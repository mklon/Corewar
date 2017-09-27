/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 16:18:32 by oposhiva          #+#    #+#             */
/*   Updated: 2017/08/08 16:18:32 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include "vm.h"

int		kbhit(void)
{
	int ch;

	if ((ch = getch()) != ERR)
	{
		ungetch(ch);
		return ch;
	}
	else
		return 0;
}

void	color_init(void)
{
	start_color();
	init_color(COLOR_WHITE, 999, 999, 999);
	init_color(COLOR_MAGENTA, 400, 400, 400);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(10, COLOR_WHITE, COLOR_RED);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(20, COLOR_WHITE, COLOR_GREEN);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(30, COLOR_WHITE, COLOR_BLUE);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(40, COLOR_WHITE, COLOR_YELLOW);
	init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void	draw_border(void)
{
	char	c;
	WINDOW *win;

	c = ' ';
	attron(COLOR_PAIR(5));
	hline(c, 254);
	vline(c, 67);
	move(0, 1);
	vline(c, 67);
	move(67, 0);
	hline(c, 254);
	move(0, 254);
	vline(c, 68);
	move(0, 255);
	vline(c, 68);
	move(0, 197);
	vline(c, 67);
	attroff(COLOR_PAIR(5));
}

void	start_graph(void)
{
	initscr();
	raw();
	color_init();
	curs_set(0);
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	scrollok(stdscr, TRUE);
	draw_border();
}

void	visualization(t_general *gen)
{
	if (!gen->v)
		return ;
	start_graph();
	gen->map = newwin(65, 193, 2, 4);
	gen->text = newwin(1, 1, 67, 256);
	gen->board = newwin(64, 53, 2, 200);
	refresh();
	map_display(gen, 0, 1);
	initial_info(gen);
	wrefresh(gen->map);
	wrefresh(gen->board);

}