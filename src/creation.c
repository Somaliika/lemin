/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:00:44 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:00:46 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list	*create_path(t_list *steps)
{
	t_list	*path;

	path = ft_lstnew(steps, sizeof(t_list));
	return (path);
}

t_list	*create_tube(t_room *room)
{
	return (ft_lstnew(&room, sizeof(t_room*)));
}

t_list	*create_start_end_path(t_farm *farm)
{
	t_room	*start;
	t_room	*room;
	t_list	*tube;
	t_list	*path;

	start = get_start_room(farm);
	tube = start->tubes;
	while (tube)
	{
		room = get_room(tube);
		if (room->is_end)
		{
			tube = create_tube(room);
			path = create_path(tube);
			FREE(tube);
			return (path);
		}
		tube = tube->next;
	}
	return (NULL);
}
