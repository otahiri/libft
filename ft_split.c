/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:15:53 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/17 11:49:52 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	word_count(char const *s, char c)
{
	int	idx;
	int	count;
	int	len;

	count = 0;
	idx = 0;
	while (s[idx])
	{
		len = 0;
		while (s[idx + len] && s[idx + len] != c)
			len++;
		if (len)
		{
			count++;
			idx += len;
		}
		idx ++;
	}
	return (count);
}

static void	word_copy(char *res, const char *src, int idx, int len)
{
	int	i;

	i = 0;
	while (i < len)
		res[i++] = src[idx++];
	res[i] = '\0';
}

static void	spliter(char const *s, char c, char **res)
{
	int	idx;
	int	i;
	int	len;

	len = 0;
	i = 0;
	idx = 0;
	while (s[i])
	{
		len = 0;
		while (s[i + len] && s[i + len] == c)
			len++;
		if (len > 0)
		{
			res[idx++] = malloc(sizeof(char) * (len + 1));
			word_copy(res[idx], s, idx, len);
			i += len;
		}
		if (res[i])
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	res = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!res)
		return (NULL);
	spliter(s, c, res);
	return (res);
}
