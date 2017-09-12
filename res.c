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
#include "vm/vm.h"
#include "graph.h"

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
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void	dashboard(WINDOW *board)
{
	wmove(board, 0, 0);
	attron(COLOR_PAIR(7));
	wprintw(board, "1232ddddddddddddddddddddddddddddddddddddddddddddddddddddddddds");
	if ()
	attroff(COLOR_PAIR(7));
	wrefresh(board);
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

void	start_graph(void)
{
	initscr();
	raw();
	color_init();
	use_default_colors();
	curs_set(0);
	draw_border();
}

int		main()
{
	int		x = 4, y = 2;
	t_g		m;
	struct s_general	*l;

	start_graph();
	m.map = newwin(65, 193, 2, 4);
	m.text = newwin(1, 1, 67, 256);
	m.board = newwin(64, 54, 2, 199);
	refresh();
	map_display(m.map, 0, 1);
	dashboard(m.board);
	while (wgetch(m.text) != 'z')
		wprintw(m.text ," ");
	endwin();
	return 0;
}
