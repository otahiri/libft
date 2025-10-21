/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:02:12 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/21 16:14:11 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_trim(char const *set, const char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	my_strcpy(const char *src, char *dst, int start, int end)
{
	int	len;

	len = 0;
	while (len < end)
	{
		dst[len] = src[start + len];
		len++;
	}
	dst[len] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		max_copy;
	char	*res;
	int		len;

	len = 0;
	max_copy = ft_strlen(s1);
	i = ft_strlen(s1) - 1;
	while (s1[i] && is_trim(set, s1[i]))
	{
		i--;
		max_copy--;
	}
	i = 0;
	while (s1[i] && is_trim(set, s1[i]))
	{
		i++;
		max_copy--;
	}
	res = malloc(sizeof(char) * (max_copy + 1));
	my_strcpy(s1, res, i, max_copy);
	return (res);
}
