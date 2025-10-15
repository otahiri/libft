/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:46:06 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/15 10:26:40 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
		return (dest);
	}
	else if (src < dest)
	{
		i = n - 1;
		while (i >= 0)
		{
			dest[i] = src[i];
			i--;
		}
		return (dest);
	}
	else
		return (dest);
}
