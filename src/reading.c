/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:00:31 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:00:32 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	get_ants(t_farm *farm, int fd)
{
	char	*line;
	int		read_res;

	while ((read_res = get_next_line(fd, &line)) == 1)
	{
		ft_lstpush(&farm->text,
			ft_lstnew(line, sizeof(char) * ft_strlen(line)));
		if (!line || !ft_strlen(line) ||
			(!is_valid_ant_num(line) && !is_comment(line)))
			error("Wrong number of ants", farm->print_leaks);
		else if (is_valid_ant_num(line))
		{
			farm->ant_num = ft_atoi(line);
			ft_strdel(&line);
			return ;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

void	make_link(t_farm *farm, char *line, int *link_mode)
{
	t_room	*first;
	t_room	*second;
	t_room	*test;
	t_list	*tube;

	*link_mode = 1;
	first = get_room_by_name(farm, line, ft_strchri(line, '-'));
	second = get_room_by_name(farm, ft_strchr(line, '-') + 1, 0);
	if (!first || !second || first == second || are_connected(first, second))
		error("Wrong link", farm->print_leaks);
	tube = create_tube(second);
	test = get_room(tube);
	ft_lstadd(&(first->tubes), tube);
	tube = create_tube(first);
	ft_lstadd(&(second->tubes), tube);
}

void	read_add_room_to_list(t_farm *farm, char *data, int *start, int *end)
{
	t_room	*room;

	if (*start > 1 || *end > 1 || (*start == 1 && get_start_room(farm)) ||
	(*end == 1 && get_end_room(farm)) || (*start == 1 && *end == 1))
		error("Commands are wrong", farm->print_leaks);
	room = (t_room*)ft_memalloc(sizeof(t_room));
	*room = (t_room){ft_strsub(data, 0, ft_strchri(data, ' ')),
	*start, *end, 0, ft_atoi(ft_strchr(data, ' ')),
	ft_atoi(ft_strrchr(data, ' ')), NULL, 0, NULL, farm->list};
	if (!is_unique_room_data(farm, room))
		error("Room is not unique", farm->print_leaks);
	farm->list = room;
	*start = 0;
	*end = 0;
}

void	read_file(t_farm *farm, int fd, int start, int end)
{
	int		read_res;
	char	*line;
	int		link_mode;

	get_ants(farm, fd);
	link_mode = 0;
	while ((read_res = get_next_line(fd, &line)) == 1 &&
		line && ft_strlen(line) > 0)
	{
		ft_lstpush(&farm->text,
			ft_lstnew(line, sizeof(char) * ft_strlen(line)));
		if ((ft_strequ(line, "##start") && start++) ||
			(ft_strequ(line, "##end") && end++))
			;
		else if (!link_mode && is_room(line))
			read_add_room_to_list(farm, line, &start, &end);
		else if (is_link(line))
			make_link(farm, line, &link_mode);
		else if (!is_comment(line))
			error(link_mode ? "Wrong link" : "Wrong room", farm->print_leaks);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}
