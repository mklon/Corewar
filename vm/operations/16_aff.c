#include "../vm.h"

void				aff_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	if (gen->aff)
	{
		uncode_args(gen->field, process, op_num, args);
		ft_printf("Aff: %c\n", (char)process->reg[args[0]]);
	}
	return ;
}
