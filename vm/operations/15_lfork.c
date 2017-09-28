#include "../vm.h"

void				lfork_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uncode_args(gen->field, process, op_num, args);
	new_process(process, &gen->process, args[0], 0);
	gen->nbr_process++;
}
