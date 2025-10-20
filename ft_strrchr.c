/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:46:57 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/16 11:11:01 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	i = size;
	while (i >= 0)
	{
		if (s[size] == c)
			return ((char *)s + size);
		size--;
		i--;
	}
	return (NULL);
}
