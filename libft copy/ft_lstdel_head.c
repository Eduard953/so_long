/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:08:31 by ebeiline          #+#    #+#             */
/*   Updated: 2021/11/13 15:21:02 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delete_head(t_list **lst)
{
	t_list	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = (*lst);
	*lst = (*lst)->next;
	free(tmp);
}
