/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:34:38 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:34:39 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **alst)
{
	t_list	*temp;

	temp = *alst;
	if (!temp)
		return (NULL);
	*alst = temp->next;
	temp->next = NULL;
	return (temp);
}
