/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:17:27 by ebeiline          #+#    #+#             */
/*   Updated: 2021/11/16 20:44:15 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **lst, void *content)
{
	t_list	*new_lst;

	new_lst = ft_lstnew(content);
	if (*lst == NULL)
	{
		*lst = new_lst;
	}
	else
	{
		ft_lstlast(*lst)->next = new_lst;
	}
}
