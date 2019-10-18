/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:59:23 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 13:59:24 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_sum_of_differences(t_farm *farm, t_list *step)
{
	int		sum;
	t_list	*tmp;
	t_list	*tmp_step;
	t_room	*current;
	t_room	*compared;

	sum = 0;
	tmp = farm->paths;
	current = get_room(step);
	while (tmp)
	{
		tmp_step = get_step(tmp);
		if (tmp_step == step)
			break ;
		compared = get_room(tmp_step);
		sum += current->distance - compared->distance;
		tmp = tmp->next;
	}
	return (sum);
}

void	reset_rooms(t_farm *farm, t_list *steps)
{
	t_room	*room;

	room = farm->list;
	while (room)
	{
		room->parent = NULL;
		room = room->next;
	}
	while (steps)
	{
		room = get_room(steps);
		if (!room->is_start && !room->is_end)
			room->is_in_path = 1;
		steps = steps->next;
	}
}

int		compare_paths(t_list *first, t_list *second)
{
	t_room	*f;
	t_room	*s;

	if (!first)
		return (-1);
	if (!second)
		return (1);
	f = get_room(get_step(first));
	f->distance = ft_lstlen(get_step(first));
	s = get_room(get_step(second));
	s->distance = ft_lstlen(get_step(second));
	return (f->distance - s->distance);
}
