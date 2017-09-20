#include "../vm.h"

void	zjmp(t_general *gen, t_process *process, int op_num, int *args)
{
	if (process->carry == 1)
	{
		process->reg[1] = args[1];//??
	}
}