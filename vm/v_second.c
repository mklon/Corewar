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
	while (i < 4096)
	{
		while (i < j * 64)
		{
			if (i < 4096)
			{
				wattron(gen->map, COLOR_PAIR(6));
				wprintw(gen->map, "%02x", gen->field[i]);
				wattroff(gen->map, COLOR_PAIR(6));
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
	while (++i <= gen->champ_num)
	{
		wprintw(gen->board, "Player %d : ", (i - 2 * i),  gen->players[i - 1]);
		attron(COLOR_PAIR(10));
		wprintw(gen->board, "%s\n", gen->players[i - 1]->name);
		attroff(COLOR_PAIR(10));
		wprintw(gen->board, "	Last live : %d\n", 0);
		wprintw(gen->board, "	Lives in current period : %d\n\n", 0);
	}
	
}

void	initial_info(t_general *gen)
{
	wprintw(gen->board, "# PAUSED  #\n\n");
	wprintw(gen->board, "Cycles/second limit : %d\n\n\n", 1);
	wprintw(gen->board, "Cycle : %d\n\n\n", 1);
	wprintw(gen->board, "Processes :%d\n\n", 1);
	players_info(gen);
}

void	dashboard(t_general *gen)
{
	int		i = -1;
	char	c;

	i < 0 ? wprintw(gen->board, "# PAUSED  #") : wprintw(gen->board, "# RUNNING #");
	attron(COLOR_PAIR(7));
	while (true)
	{
		wmove(gen->board, 0, 0);
		wmove(gen->text, 0, 0);
		if (kbhit())
		{
			c = wgetch(gen->text);
			if (c == 'p')
			{
				i *= -1;
				i < 0 ? wprintw(gen->board, "# PAUSED  #") : wprintw(gen->board, "# RUNNING #");
			}
			else if (c == 'z')
			{
				system("clear");
				exit(1);
			}
		}
		wrefresh(gen->board);
	}
	attroff(COLOR_PAIR(7));
}
