/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:42:24 by msymkany          #+#    #+#             */
/*   Updated: 2016/12/10 14:52:32 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_list(t_list *list)
{
	while (list)
	{
		ft_putstr((char *)list->content);
		ft_putchar('\n');
		list = list->next;
	}
}
