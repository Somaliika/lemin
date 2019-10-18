/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:34:47 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:34:49 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*temp;

	temp = *alst;
	if (!temp)
	{
		*alst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
