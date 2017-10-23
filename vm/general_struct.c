/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:10:17 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/10/12 15:10:18 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_array(size_t *arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

void		gen_init_next(t_general *gen)
{
	gen->limit = 50;
	gen->players = NULL;
	gen->champ_num = 0;
	gen->game_over = 0;
	gen->winner = 0;
	gen->line = NULL;
	gen->process = NULL;
	gen->mark = 0;
	gen->low = 0;
	gen->alive = 0;
	init_array(gen->n_flag, (MAX_PLAYERS + 1));
	init_array(gen->no_flag, (MAX_PLAYERS + 1));
}

t_general	*gen_init(void)
{
	t_general	*gen;

	gen = (t_general *)malloc(sizeof(t_general));
	if (!gen)
		ft_error("Error in allocation");
	ft_bzero(gen->field, MEM_SIZE);
	ft_memset(gen->colors, 11, MEM_SIZE);
	ft_memset(gen->holdup, 0, MEM_SIZE);
	gen->total_cycles = 0;
	gen->current_cycles = 0;
	gen->nbr_process = 0;
	gen->total_process = 0;
	gen->cycle_to_die = CYCLE_TO_DIE;
	gen->live_per_period = 0;
	gen->live_checks = MAX_CHECKS;
	gen->dump = -1;
	gen->aff = 0;
	gen->debug = 0;
	gen->visual = 0;
	gen->pause = 1;
	gen_init_next(gen);
	return (gen);
}
