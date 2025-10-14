/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:53:37 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/14 15:22:14 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *pt, int cha, size_t n)
{
	unsigned char	c;
	unsigned char	*str;
	size_t			i;

	c = cha;
	str = (unsigned char)pt;
	i = 0;
	while (i < n)
		str[i++] = c;
	return (pt);
}
