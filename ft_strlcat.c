/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:43:22 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/15 11:08:23 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	src_len;
	size_t	i;

	i = 0;
	len = 0;
	src_len = 0;
	if (size == 0)
		return (0);
	while (dst[len])
		len++;
	while (src[src_len])
		src_len++;
	while (len + i < size - 1 && src[i])
	{
		dst[len + i] = src[i];
		i++;
	}
	if (len + i < size)
		dst[len + i] = '\0';
	return (len + src_len);
}
