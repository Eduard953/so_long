/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:11:07 by ebeiline          #+#    #+#             */
/*   Updated: 2021/06/15 16:12:24 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	token_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static void	get_next_token(char **token, size_t *token_len, char c)
{
	size_t	i;

	*token += *token_len;
	*token_len = 0;
	i = 0;
	while ((*token[i]) == c)
		(*token)++;
	while ((*token)[i])
	{
		if ((*token)[i] == c)
			return ;
		i++;
		(*token_len)++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	token_len;
	size_t	i;
	char	*token;
	char	**res;

	res = (char **)malloc(sizeof(char *) * (token_count(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	token = (char *)s;
	token_len = 0;
	while (i < token_count(s, c))
	{
		get_next_token(&token, &token_len, c);
		res[i] = (char *)malloc(sizeof(char) * (token_len + 1));
		if (!res[i])
			return (NULL);
		ft_strlcpy(res[i], token, token_len + 1);
		i++;
	}
	res[i] = NULL;
	return (res);
}
