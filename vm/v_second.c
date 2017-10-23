/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_second.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:15:19 by oposhiva          #+#    #+#             */
/*   Updated: 2017/09/26 17:15:20 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	map_display(t_general *gen, int i, int j)
{
	wmove(gen->map, 0, 0);
	while (i < MEM_SIZE)
	{
		while (i < j * 64)
		{
			if (i < MEM_SIZE)
			{
				wattron(gen->map, COLOR_PAIR(gen->colors[i]));
				wprintw(gen->map, "%02x", gen->field[i]);
				wattroff(gen->map, COLOR_PAIR(gen->colors[i]));
			}
			if (i != j * 64 - 1)
				wprintw(gen->map, " ");
			i++;
		}
		wprintw(gen->map, "\n");
		j++;
	}
}

void	players_info(t_general *gen)
{
	int		i;

	i = 0;
	while (++i <= (int)gen->champ_num)
	{
		wprintw(gen->board, "Player %d > ", (i - 2 * i), gen->players[i - 1]);
		wattron(gen->board, COLOR_PAIR(i));
		wprintw(gen->board, "%s\n", gen->players[i - 1]->name);
		wattroff(gen->board, COLOR_PAIR(i));
		wprintw(gen->board, "	Last live > %d\n",
			gen->players[i - 1]->last_live);
		wprintw(gen->board, "	Lives in current period > %d\n\n",
				gen->players[i - 1]->declared_live);
	}
}

void	initial_info(t_general *gen)
{
	wmove(gen->board, 0, 0);
	gen->pause == 1 ? wprintw(gen->board, "# PAUSED  #\n\n") :
					wprintw(gen->board, "# RUNNING #\n\n");
	wprintw(gen->board, "Cycles/second limit > %d\n\n\n", gen->limit);
	wprintw(gen->board, "Cycle > %d\n\n\n", gen->total_cycles);
	wprintw(gen->board, "Processes > %d\n\n", gen->nbr_process);
	players_info(gen);
	wprintw(gen->board, "Live breakdown for current period :\n");
	scroll_tool(gen, -1, 0);
	wprintw(gen->board, "CYCLE_TO_DIE > %d\n\n", gen->cycle_to_die);
	wprintw(gen->board, "CYCLE_DELTA > %d\n\n", CYCLE_DELTA);
	wprintw(gen->board, "NBR_LIVE > %d\n\n", NBR_LIVE);
	wprintw(gen->board, "MAX_CHECKS > %d\n\n", MAX_CHECKS);
}
