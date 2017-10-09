#include "vm.h"

void		dump_map(unsigned char *line)
{
	size_t	i;
	size_t	k;
	size_t	j;

	k = 0;
	j = 0;
	while (k < MEM_SIZE)
	{
		i = 0;
		ft_printf("%-5d: ", (j++ * 64));
		while (i++ < 64)
		{
			ft_printf("%.2hhx ", line[k++]);
		}
		ft_printf("\n");
	}
}

void		introduce_contestants(t_player *bot)
{
	char 	col;

	col = (char)((bot->num == -4) ? (-(bot->num) + '1') : (-(bot->num) + '0'));
	ft_printf("=== Player %d, weighing %u bytes: ", -(bot->num), bot->size);
	ft_printf("\033[1;3%cm", col);
	ft_printf("%s\t# %s #\n", bot->name, bot->comment);
	ft_printf("\033[;0m");
}

void	init_process(t_general *gen, size_t j, size_t i)
{
	t_process	*head;

	head = (t_process *)ft_memalloc(sizeof(t_process));
	(head->reg)[1] = (uint32_t)(gen->players)[j]->num;
	head->pc = i;
	head->num = j + 1;
	head->color = j + 1;
	head->next = gen->process;
	gen->process = head;
	if (!gen->visual)
		introduce_contestants((gen->players)[j]);
}

void		write_to_map(t_general *gen)
{
	size_t		i;
	size_t		j;
	size_t		step;
	void		*ptr;

	i = 0;
	j = 0;
	step = (size_t)(MEM_SIZE) / gen->champ_num;
	if (!gen->visual)
		ft_printf("Introducing contestants...\n");
	else
	{
		gen->dump = -1;
		gen->debug = 0;
	}
	while (j < gen->champ_num)
	{
		init_process(gen, j, i);
		ptr = gen->players[j]->opcode;
		ft_memcpy(gen->field + i, ptr, gen->players[j]->size);
		ft_memset(&gen->colors[i], j + 1, gen->players[j]->size);
		j++;
		i += step;
	}
	gen->nbr_process = (uint32_t)gen->champ_num;
}
