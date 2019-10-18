/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:01:17 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:01:18 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_valid_ant_num(char *line)
{
	long int	num;

	if (!(ft_isdigit(*line) || *line == '+'))
		return (0);
	if (!are_num(line + 1))
		return (0);
	num = ft_atoli(line);
	if (num <= 0 || num != (int)num)
		return (0);
	return (1);
}

int		is_coordinate(char *line)
{
	long int	num;

	if (!(ft_isdigit(*line) || *line == '+' || *line == '-') ||
		!are_num(line + 1))
	{
		ft_strdel(&line);
		return (0);
	}
	num = ft_atoli(line);
	ft_strdel(&line);
	if (num != (int)num)
		return (0);
	return (1);
}

int		is_room(char *line)
{
	char	*name;
	int		x;
	int		y;

	if (ft_chrcount(line, ' ') != 2 ||
		ft_strrchri(line, ' ') == 0 ||
		ft_strrchri(line, ' ') == (int)ft_strlen(line) - 1)
		return (0);
	x = ft_strchri(line, ' ');
	y = ft_strrchri(line, ' ');
	if (!is_num(line[x + 1]) || !is_num(line[y + 1]))
		return (0);
	name = ft_strsub(line, 0, x);
	if (*name == 'L' || *name == '#')
	{
		ft_strdel(&name);
		return (0);
	}
	ft_strdel(&name);
	if (!is_coordinate(ft_strsub(line, x + 1, y - x - 1)) ||
		!is_coordinate(ft_strsub(line, y + 1, ft_strlen(line) - y)))
		return (0);
	return (1);
}

int		is_link(char *line)
{
	if (*line == '#' || ft_chrcount(line, '-') != 1 ||
		*line == '-' || line[ft_strlen(line) - 1] == '-')
		return (0);
	return (1);
}

int		is_comment(char *line)
{
	return (*line == '#' ? 1 : 0);
}
