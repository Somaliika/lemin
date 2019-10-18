/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:24:27 by ilian             #+#    #+#             */
/*   Updated: 2019/07/17 14:24:28 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcpy(t_list **dest, t_list *lst)
{
	if (!dest)
		return ;
	while (lst)
	{
		ft_lstpush(dest, ft_lstnew(lst->content, lst->content_size));
		lst = lst->next;
	}
}
