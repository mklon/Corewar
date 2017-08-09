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
	char	*c;
	WINDOW *win;
        
	initscr();
	raw();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_MAGENTA);
	init_color(COLOR_MAGENTA, 400, 400, 400);
	attron(COLOR_PAIR(1));
	hline(' ', 254);
	vline(' ', 67);
	move(0, 1);
	vline(' ', 67);
	move(66, 0);
	hline(' ', 254);
	move(0, 254);
	vline(' ', 67);
	move(0, 255);
	vline(' ', 67);
	move(0, 197);
	vline(' ', 67);
	move(0, 0);
	while ((*c = getch()) != 27)
	{
		if (*c == 13)
			move(0, 10);
	}
	attroff(COLOR_PAIR(1));
	endwin();
	return 0;
}
