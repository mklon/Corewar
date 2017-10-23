/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:43:39 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 17:43:43 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	dell_stack(t_stak **stak)
{
	t_stak	*liaks;

	while (*stak)
	{
		liaks = (*stak);
		(*stak) = (*stak)->next;
		liaks->next = NULL;
		ft_strdel(&(liaks->funk_name));
		free(liaks);
	}
	*stak = NULL;
}

static void	dell_program(t_prog **prog)
{
	t_prog	*liaks;

	while (*prog)
	{
		liaks = *prog;
		*prog = (*prog)->next;
		liaks->next = NULL;
		if (liaks->label1)
			ft_strdel(&(liaks->label1));
		if (liaks->label2)
			ft_strdel(&(liaks->label2));
		if (liaks->label3)
			ft_strdel(&(liaks->label3));
		free(liaks);
	}
	*prog = NULL;
}

void		ft_dell_all(t_all **all)
{
	free((*all)->header);
	(*all)->header = NULL;
	dell_stack(&(*all)->stak);
	dell_program(&(*all)->prog);
	free(*all);
	*all = NULL;
}
