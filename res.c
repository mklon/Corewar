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

#include <ncurses.h>

int main()
{
	WINDOW *win;
        
	initscr();
	raw();
	start_color();
	init_color(COLOR_BLUE, 128, 128, 128);
	attron(COLOR_PAIR(1));
	hline(' ', 100);
	vline(' ', 100);
	init_pair(1, COLOR_GREEN, COLOR_BLUE);
	init_pair(2, COLOR_BLUE, COLOR_RED);
	mvprintw(2, 15, "Dialog     ");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	getch();
	refresh();
	move(0, 0);
	printw("84845");
	attroff(COLOR_PAIR(2));
	while (getch() != 27)
		;
	endwin();
	return 0;
}