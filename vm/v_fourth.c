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

void	print_symbol(t_general *gen, char c, int i)
{
	wattron(gen->board, COLOR_PAIR(i));
	wprintw(gen->board, "%c", c);
	wattroff(gen->board, COLOR_PAIR(i));
}
int		scroll_check(t_general *gen)
{
	int		i;

	i = -1;
	while (++i < gen->champ_num)
		if (gen->players[i]->last_live != 0)
			return (0);
	return (1);
}

void	scroll_base(t_general *gen)
{
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
	unsigned int		mass[4];
	int		array[4];

	n = 0;
	sum = 0;
	if (scroll_check(gen))
	{
		scroll_base(gen);
		return ;
	}
	print_symbol(gen, '[', 11);
	while (++i < gen->champ_num)
	{
		mass[i] = gen->players[i]->last_live;
		sum += mass[i];
	}
	i = -1;
	while (++i < gen->champ_num)
		array[i] = 50 * mass[i] / sum;
	i = 0;
	while (++j < 50)
	{
		n++;
		print_symbol(gen, '-', i + 1);
		if (n >= array[i] && i < gen->champ_num - 1)
		{
			i++;
			n = 0;
		}
	}
	print_symbol(gen, ']', 11);
	wprintw(gen->board, "\n\nLive breakdown for last period :\n");
	wattron(gen->board, COLOR_PAIR(11));
	wprintw(gen->board, "[--------------------------------------------------]\n\n");
	wattroff(gen->board, COLOR_PAIR(11));
}