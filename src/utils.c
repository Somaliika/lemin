/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:00:37 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:00:39 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_unique_room_data(t_farm *farm, t_room *room)
{
	t_room	*tmp;

	tmp = farm->list;
	while (tmp)
	{
		if (ft_strequ(tmp->name, room->name))
			return (0);
		if (tmp->x == room->x && tmp->y == room->y)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		is_num(char c)
{
	if (ft_isdigit(c) || c == '-' || c == '+')
		return (1);
	return (0);
}

int		are_num(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int		are_connected(t_room *first, t_room *second)
{
	t_list	*tube;
	t_room	*linked;

	tube = first->tubes;
	while (tube)
	{
		linked = get_room(tube);
		if (linked == second)
			return (1);
		tube = tube->next;
	}
	return (0);
}

void	error(char *text, int leaks)
{
	if (leaks)
		system("leaks lem-in");
	ft_printf(RED);
	ft_printf(text);
	ft_printf(RESET "\n");
	exit(1);
}
