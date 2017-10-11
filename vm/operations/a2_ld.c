/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyatsulk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 21:46:13 by nyatsulk          #+#    #+#             */
/*   Updated: 2017/10/11 21:46:14 by nyatsulk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	ld_op(t_general *gen, t_process *process, int op_num, uint32_t *args)
{
	uncode_args(gen->field, process, op_num, args);
	if (args[1] >= 1 && args[1] <= 16)
	{
		process->reg[args[1]] = args[0];
		process->carry = (char)((process->reg[args[1]] == 0) ? 1 : 0);
	}
	if (gen->debug)
		ft_printf("P%7u | ld %d r%u\n", process->num, args[0], args[1]);
}
