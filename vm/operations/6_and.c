
#include "../vm.h"

int		is_valid_reg(uint32_t type, uint32_t value)
{
	if	(type == T_REG && (value >= 1 && value <= REG_NUMBER))
		return (1);
	else if (type != T_REG)
		return (-1);
	return (0);
}

void	and_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uint32_t		ar[MAX_ARGS_NUMBER];
	uint32_t		first;
	uint32_t		second;

	args_copy(args, ar, op[op_num].nbr_arg);
	uncode_args(gen->field, process, op_num, ar);
	if (!(is_valid_reg(args[2], ar[2]) && is_valid_reg(args[0], ar[0]) &&
		is_valid_reg(args[1], ar[1])))
		return ;
	else
	{
		first = ((is_valid_reg(args[0], ar[0])) ? process->reg[ar[0]] : ar[0]);
//		if (args[0] == T_DIR)
//			first = (short)ar[0];
		second = ((is_valid_reg(args[1], ar[1])) ? process->reg[ar[1]] : ar[1]);
		process->reg[ar[2]] = first & second;
		process->carry = (char)((process->reg[ar[2]] == 0) ? 1 : 0);
		if (gen->debug)
		{
			ft_printf("P%7u | and %d %d r%u -> %d & %d = %d\n", process->num,
					  args_val[0], first, second);
			ft_printf("         | %d + %d = %d -> go %d\n", first, second,
					  (first + second), sum_go);
		}
	}
//	if (is_valid_reg(args[0], ar[0]) && is_valid_reg(args[1], ar[1]))
//	{
//		process->reg[ar[2]] = process->reg[ar[0]] & process->reg[ar[1]];
//	}
//	else if (args[0] != T_REG && is_valid_reg(args[1], ar[1]))
//	{
//		process->reg[ar[2]] = ar[0] & process->reg[ar[1]];
//	}
//	else if (args[1] != T_REG && is_valid_reg(args[0], ar[0]))
//	{
//		process->reg[ar[2]] = process->reg[ar[0]] & ar[1];
//	}
//	else if (args[0] != T_REG && args[1] != T_REG)
//	{
//		process->reg[ar[2]] = ar[0] & ar[1];
//	}
}
