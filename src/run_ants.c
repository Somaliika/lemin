/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:01:10 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:01:11 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ant_finishes_way(t_farm *farm, t_list **elem,
		t_list **prev_elem, int *finished)
{
	*finished = *finished + 1;
	if (*prev_elem)
	{
		(*prev_elem)->next = (*elem)->next;
		ft_lstdelone(elem, ft_lstfree);
		(*elem) = (*prev_elem);
		return (0);
	}
	else
	{
		farm->que = (*elem)->next;
		ft_lstdelone(elem, ft_lstfree);
		(*elem) = farm->que;
		return (1);
	}
}

int		move_ants(t_farm *farm, t_list *prev_elem, int finished)
{
	t_list	*elem;
	t_ant	*ant;
	t_room	*room;

	elem = farm->que;
	while (elem)
	{
		ant = (t_ant*)elem->content;
		room = get_room(ant->path);
		if (!farm->just_steps_num && !farm->not_print_ants)
			ft_printf("L%i-%s ", ant->ant_num, room->name);
		if (room->is_end &&
			ant_finishes_way(farm, &elem, &prev_elem, &finished))
			continue ;
		else if (!room->is_end)
			ant->path = ant->path->next;
		prev_elem = elem;
		elem = elem->next;
	}
	return (finished);
}

int		add_ant(t_farm *farm, t_list *step, int ant_id)
{
	int		ants_in_que;
	int		sum;
	t_ant	*ant;

	if (ant_id == 0)
		return (0);
	ants_in_que = farm->ant_num - ant_id + 1;
	sum = get_sum_of_differences(farm, step);
	if (ants_in_que <= sum)
		return (0);
	ant = (t_ant*)ft_memalloc(sizeof(t_ant));
	*ant = (t_ant){ant_id, step};
	ft_lstpush(&(farm->que), ft_lstnew(ant, sizeof(t_ant)));
	FREE(ant);
	return (1);
}

int		add_new_ants(t_farm *farm, int last_ant_id)
{
	int		result;
	int		sum;
	t_list	*path;
	int		ants_gone;

	result = 1;
	path = farm->paths;
	sum = 0;
	ants_gone = 0;
	while (result && path)
	{
		last_ant_id++;
		result = add_ant(farm, get_step(path), last_ant_id);
		ants_gone += result;
		path = path->next;
	}
	return (ants_gone);
}

void	run_ants(t_farm *farm)
{
	int	ants_in_que;
	int	ants_in_finish;
	int	moves;

	ants_in_que = farm->ant_num;
	ants_in_finish = 0;
	moves = 0;
	while (ants_in_finish < farm->ant_num)
	{
		if (ants_in_que > 0)
			ants_in_que -= add_new_ants(farm, farm->ant_num - ants_in_que);
		ants_in_finish += move_ants(farm, NULL, 0);
		moves++;
		if (!farm->just_steps_num && !farm->not_print_ants)
			ft_printf("\n");
	}
	if (farm->just_steps_num)
		ft_printf("%i\n", moves);
	else if (farm->print_paths)
		ft_printf("\n---------------------------\nResult: %i steps\n", moves);
}
