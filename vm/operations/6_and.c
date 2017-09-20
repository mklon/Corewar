
#include "../vm.h"

void	and(t_general *gen, t_process *process, int op_num, int *args)
{
	if (args[1] >= 0 && args[1] <= 16 && args[2] >= 0 && args[2] <= 16)
		//&& args[3] >= 0 && args[3] <= 16) ??
	{
		args[3] = args[1] + args[2];
		process->carry = (proc->reg[args[3]] == 0) ? 1 : 0;	
	}
}
