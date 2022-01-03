/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:41:27 by ebeiline          #+#    #+#             */
/*   Updated: 2021/09/08 16:00:09 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digits(unsigned int n)
{
	size_t	i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	size_t	digits;
	char	*a;

	digits = get_digits(n);
	a = (char *)malloc(sizeof(char) * (digits + 1));
	a[digits] = '\0';
	while (digits--)
	{
		if (digits == 0)
			a[digits] = n + '0';
		else
		{
			a[digits] = (n % 10) + '0';
			n = n / 10;
		}
	}
	return (a);
}
