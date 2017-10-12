/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:06:34 by msymkany          #+#    #+#             */
/*   Updated: 2017/10/12 13:06:37 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

uint32_t	check_pc(size_t pc)
{
	if (pc >= MEM_SIZE)
		pc = pc % MEM_SIZE;
	return ((uint32_t)pc);
}

void		check_lives(t_general *gen)
{
	size_t		i;

	i = 0;
	if (gen->process)
		gen->nbr_process -= kill_process(gen);
	while (i < gen->champ_num)
	{
		gen->players[i]->declared_live = 0;
		i++;
	}
	if (gen->live_per_period >= NBR_LIVE || gen->live_checks == 1)
	{
		gen->live_checks = MAX_CHECKS;
		gen->cycle_to_die -= CYCLE_DELTA;
	}
	else
		gen->live_checks--;
	if (gen->cycle_to_die <= 0 || !gen->process)
		gen->game_over = 1;
	gen->current_cycles = 0;
	gen->live_per_period = 0;
}

void		process_next(t_general *gen, t_process *ptr)
{
	if ((ptr->on_hold + 1) != g_op[ptr->op_num].cycle)
		ptr->on_hold++;
	else
	{
		fetch(gen, ptr, ptr->op_num);
		ptr->pc = check_pc(ptr->pc);
		ptr->on_hold = 0;
	}
}

void		process(t_general *gen)
{
	t_process	*ptr;
	int			curr_byte;

	ptr = gen->process;
	while (ptr)
	{
		curr_byte = gen->field[ptr->pc];
		if (!ptr->on_hold)
		{
			if (curr_byte && curr_byte < 17)
			{
				ptr->op_num = curr_byte - 1;
				(ptr->on_hold)++;
			}
			else
			{
				pc_color_down(gen, ptr->pc);
				ptr->pc = check_pc(ptr->pc + 1);
			}
		}
		else
			process_next(gen, ptr);
		ptr = ptr->next;
	}
}
