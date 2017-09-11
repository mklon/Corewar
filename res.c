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
#include <ncurses.h>

char	*str = ".,((.;(..);;!;!;)(!;)(;.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjoprejgapkfldmkfndgreigj.,((.;(..);;!;!;)(!;)(;;_);_;(*=--+=_+_)_+)1gwegwegwe,fklhesifseoijgegewpijgd[pglvz,v;lrjopre";

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
}

void	dashboard(WINDOW *dboard)
{
	wmove(dboard, 0, 0);
	wprintw(dboard, "1232ddddddddddddddddddddddddddddddddddddddddddddddddddddddddds");
	wrefresh(dboard);
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

void	map_display(WINDOW *map, int i, int j)
{
	wmove(map, 0, 0);
	while (i < 4096)
	{
		while (i < j * 64)
		{
			if (i < 4096)
			{
				wattron(map, COLOR_PAIR(6));
				wprintw(map, "%02x", str[i]);
				wattroff(map, COLOR_PAIR(6));
			}
			if (i != j * 64 - 1)
				wprintw(map, " ");
			i++;
		}
		wprintw(map, "\n");
		wrefresh(map);
		j++;
	}
}


int		main()
{
	int		x = 4, y = 2;
	WINDOW *map, *text, *dboard;

	initscr();
	raw();
	color_init();
	curs_set(0);
	draw_border();
	map = newwin(65, 193, 2, 4);
	text = newwin(1, 1, 67, 256);
	dboard = newwin(64, 54, 2, 199);
	refresh();
	map_display(map, 0, 1);
	dashboard(dboard);
	while (wgetch(text) != 'q')
		wprintw(text ," ");
	endwin();
	return 0;
}
