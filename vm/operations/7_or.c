
#include "../vm.h"

void	or_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uint32_t		ar[MAX_ARGS_NUMBER];
	uint32_t		first;
	uint32_t		sec;

	args_copy(args, ar, op[op_num].nbr_arg);
	uncode_args(gen->field, process, op_num, ar);
	if (!(val_reg(args[2], ar[2]) && val_reg(args[0], ar[0])
		&& val_reg(args[1], ar[1])))
		return ;
	else
	{
		first = ((val_reg(args[0], ar[0]) == 1) ? process->reg[ar[0]] : ar[0]);
		sec = ((val_reg(args[1], ar[1]) == 1) ? process->reg[ar[1]] : ar[1]);
		process->reg[ar[2]] = first | sec;
		process->carry = (char)((process->reg[ar[2]] == 0) ? 1 : 0);
		if (gen->debug)
		{
			ft_printf("P%7u | or %d %d r%u -> %d | %d = %d\n", process->num,
					first, sec, ar[2], first, sec, process->reg[ar[2]]);
		}
	}
}
