/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:53:37 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/16 11:09:36 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *pt, int cha, size_t n)
{
	unsigned char	c;
	unsigned char	*tstr;
	size_t			i;

	tstr = (unsigned char *)pt;
	c = cha;
	i = 0;
	while (i < n)
		tstr[i++] = c;
	return (pt);
}
