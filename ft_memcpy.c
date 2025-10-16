/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:25:30 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/16 11:05:12 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tdest;
	char	*tsrc;

	tdest = (char *)dest;
	tsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		tdest[i] = tsrc[i];
		i++;
	}
	return (dest);
}
