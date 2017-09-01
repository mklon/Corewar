#include "vm.h"

void		check_lives(t_general *gen)
{
	size_t		i;
	size_t		live_sum;
	size_t		dead_players;

	i = 0;
	dead_players = 0;
	while (i < gen->champ_num)
	{
		live_sum += gen->players[i]->all_live;
		gen->players[i]->all_live = 0;
		if (gen->players[i]->process)
			gen->nbr_process -= kill_process(&gen->players[i]->process);
		else
			dead_players++; // check if player alive
		i++;
	}
	if (live_sum >= NBR_LIVE)
		gen->cycle_to_die -= CYCLE_DELTA;
	else if (gen->live_checks == 1)
	{
		gen->live_checks = MAX_CHECKS;
		gen->cycle_to_die -= CYCLE_DELTA;
	}
	if (gen->cycle_to_die <= 0 || dead_players == gen->champ_num)
		return ; // winner is??????
	gen->current_cycles = 0;
}
