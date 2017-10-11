#include "../vm.h"

void	lfork_op(t_general *gen, t_process *process, int op_num, uint32_t *arg)
{
	uncode_args(gen->field, process, op_num, arg);
	new_process(process, &gen->process, arg[0], 0);
	(gen->nbr_process)++;
	gen->process->num = ++(gen->total_process);
	if (gen->debug)
	{
		ft_printf("P%7u | lfork %hd (p %u)\n", process->num, (short)arg[0],
				  gen->process->num);
	}
}
