 #include "../vm.h"

void	live_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	int 	player_num;

	uncode_args(gen->field, process, op_num, args);
	player_num = -1 * ((int)args[0]);
	if (player_num > 0 && player_num <= gen->champ_num)
	{
		(gen->players[player_num - 1]->declared_live)++;
		gen->players[player_num - 1]->last_live = gen->total_cycles;
		if (!gen->visual)
			ft_printf("A process shows that player %d (%s) is alive\n",
						player_num, gen->players[player_num - 1]->name);
		gen->winner = player_num;
	}
	(gen->live_per_period)++;
	(process->live)++;
}
