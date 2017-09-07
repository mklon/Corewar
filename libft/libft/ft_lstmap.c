/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:52:58 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/09 22:50:40 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p;
	t_list	*n;

	if (!lst || !f)
		return (NULL);
	p = f(lst);
	n = p;
	while ((lst = lst->next))
	{
		n->next = f(lst);
		n = n->next;
	}
	return (p);
}
