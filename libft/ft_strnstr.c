/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:08:51 by ebeiline          #+#    #+#             */
/*   Updated: 2021/06/08 12:31:21 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;
	size_t	size;

	size = len;
	j = 0;
	if (!big || !little)
		return (NULL);
	if (!little[0])
		return ((char *)big);
	while (big[j] && len)
	{
		i = 0;
		while (little[i] && big[i + j] && (little[i] == big[i + j])
			&& (i + j < size))
			i++;
		if (!little[i])
			return ((char *)big + j);
		len--;
		j++;
	}
	return (NULL);
}
