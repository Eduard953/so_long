/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:11:41 by ebeiline          #+#    #+#             */
/*   Updated: 2021/11/16 20:50:30 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *elem)
{
	int	len;

	while (elem)
	{
		len = 0;
		while (((char *)elem->content)[len])
			len++;
		write(1, elem->content, len);
		write(1, "\n", 1);
		elem = elem->next;
	}
}
