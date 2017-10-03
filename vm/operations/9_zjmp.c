#include "../vm.h"

void	zjmp_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uncode_args(gen->field, process, op_num, args);
//	ft_printf("process->carry: %d\n", process->carry ); //test
	if (process->carry == 1)
	{
		process->pc = check_pc(process->pc + args[0]);
	}
}
