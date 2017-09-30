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

void	winner(t_general *gen)
{
	int 	w;

	wmove(gen->board, 43, 0);
	w = ((gen->winner) ? gen->winner : gen->champ_num);
	wprintw(gen->board, "Player %d (", ++gen->winner * (-1));
	wattron(gen->board, COLOR_PAIR(gen->colors[w - 1]));
	wprintw(gen->board, "%s", gen->players[w - 1]->name);
	wattroff(gen->board, COLOR_PAIR(gen->colors[w - 1]));
	wprintw(gen->board, ") won.\n\n");
	wprintw(gen->board, "Press any key to quit...\n");
	wrefresh(gen->board);
	while (getch() == ERR)
		;
	endwin();
}

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
	wrefresh(gen->board);
	if (pressing(gen) == 1)
		return ;
	initial_info(gen);
	wrefresh(gen->board);
	while(gen->pause > 0)
	{
		if (pressing(gen) == 1)
			return ;
		initial_info(gen);
		wrefresh(gen->board);
	}
	timeout(1000 / gen->limit);
	wrefresh(gen->board);

}

int		pressing(t_general *gen)
{
	char	c;

	wmove(gen->text, 0, 0);
	if (kbhit())
	{
		c = wgetch(gen->text);
		if (c == 'p')
			gen->pause *= -1;
		else if (gen->pause && c == 's')
			return (1);
		else
			limit_handel(gen, c);
	}
	return (0);
}

