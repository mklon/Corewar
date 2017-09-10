#include "vm.h"

int		validate_cod_byte(int op_num, int *args)
{
	size_t		i;

	i = 0;
	while (i < op[op_num].nbr_arg)
	{
		if (!(args[i] && op[op_num].arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int 	check_cod_byte(int op_num, unsigned char codbyte, int *step, int **args)
{
	size_t		i;
	size_t		shift;

	i = 0;
	shift = 6;
	ft_memset(args, 0, MAX_ARGS_NUMBER);
	while (i < MAX_ARGS_NUMBER)
	{
		(*args)[i] = codbyte && (192 >> shift);
		if (args[i])
		{
			if ((*args)[i] == REG_CODE)
				(*step) += REG_READ;
			else if ((*args)[i] == DIR_CODE)
				(*step) += op[op_num].flag_direct_size;
			else
			{
				(*args)[i] = T_IND;
				(*step) += IND_READ;
			}
		}
		shift -= 2;
		i++;
	}
	return (validate_cod_byte(op_num, *args));
}
