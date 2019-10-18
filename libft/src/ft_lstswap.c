/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:34:14 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:34:58 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list **previous, t_list *first, t_list *second)
{
	if (previous && first && second)
	{
		if (!*previous || (*previous && *previous == first))
			*previous = second;
		else
			(*previous)->next = second;
		first->next = second->next;
		second->next = first;
	}
}
