/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:48:02 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/18 10:45:20 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	convert_num(size_t idx, long num, char res[])
{
	size_t	i;
	char	tmp;
	size_t	output;

	i = 0;
	if (res[0] == '-')
		i++;
	while (num > 0)
	{
		res[idx++] = (num % 10) + '0';
		num /= 10;
	}
	output = idx;
	if (output == 1)
		return (output);
	idx--;
	while (idx >= i)
	{
		tmp = res[i];
		res[i] = res[idx];
		res[idx] = tmp;
		i++;
		idx--;
	}
	return (output);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	char	num[32];
	long	tmp_num;
	size_t	idx;

	idx = 0;
	i = 0;
	tmp_num = n;
	if (tmp_num < 0)
	{
		tmp_num *= -1;
		num[i++] = '-';
	}
	if (tmp_num == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	i = convert_num(i, tmp_num, num);
	write(fd, &num, i);
}
