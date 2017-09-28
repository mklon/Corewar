#include "../vm.h"

void	live_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	int 	player_num;

	uncode_args(gen->field, process, op_num, args);
	player_num = -1 * ((int)args[0]);
	ft_printf("player_num: %d\n", player_num); // test
	if (player_num > 0 && player_num <= gen->champ_num)
	{
		(gen->players[player_num - 1]->declared_live)++;
		gen->players[player_num - 1]->last_live = gen->total_cycles;
		ft_printf("A process shows that player %d", player_num);
		ft_printf("(%s) is alive\n", gen->players[player_num - 1]->name);
		gen->winner = player_num;
	}
	(gen->live_per_period)++;
	(process->live)++;
	return ;
}
