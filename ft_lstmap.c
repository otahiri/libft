/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:33:14 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/18 12:58:44 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static t_list	*my_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list *));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

static void	my_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;
	t_list	*current;

	current = (*lst);
	next = current->next;
	while (current)
	{
		if (del)
			del(current->content);
		free(current);
		current = next;
		next = current->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*current;

	if (lst)
	{
		res = my_lstnew(f(lst->content));
		current = res;
		lst = lst->next;
	}
	while (lst)
	{
		if (!current)
		{
			my_lstclear(&res, del);
			return (NULL);
		}
		current->next = my_lstnew(f(lst->content));
		current = current->next;
		lst = lst->next;
	}
	return (res);
}
