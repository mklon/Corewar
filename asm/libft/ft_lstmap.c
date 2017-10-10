/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:50:16 by amovchan          #+#    #+#             */
/*   Updated: 2016/12/05 13:22:34 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp_new_map;
	t_list	*new_map;

	if (!lst)
		return (NULL);
	new_map = NULL;
	tmp_new_map = NULL;
	if ((new_map = (t_list *)malloc(ft_lst_len(lst) * sizeof(t_list))))
	{
		new_map = f(ft_lstnew(lst->content, lst->content_size));
		tmp_new_map = new_map;
		lst = lst->next;
		while (lst)
		{
			tmp_new_map->next = f(ft_lstnew(lst->content, lst->content_size));
			tmp_new_map = tmp_new_map->next;
			lst = lst->next;
		}
	}
	return (new_map);
}
