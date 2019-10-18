/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:01:03 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:01:04 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_path(t_list *path)
{
	t_list	*step;
	int		length;
	t_room	*room;

	step = get_step(path);
	length = 0;
	while (step)
	{
		room = get_room(step);
		ft_printf("room %s", room->name);
		if (!room->is_end)
			ft_printf(" -> ");
		step = step->next;
		length++;
	}
	ft_printf("\nOverall: %i steps\n\n", length);
}

void	print_paths(t_farm *farm)
{
	ft_printf("---------------------------\n");
	ft_printf("%i path were found\n\n", ft_lstlen(farm->paths));
	ft_lstiter(farm->paths, print_path);
	if (!farm->not_print_ants)
		ft_printf("---------------------------\n\n");
}

void	print_rooms_list(t_farm *farm)
{
	t_room	*room;
	t_room	*next;
	t_list	*tube;

	room = farm->list;
	while (room)
	{
		tube = room->tubes;
		ft_printf("Room %s (%i) links to", room->name, room->distance);
		while (tube)
		{
			next = get_room(tube);
			ft_printf(" %s (%i)", next->name, next->distance);
			tube = tube->next;
		}
		ft_printf("\n");
		room = room->next;
	}
}

void	print_task(t_farm *farm)
{
	t_list	*tmp;

	tmp = farm->text;
	while (tmp)
	{
		ft_printf((char*)tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
