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

static t_list	*my_lsnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->next = NULL;
	list->content = content;
	return (list);
}

static void	del_list(t_list **list, void (*del)(void *))
{
	t_list	*next;
	t_list	*current;

	current = (*list);
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
	t_list	*head;
	t_list	*new;

	if (lst)
	{
		new = my_lsnew(f(lst->content));
		if (!new)
			return (NULL);
		head = new;
		lst = lst->next;
		new = new->next;
		while (lst)
		{
			new = my_lsnew(f(lst->content));
			if (!new)
			{
				del_list(&head, del);
				return (NULL);
			}
			new = new->next;
			lst = lst->next;
		}
	}
	return (head);
}
