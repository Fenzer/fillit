/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepinson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:16:55 by fepinson          #+#    #+#             */
/*   Updated: 2019/01/04 22:46:34 by fepinson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*current;
	t_list	*first;

	if (!lst || !f)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new = f(lst);
		if (!first)
		{
			first = new;
			current = first;
		}
		else
		{
			current->next = new;
			current = current->next;
		}
		lst = lst->next;
	}
	return (first);
}
