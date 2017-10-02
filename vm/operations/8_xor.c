
#include "../vm.h"

void	xor_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{

	uint32_t		ar[MAX_ARGS_NUMBER];

	args_copy(args, ar, op[op_num].nbr_arg);
	uncode_args(gen->field, process, op_num, ar);
	if (!(ar[2] >= 1 && ar[2] <= REG_NUMBER))
		return ;
	if (args[0] == T_REG && args[1] == T_REG
		&& (ar[0] >= 1 && ar[0] <= REG_NUMBER
			&& ar[1] >= 1 && ar[1] <= REG_NUMBER))
		process->reg[ar[2]] = process->reg[ar[0]] ^ process->reg[ar[1]];
	else if (args[0] != T_REG && args[1] == T_REG
			 && (ar[1] >= 1 && ar[1] <= REG_NUMBER))
		process->reg[ar[2]] = ar[0] ^ process->reg[ar[1]];
	else if (args[0] == T_REG && args[1] != T_REG
			 && (ar[0] >= 1 && ar[0] <= REG_NUMBER))
		process->reg[ar[2]] = process->reg[ar[0]] ^ ar[1];
	else if (args[0] != T_REG && args[1] != T_REG)
		process->reg[ar[2]] = ar[0] ^ ar[1];
	else
		return ;
	process->carry = (char)((process->reg[args[2]] == 0) ? 1 : 0);
}
