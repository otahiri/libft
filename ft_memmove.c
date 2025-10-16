/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:46:06 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/16 11:05:25 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
		return (dest);
	}
	else if (src < dest)
	{
		i = n - 1;
		while (i >= 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
		return (dest);
	}
	return (dest);
}
