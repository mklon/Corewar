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
	int		i;

	i = -1;
	if (gen->low)
		while (++i < (int)gen->champ_num)
			if (array[i] != 0)
			{
				print_symbol(gen, '[', 11);
				scroll_loop(gen, array);
				print_symbol(gen, ']', 11);
				wprintw(gen->board, "\n");
				return ;
			}
	wattron(gen->board, COLOR_PAIR(11));
	wprintw(gen->board, "[--------------------------------------------------]"
			"\n");
	wattroff(gen->board, COLOR_PAIR(11));
}

void	scroll_loop(t_general *gen, int *array)
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
		if (index >= array[color] && color < (int)gen->champ_num - 1)
		{
			color++;
			index = 0;
		}
	}
}

void	scroll_tool(t_general *gen, int i, int sum)
{
	int			mass[MAX_PLAYERS];
	int			curr[MAX_PLAYERS];
	static int	last[MAX_PLAYERS];

	while (++i < (int)gen->champ_num)
		curr[i] = 0;
	if (!scroll_check(gen))
	{
		i = -1;
		gen->low = 1;
		while (++i < (int)gen->champ_num)
		{
			mass[i] = gen->players[i]->declared_live;
			sum += mass[i];
		}
		i = -1;
		while (++i < (int)gen->champ_num)
			curr[i] = 50 * mass[i] / sum;
		curr[gen->champ_num - 1]++;
	}
	scroll_down(gen, curr);
	wprintw(gen->board, "Live breakdown for last period :\n");
	if (gen->mark + 1 == (int)gen->cycle_to_die)
		scroll_array(gen, curr, last);
	scroll_down(gen, last);
}
