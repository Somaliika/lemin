/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:00:22 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:00:24 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list	*form_path(t_farm *farm)
{
	t_list	*path;
	t_list	*list;
	t_list	*step;
	t_room	*room;

	room = get_end_room(farm);
	list = NULL;
	while (room && !room->is_start)
	{
		step = create_tube(room);
		ft_lstadd(&list, step);
		room = room->parent;
	}
	path = create_path(list);
	free(list);
	return (path);
}

void	add_next_steps(t_farm *farm, t_list *step)
{
	t_list	*opt;
	t_list	*tube;
	t_room	*room;

	room = get_room(step);
	tube = room->tubes;
	opt = NULL;
	while (tube)
	{
		room = get_room(tube);
		if (!room->parent && !room->is_start && !room->is_in_path &&
		!(get_room(step)->is_start && room->is_end))
		{
			room->parent = get_room(step);
			opt = create_tube(room);
			ft_lstpush(&farm->que, opt);
		}
		tube = tube->next;
	}
}

t_list	*find_path(t_farm *farm)
{
	t_list	*step;
	t_room	*room;

	room = get_start_room(farm);
	step = create_tube(room);
	ft_lstadd(&farm->que, step);
	while (farm->que)
	{
		step = ft_lstpop(&farm->que);
		room = get_room(step);
		if (room->is_end)
		{
			ft_lstdel(&farm->que, ft_lstfree);
			ft_lstdel(&step, ft_lstfree);
			return (form_path(farm));
		}
		add_next_steps(farm, step);
		ft_lstdel(&step, ft_lstfree);
	}
	return (NULL);
}

void	collect_paths(t_farm *farm)
{
	t_list	*path;

	path = create_start_end_path(farm);
	if (path)
		ft_lstadd(&farm->paths, path);
	while ((path = find_path(farm)))
	{
		ft_lstadd(&farm->paths, path);
		reset_rooms(farm, get_step(path));
	}
	ft_lstsort(&farm->paths, compare_paths);
}
