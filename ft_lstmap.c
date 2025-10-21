/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:33:14 by otahiri-          #+#    #+#             */
/*   Updated: 2025/10/21 14:38:26 by otahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_list	*my_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

static void	my_lstclear(t_list **lst, void (*del)(void*))
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*current;

	if (!f || !del)
		return (NULL);
	if (lst)
	{
		res = my_lstnew(f(lst->content));
		if (!res)
			return (NULL);
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
