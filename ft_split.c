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

static void	my_strcpy(int idx, char const *s, char *dest, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = (char)s[idx + i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		idx;
	int		len;
	char	**arr;

	i = 0;
	idx = 0;
	arr = malloc(sizeof(char *) * word_count(s, c));
	while (s[i])
	{
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len > 0)
		{
			arr[idx] = malloc(sizeof(char) * (len + 1));
			my_strcpy(i, s, arr[idx++], len);
			i += len;
		}
		if (s[i] && len == 0)
			i++;
	}
	arr[idx] = NULL;
	return (arr);
}
