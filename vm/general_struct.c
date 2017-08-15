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
	//	gen->champs_args = (unsigned char **)malloc(sizeof(char*) * 3);
//	gen->champs_args[0] = (unsigned char *)ft_strnew(MAX_PLAYERS );
//	gen->champs_args[1] = (unsigned char *)ft_strnew(MAX_PLAYERS);
	gen->champ_num = 0;
	return(gen);
}
