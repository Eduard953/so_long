/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:18:22 by ebeiline          #+#    #+#             */
/*   Updated: 2021/11/19 15:29:04 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delete_last(t_list **head)
{
	t_list	*prev;
	t_list	*cur;

	if (head == NULL || *head == NULL)
		return ;
	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	prev = *head;
	cur = prev->next;
	while (cur->next)
	{
		prev = prev->next;
		cur = cur->next;
	}
	prev->next = NULL;
}
