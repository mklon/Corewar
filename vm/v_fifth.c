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

void	holdup_decrease(t_general *gen)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (gen->holdup[i] == 1)
		{
			if (gen->colors[i] == 14)
				gen->colors[i] = 1;
			else if (gen->colors[i] == 15)
				gen->colors[i] = 2;
			else if (gen->colors[i] == 16)
				gen->colors[i] = 3;
			else if (gen->colors[i] == 17)
				gen->colors[i] = 4;
		}
		if (gen->holdup[i] > 0)
			gen->holdup[i]--;
	}
}

void	scroll_array(t_general *gen, int *array, int *m)
{
	int		i;

	i = -1;
	while (++i < (int)gen->champ_num)
		m[i] = array[i];
	gen->mark = 0;
}

void	pc_color_down(t_general *gen, size_t i)
{
	if (gen->colors[i] == 5 && gen->holdup[i] > 0)
		gen->colors[i] = 14;
	else if (gen->colors[i] == 6 && gen->holdup[i] > 0)
		gen->colors[i] = 15;
	else if (gen->colors[i] == 7 && gen->holdup[i] > 0)
		gen->colors[i] = 16;
	else if (gen->colors[i] == 8 && gen->holdup[i] > 0)
		gen->colors[i] = 17;
	else if (gen->colors[i] == 5)
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
	while (++i < (int)gen->champ_num)
		if (gen->players[i]->declared_live != 0)
			return (0);
	return (1);
}
