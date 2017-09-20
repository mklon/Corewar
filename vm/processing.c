#include "vm.h"

size_t		check_pc(size_t pc)
{
	if (pc > MEM_SIZE)
		pc = pc % MEM_SIZE;
	return (pc);
}

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

void		process(t_general *gen)
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

void		fetch(t_general *gen, t_process *process, int op_num)
{
	int 		step;
	uint32_t	args[MAX_ARGS_NUMBER];
	size_t		curr;

	step = 0;
	curr = check_pc(process->pc + 1);
	while (step < MAX_ARGS_NUMBER)
		args[step++] = 0;
	step = 1;
	if (check_cod_byte(op_num, gen->field[curr], &step, args))
	{
		fetch_args(gen->field, process, op_num, args);
		op[op_num].f(gen, process, op_num, args);
	}
	process->pc += step;
}
