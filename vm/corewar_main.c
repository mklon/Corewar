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


int		main(int ar, char **av)
{
    t_general   *gen;

    if (ar == 1)
        ft_usage();
    gen = gen_init();
	read_args(ar, av, gen);
	while (!gen->winner)
	{
		if (gen->dump >= 0 && gen->total_cycles == gen->dump)
		{
			dump_map(gen->field);
			exit(0);
		}
		if (gen->current_cycles == gen->cycle_to_die)
			check_lives(gen);
		process();
		gen->total_cycles++;
		gen->current_cycles++;
	}
//	while(1)
//		;
	return (0);
}
