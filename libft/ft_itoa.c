/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:18:48 by ebeiline          #+#    #+#             */
/*   Updated: 2021/06/09 13:37:36 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_digits(long long n)
{
	int		i;

	i = 0;
	if (n < 0)
		n = n * (-1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_power(int i)
{
	int		div;

	div = 1;
	while (i > 0)
	{
		div = div * 10;
		i--;
	}
	return (div);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*a;
	int			div;
	long long	numb;

	numb = n;
	i = ft_num_digits(numb);
	a = (char *)malloc(sizeof(char) * (i + 2));
	if (!a)
		return (NULL);
	div = ft_power(i - 1);
	i = 0;
	if (numb < 0)
	{
		a[i++] = '-';
		numb = numb * (-1);
	}
	while (div > 0)
	{
		a[i] = ((numb / div) % 10 + '0');
		i++;
		div /= 10;
	}
	a[i] = '\0';
	return (a);
}
