/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_third.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:41:52 by oposhiva          #+#    #+#             */
/*   Updated: 2017/09/28 17:41:52 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	limit_handel(t_general *gen, char c)
{
	if (c == 'q')
		gen->limit -= 10;
	else if (c == 'w')
		gen->limit -= 1;
	else if (c == 'e')
		gen->limit += 1;
	else if (c == 'r')
		gen->limit += 10;
	if (gen->limit > 1000)
		gen->limit = 1000;
	else if (gen->limit < 1)
		gen->limit = 1;
}

void	visual_apd(t_general *gen)
{
	pressing(gen);
	initial_info(gen);
}

void	pressing(t_general *gen)
{
	int		i = -1;
	char	c;

	wmove(gen->text, 0, 0);
	//if (kbhit())
	//{
		c = wgetch(gen->text);
		if (c == 'p')
			gen->pause *= -1;
		limit_handel(gen, c);
	//}
	usleep(1000);
	wrefresh(gen->board);
}

