#include "../vm.h"

void	live(t_general *gen, t_process *process, int op_num)
{
	int 	step;
	int 	args[MAX_ARGS_NUMBER];

	step = 0;
	if (check_coding_byte(op_num, gen->field[++process->pc], &step, &args))
	{
		fetch(process, op_num);

	}
	process->pc += step;
}
