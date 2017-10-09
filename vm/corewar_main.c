/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 17:52:03 by msymkany          #+#    #+#             */
/*   Updated: 2017/08/03 18:01:51 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	the_winner_is(t_general *gen)
{
	int 	w;

	w = ((gen->winner) ? gen->winner : gen->champ_num);
	ft_printf("Player %d (%s) won\n", w, gen->players[w - 1]->name);
}

int		main(int ar, char **av)
{
    t_general   	*gen;

    if (ar == 1)
        ft_usage();
    gen = gen_init();
	read_args(ar, av, gen);
	visual_init(gen);
	visual_apd(gen);
	while (!gen->game_over)
	{
		(gen->total_cycles)++;
		(gen->current_cycles)++;
		process(gen);
		if (gen->current_cycles == gen->cycle_to_die)
			check_lives(gen);
		if (gen->dump >= 0 && gen->total_cycles == gen->dump)
		{
			dump_map(gen->field);
			exit(0);
		}
		visual_apd(gen);
	}
	if (!gen->v)
		the_winner_is(gen);
	else
		winner(gen);
//	while (1)
//		;
	return (0);
}
