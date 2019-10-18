/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:25:11 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:25:26 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(void *lst_ptr, size_t s)
{
	t_list	*lst;

	lst = *((t_list**)lst_ptr);
	(void)s;
	ft_memdel(&lst->content);
	ft_memdel(lst_ptr);
}
