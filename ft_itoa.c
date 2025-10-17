/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:51:47 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/17 13:03:26 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	rev_str(char *s, int last_idx)
{
	int		i;
	char	tmp;

	i = 0;
	if (s[i] == '-')
		i++;
	while (i < last_idx)
	{
		tmp = s[last_idx];
		s[last_idx] = s[i];
		s[i] = tmp;
		i++;
		last_idx--;
	}
}

static int	size_count(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static int	my_put_nbr(char *res, int idx, long num)
{
	if (num == 0)
		res[idx++] = '0';
	while (num > 0)
	{
		res[idx++] = (num % 10) + '0';
		num /= 10;
	}
	res[idx] = '\0';
	return (idx);
}

char	*ft_itoa(int n)
{
	int		temp_num;
	int		size;
	char	*res;
	int		sign;
	long	num;

	num = n;
	temp_num = n;
	sign = 1;
	if (n < 0)
	{
		num *= -1;
		sign = -1;
	}
	size = size_count(n);
	res = malloc(sizeof(char) * (size + 1));
	size = 0;
	if (sign < 0)
		res[size++] = '-';
	size = my_put_nbr(res, size, num);
	rev_str(res, size - 1);
	return (res);
}
