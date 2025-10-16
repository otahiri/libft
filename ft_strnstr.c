/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:50:38 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/16 09:24:27 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lilen;
	size_t	i;
	char	*ptr;

	ptr = (char *)big;
	i = 0;
	while (i < len && big[i])
	{
		lilen = 0;
		while (little[lilen] == big[i + lilen])
			lilen++;
		if (!little[lilen])
			return (ptr + i);
		i++;
	}
	return (NULL);
}
