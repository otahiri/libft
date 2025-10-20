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

static int	is_tirmmable(const char *str, const char c)
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		len;
	int		i;
	int		max_copy_len;

	max_copy_len = ft_strlen(s1);
	len = 0;
	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	while (max_copy_len > 0 && is_tirmmable(set, s1[max_copy_len - 1]))
		max_copy_len--;
	while (is_tirmmable(set, s1[i]))
		i++;
	while (i < max_copy_len)
		res[len++] = s1[i++];
	res[len] = '\0';
	return (res);
}
