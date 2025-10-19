/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:25:44 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/19 10:25:17 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	end;

	end = start + len;
	i = 0;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[start] && start < end)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
