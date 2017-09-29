
#include "../vm.h"

void	xor_op(t_general *gen, t_process *p, int op_num, uint32_t *args)
{
	uint32_t		ar[MAX_ARGS_NUMBER];

	args_copy(args, ar, op[op_num].nbr_arg);
	uncode_args(gen->field, p, op_num, ar);
}
