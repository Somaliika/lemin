/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:35:03 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:35:36 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **alst, int (*compare)(t_list*, t_list*))
{
	t_list	*tmp;
	t_list	*prev;
	int		i;
	int		j;
	int		size;

	if (!(alst && *alst && compare && (size = ft_lstlen(*alst))))
		return ;
	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		prev = NULL;
		tmp = *alst;
		while (++j < size - i - 1)
		{
			if (compare(tmp, tmp->next) > 0)
			{
				ft_lstswap((prev) ? &prev : alst, tmp, tmp->next);
				tmp = (prev) ? prev->next : *alst;
			}
			prev = tmp;
			tmp = tmp->next;
		}
	}
}
