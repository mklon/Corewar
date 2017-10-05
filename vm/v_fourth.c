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

void	pc_color_down(t_general *gen, size_t i)
{
	if (gen->colors[i] == 5)
			gen->colors[i] = 1;
		else if (gen->colors[i] == 6)
			gen->colors[i] = 2;
		else if (gen->colors[i] == 7)
			gen->colors[i] = 3;
		else if (gen->colors[i] == 8)
			gen->colors[i] = 4;
}

int		scroll_check(t_general *gen)
{
	if (gen->players[0]->last_live == 0
		&& gen->players[1]->last_live == 0
		&& gen->players[2]->last_live == 0
		&& gen->players[3]->last_live == 0)
		return (1);
	return (0);
}

void	scroll_base(t_general *gen)
{
	wprintw(gen->board, "Live breakdown for last period :\n");
	wattron(gen->board, COLOR_PAIR(11));
	wprintw(gen->board, "[--------------------------------------------------]\n\n");
	wattroff(gen->board, COLOR_PAIR(11));
	wprintw(gen->board, "Live breakdown for last period :\n");
	wattron(gen->board, COLOR_PAIR(11));
	wprintw(gen->board, "[--------------------------------------------------]\n\n");
	wattroff(gen->board, COLOR_PAIR(11));
}

void	scroll_tool(t_general *gen, int i, int j)
{
	int		n;
	int		sum;
	int		mass[4];
	int		array[4];

	n = -1;
	if (scroll_check(gen))
	{
		scroll_base(gen);
		return ;
	}
	wprintw(gen->board, "Live breakdown for last period :\n");
	wattron(gen->board, COLOR_PAIR(11));
	wprintw(gen->board, "[");
	wattroff(gen->board, COLOR_PAIR(11));
	while (++i < 4)
		mass[i] = gen->players[i++]->last_live;
	i = 0;
	while (++i < 4)
		array[i] = 50 * mass[i] / sum;
	sum = mass[0] + mass[1] + mass[2] + mass[3];
	//wprintw(gen->board, "%d", sum);
	i = 0;
	while (++j < 50)
	{
		n++;
		wattron(gen->board, COLOR_PAIR(i + 1));
		wprintw(gen->board, "-");
		wattroff(gen->board, COLOR_PAIR(i + 1));
		if (n >= mass[j])
		{
			i++;
			n = -1;
		}
	}
	wprintw(gen->board, "Live breakdown for last period :\n");
	wattron(gen->board, COLOR_PAIR(11));
	wprintw(gen->board, "[--------------------------------------------------]\n\n");
	wattroff(gen->board, COLOR_PAIR(11));
}