/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:00:54 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:00:56 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	set_config(t_farm *farm, int args, char **argv)
{
	int i;

	i = 1;
	while (i < args)
	{
		if (ft_strequ(argv[i], "-r"))
			farm->just_steps_num = 1;
		else if (ft_strequ(argv[i], "-p"))
			farm->print_paths = 1;
		else if (ft_strequ(argv[i], "-n"))
			farm->not_print_ants = 1;
		else if (ft_strequ(argv[i], "-l"))
			farm->print_leaks = 1;
		else if (ft_strequ(argv[i], "-help"))
		{
			ft_printf("Usage:\n\t-r - show just result\n");
			ft_printf("\t-p - show steps counting\n\t-n - don't show moves\n");
			ft_printf("\t-l - show leaks\n");
			exit(0);
		}
		i++;
	}
}

int		main(int args, char **argv)
{
	t_farm	*farm;

	farm = (t_farm*)malloc(sizeof(t_farm));
	ft_bzero(farm, sizeof(t_farm));
	set_config(farm, args, argv);
	read_file(farm, 0, 0, 0);
	if (!get_start_room(farm) || !get_end_room(farm))
		error("Commands are wrong", farm->print_leaks);
	collect_paths(farm);
	if (!farm->paths)
		error("There are no connection between start and finish",
			farm->print_leaks);
	if (!farm->just_steps_num && !farm->not_print_ants)
		print_task(farm);
	if (!farm->just_steps_num && farm->print_paths)
		print_paths(farm);
	run_ants(farm);
	if (farm->print_leaks)
		system("leaks lem-in");
	return (0);
}
