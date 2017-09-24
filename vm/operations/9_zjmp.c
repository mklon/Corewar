#include "../vm.h"

void		zjmp_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	if (process->carry == 1)
	{
		process->reg[1] = args[1];//??
	}
}