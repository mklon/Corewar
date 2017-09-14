#include "vm.h"

void		check_lives(t_general *gen)
{
	size_t		i;

	i = 0;
	if (gen->process)
		gen->nbr_process -= kill_process(&gen->process);
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

void 	process(t_general *gen)
{
	t_process	*ptr;
	int			curr_byte;

	ptr = gen->process;
	while (ptr)
	{
		curr_byte = gen->field[ptr->pc];
		if (!ptr->on_hold)
			(curr_byte && curr_byte < 17) ? (ptr->on_hold)++ : (ptr->pc)++; // what if pc > MEM_size
		else
		{
			ft_printf("%d\n", op[curr_byte - 1].cycle);
			if (ptr->on_hold != op[curr_byte - 1].cycle)
				ptr->on_hold++;
			else
			{
 				fetch(gen, ptr, curr_byte - 1);
				ptr->on_hold = 0;
			}
		}
		ptr->pc = check_pc(ptr->pc);
		ptr = ptr->next;
	}
}
