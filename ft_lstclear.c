/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:16:21 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/19 10:23:52 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (!lst)
		return ;
	current = (*lst);
	while (current)
	{
		if (del)
			del(current->content);
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}
