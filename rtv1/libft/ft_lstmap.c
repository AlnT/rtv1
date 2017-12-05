/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataftai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:57:51 by ataftai           #+#    #+#             */
/*   Updated: 2016/12/09 14:27:22 by ataftai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *begin;
	t_list *prev;

	if (!lst)
		return (0);
	newlist = (t_list *)malloc(sizeof(t_list));
	newlist = f(lst);
	begin = newlist;
	prev = newlist;
	newlist = newlist->next;
	lst = lst->next;
	while (lst)
	{
		newlist = (t_list *)malloc(sizeof(t_list));
		newlist = f(lst);
		prev->next = newlist;
		prev = newlist;
		newlist = newlist->next;
		lst = lst->next;
	}
	return (begin);
}
