/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:02:12 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/16 14:25:04 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_tirmmable(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	my_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		s_len;
	int		len;

	s_len = 0;
	len = 0;
	res = malloc(sizeof(char) * (my_strlen(s1) + 1));
	while (s1[s_len])
	{
		if (is_tirmmable(set, s1[s_len]))
		{
			s_len++;
			continue ;
		}
		res[len++] = s1[s_len++];
	}
	res[len] = '\0';
	return (res);
}
