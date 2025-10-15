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
	size_t	dst_end;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_end = 0;
	src_len = 0;
	if (size == 0)
		return (0);
	while (dst[dst_end])
		dst_end++;
	while (src[src_len])
		src_len++;
	while (dst_end + i < size - 1 && src[i])
	{
		dst[dst_end + i] = src[i];
		i++;
	}
	if (dst_end + i < size)
		dst[dst_end + i] = '\0';
	return (dst_end + src_len);
}
