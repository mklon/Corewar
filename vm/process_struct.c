/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:07:03 by msymkany          #+#    #+#             */
/*   Updated: 2017/10/12 13:07:04 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	new_process(t_process *parent, t_process **head, uint32_t arg, int idx)
{
	t_process	*new;
	size_t		i;
	short		con;

	i = 0;
	new = (t_process *)malloc(sizeof(t_process));
	if (idx)
	{
		con = (short)arg;
		new->pc = check_pc(parent->pc + (con % IDX_MOD));
	}
	else
		new->pc = check_pc(parent->pc + arg);
	new->carry = parent->carry;
	new->color = parent->color;
	new->live = parent->live;
	new->on_hold = 0;
	new->op_num = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = parent->reg[i];
		i++;
	}
	new->next = *head;
	*head = new;
}

size_t	kill_them_all(t_general *gen, t_process *ptr, size_t dead_process)
{
	t_process	*tail;

	while (ptr->next)
	{
		ptr->live = 0;
		if (!ptr->next->live)
		{
			tail = ptr->next->next;
			pc_color_down(gen, ptr->next->pc);
			free(ptr->next);
			ptr->next = NULL;
			ptr->next = tail;
			dead_process++;
		}
		else
			ptr = ptr->next;
	}
	ptr->live = 0;
	return (dead_process);
}

size_t	kill_process(t_general *gen)
{
	size_t		dead_process;
	t_process	*ptr;

	dead_process = 0;
	ptr = gen->process;
	while (ptr && !ptr->live)
	{
		gen->process = ptr->next;
		pc_color_down(gen, ptr->pc);
		free(ptr);
		ptr = NULL;
		ptr = gen->process;
		dead_process++;
	}
	if (!ptr)
		return (dead_process);
	else
		return (kill_them_all(gen, ptr, dead_process));
}
