/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:35:45 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:35:47 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*rev(t_list *old_list)
{
	t_list	*new_list;

	if (!old_list || !old_list->next)
		return (old_list);
	new_list = rev(old_list->next);
	old_list->next = NULL;
	ft_lstpush(&new_list, old_list);
	return (new_list);
}

void	ft_lstrev(t_list **alst)
{
	t_list	*start;

	if (!*alst || !(*alst)->next)
		return ;
	start = rev(*alst);
	*alst = start;
}
