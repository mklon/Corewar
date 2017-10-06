/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_fifth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:50:24 by oposhiva          #+#    #+#             */
/*   Updated: 2017/10/06 15:50:25 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	pc_color_down(t_general *gen, size_t i)
{
	if (gen->colors[i] == 5)
			gen->colors[i] = 1;
		else if (gen->colors[i] == 6)
			gen->colors[i] = 2;
		else if (gen->colors[i] == 7)
			gen->colors[i] = 3;
		else if (gen->colors[i] == 8)
			gen->colors[i] = 4;
		else if (gen->colors[i] == 13)
			gen->colors[i] = 11;
}

void	print_symbol(t_general *gen, char c, int i)
{
	wattron(gen->board, COLOR_PAIR(i));
	wprintw(gen->board, "%c", c);
	wattroff(gen->board, COLOR_PAIR(i));
}
int		scroll_check(t_general *gen)
{
	int		i;

	i = -1;
	while (++i < gen->champ_num)
		if (gen->players[i]->declared_live != 0)
			return (0);
	if (gen->total_cycles)
		return (-1);
	return (1);
}

int		scroll_base(t_general *gen)
{
	if (scroll_check(gen) == 0)
		return (0);
	wattron(gen->board, COLOR_PAIR(11));
	wprintw(gen->board, "[--------------------------------------------------]\n");
	wattroff(gen->board, COLOR_PAIR(11));
	wprintw(gen->board, "Live breakdown for last period :\n");
	wattron(gen->board, COLOR_PAIR(11));
	wprintw(gen->board, "[--------------------------------------------------]\n");
	wattroff(gen->board, COLOR_PAIR(11));
	return (1);
}