/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:50:49 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/09 22:47:34 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*pt;
	t_list	*n;

	if (!del)
		return ;
	pt = *alst;
	while (pt)
	{
		n = pt->next;
		ft_lstdelone(&pt, del);
		pt = n;
	}
	*alst = NULL;
}
