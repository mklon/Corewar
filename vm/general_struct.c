#include "vm.h"

t_general		*gen_init(void)
{
	t_general	*gen;
	size_t		j;

	j = 0;
	gen = (t_general *)malloc(sizeof(t_general));
	if (!gen)
		ft_error("Error in allocation");
	gen->field = ft_memalloc(MEM_SIZE);
	gen->total_cycles = 0;
	gen->process = 0;
	gen->cycle_to_die = 0;
	gen->nbr_live = 0;
	gen->dump = -1;
	gen->players = NULL;
	gen->champ_num = 0;
	return(gen);
}
