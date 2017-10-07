/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_fourth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:41:07 by oposhiva          #+#    #+#             */
/*   Updated: 2017/10/04 17:41:08 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	scroll_down(t_general *gen, int *array)
{
	//wprintw(gen->board, "Live breakdown for last period :\n");
	print_symbol(gen, '[', 11);
	scroll_loop(gen, array);
	print_symbol(gen, ']', 11);
	wprintw(gen->board, "\n");
	wattroff(gen->board, COLOR_PAIR(11));
}

void	scroll_loop(t_general *gen, int array[4])
{
	int		index;
	int		color;
	int		player;

	index = 0;
	player = -1;
	color = 0;
	while (++player < 50)
	{
		if (array[color] == 0)
		{
			player--;
			color++;
			continue ;
		}
		index++;
		print_symbol(gen, '-', color + 1);
		if (index >= array[color] && color < gen->champ_num - 1)
		{
			color++;
			index = 0;
		}
	}
}

void	scroll_tool(t_general *gen, int i, int index, int sum)
{
	int			mass[4];
	int			array[4];

	if (scroll_base(gen) == 1 && gen->arr[0] == 0)
		return ;
	while (++i < gen->champ_num)
	{
		mass[i] = gen->players[i]->declared_live;
		sum += mass[i];
	}
	i = -1;
	while (++i < gen->champ_num)
		array[i] = 50 * mass[i] / sum;
	scroll_down(gen, array);
	wprintw(gen->board, "Live breakdown for last period :\n");
	if (gen->mark + 1 == gen->cycle_to_die)
	{
		scroll_array(gen, array);
		gen->mark = 0;
	}
	if (gen->total_cycles > CYCLE_TO_DIE)
		scroll_down(gen, gen->arr);
	else
	{
		wattron(gen->board, COLOR_PAIR(11));
		wprintw(gen->board, "[--------------------------------------------------]\n");
		wattroff(gen->board, COLOR_PAIR(11));
	}
}
