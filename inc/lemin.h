/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:20:09 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:20:11 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"
# define RED "\033[31;1m"
# define RESET "\x1b[0m"

typedef struct		s_room
{
	char			*name;
	int				is_start;
	int				is_end;
	int				distance;
	int				x;
	int				y;
	t_list			*tubes;
	int				is_in_path;
	struct s_room	*parent;
	struct s_room	*next;
}					t_room;

typedef struct		s_farm
{
	int				ant_num;
	int				room_num;
	t_room			*list;
	t_list			*paths;
	t_list			*que;
	t_list			*text;
	int				just_steps_num;
	int				print_paths;
	int				not_print_ants;
	int				print_leaks;
}					t_farm;

typedef struct		s_ant
{
	int				ant_num;
	t_list			*path;
}					t_ant;

void				read_file(t_farm *farm, int fd, int start, int end);
t_room				*get_room_by_name(t_farm *farm, char *name, int len);
void				print_rooms_list(t_farm *farm);
t_room				*get_end_room(t_farm *farm);
t_room				*get_start_room(t_farm *farm);
void				collect_paths(t_farm *farm);
void				print_paths(t_farm *farm);
void				print_task(t_farm *farm);
void				run_ants(t_farm *farm);
int					compare_paths(t_list *first, t_list *second);
t_list				*find_path(t_farm *farm);
int					is_room(char *line);
int					is_comment(char *line);
int					is_link(char *line);
int					is_num(char c);
int					is_valid_ant_num(char *line);
int					are_num(char *line);
int					is_unique_room_data(t_farm *farm, t_room *room);
int					are_connected(t_room *first, t_room *second);
void				reset_rooms(t_farm *farm, t_list *steps);
t_list				*create_start_end_path(t_farm *farm);
int					get_new_ant_id(t_farm *farm);
int					get_sum_of_differences(t_farm *farm, t_list *step);
void				error(char *text, int leaks);
t_list				*get_step(t_list *path);
t_room				*get_room(t_list *step);
t_list				*create_tube(t_room *room);
t_list				*create_path(t_list *steps);

#endif
