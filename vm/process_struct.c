#include "vm.h"

void	new_process(t_process *parent, t_process **head, uint32_t arg, int idx)
{
	t_process	*new;
	size_t		i;

	i = 0;
	new = (t_process *)malloc(sizeof(t_process));
	if (idx)
		new->pc = check_pc(parent->pc + (arg % IDX_MOD));
	else
		new->pc = check_pc(parent->pc + arg);
	new->carry = parent->carry;
	new->live = 0;
	new->on_hold = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = parent->reg[i];
		i++;
	}
	new->next = *head;
	*head = new;
}

size_t		kill_process(t_process **head)
{
	size_t		dead_process;
	t_process	*ptr;
	t_process	*tail;

	dead_process = 0;
	ptr = *head;
	if (!(*head)->live)
	{
		*head = NULL;
		return (1);
	}
	while (ptr->next)
	{
		ptr->live = 0; // null last node
		if (!ptr->next->live)
		{
			tail = ptr->next->next;
//			free(ptr->next);
//			ptr->next = NULL;
			ptr->next = tail;
			dead_process++;
		}
		else
			ptr = ptr->next;
	}
	ptr->live = 0;
	return (dead_process);
}
