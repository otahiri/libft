/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:36:53 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/16 12:28:39 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	my_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res_str;
	size_t	len;
	size_t	temp_len;

	len = 0;
	temp_len = 0;
	res_str = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
	while (s1[temp_len])
		res_str[len++] = s1[temp_len++];
	temp_len = 0;
	while (s2[temp_len])
		res_str[len++] = s2[temp_len];
	res_str[len] = '\0';
	return (res_str);
}
