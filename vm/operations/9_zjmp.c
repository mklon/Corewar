#include "../vm.h"

void	zjmp_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uncode_args(gen->field, process, op_num, args);
//	ft_printf("process->carry: %d\n", process->carry ); //test
	if (process->carry == 1)
	{
		pc_color_down(gen, process->pc);
		process->pc = check_pc(process->pc + ((short)args[0] % IDX_MOD));
	}
}
