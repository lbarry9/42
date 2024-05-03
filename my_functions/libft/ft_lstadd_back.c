/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:31:51 by lbarry            #+#    #+#             */
/*   Updated: 2023/06/12 19:22:14 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	end = ft_lstlast(*lst);
	end->next = new;
}
