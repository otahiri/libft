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
	size_t	i;
	size_t	lil_len;

	i = 0;
	if (big == little)
		return ((char *)big);
	while (big[i])
	{
		lil_len = 0;
		while (big[i + lil_len] && little[lil_len] == big[i + lil_len]
			&& i + lil_len < len)
			lil_len++;
		if (!little[lil_len])
			return ((char *)big + i);
		else
			i++;
	}
	return (NULL);
}
