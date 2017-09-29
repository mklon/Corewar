
#include "../vm.h"

void	and_op(t_general *gen, t_process *p, int op_num, uint32_t *args)
{
	uint32_t		ar[MAX_ARGS_NUMBER];

	args_copy(args, ar, op[op_num].nbr_arg);
	uncode_args(gen->field, p, op_num, ar);
	if (args[0] == T_REG && args[1] == T_REG && args[2] == T_REG)
		if (ar[0] >= 1 && ar[0] <= REG_NUMBER
			&& ar[1] >= 1 && ar[1] <= REG_NUMBER
			&& ar[2] >= 1 && ar[2] <= REG_NUMBER)
	{
		(op_num == 5) ? (p->reg[ar[2]] = p->reg[ar[0]] & p->reg[ar[1]]) : 0;
		(op_num == 6) ? (p->reg[ar[2]] = p->reg[ar[0]] | p->reg[ar[1]]) : 0;
		(op_num == 7) ? (p->reg[ar[2]] = p->reg[ar[0]] ^ p->reg[ar[1]]) : 0;
	}
	if (args[0] != T_REG && args[1] == T_REG && args[2] == T_REG)
		if (ar[1] >= 1 && ar[1] <= REG_NUMBER
			&& ar[2] >= 1 && ar[2] <= REG_NUMBER)
		{
			(op_num == 5) ? (p->reg[ar[2]] = ar[0] & p->reg[ar[1]]) : 0;
			(op_num == 6) ? (p->reg[ar[2]] = ar[0] | p->reg[ar[1]]) : 0;
			(op_num == 7) ? (p->reg[ar[2]] = ar[0] ^ p->reg[ar[1]]) : 0;
		}
	else
		or_op(gen, p, op_num, args);
	p->carry = (char)(p->reg[args[2]] == 0) ? 1 : 0;
}
