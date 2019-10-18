/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:00:12 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:00:14 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list	*get_step(t_list *path)
{
	return ((t_list*)(path->content));
}

t_room	*get_room(t_list *step)
{
	return (*((t_room**)(step->content)));
}

t_room	*get_room_by_name(t_farm *farm, char *name, int len)
{
	t_room	*tmp;

	tmp = farm->list;
	while (tmp)
	{
		if (len && (int)ft_strlen(tmp->name) == len &&
			ft_strnequ(tmp->name, name, len))
			return (tmp);
		else if (!len && ft_strequ(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room	*get_end_room(t_farm *farm)
{
	t_room	*tmp;

	tmp = farm->list;
	while (tmp)
	{
		if (tmp->is_end)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room	*get_start_room(t_farm *farm)
{
	t_room	*tmp;

	tmp = farm->list;
	while (tmp)
	{
		if (tmp->is_start)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
