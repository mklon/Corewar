#include "vm.h"

void	dump_map(unsigned char *line)
{
	int		i;
	int		k;
	int		j;

//	i = -1;
	k = -1;
	j = -1;
	while (k < MEM_SIZE)
	{
		i = -1;
		ft_printf("%-5d:", ++j);
		while (++i < 64)
		{
			ft_printf("%.2hhX ", line[++k]);
		}
		ft_printf("\n");
	}
}

void 	write_to_map(t_general *gen)
{
	size_t		i;
	size_t		j;
	size_t		step;
	void		*ptr;

	i = 0;
	j = 0;
	step = MEM_SIZE / gen->champ_num;
	while (j < gen->champ_num)
	{
		ptr = gen->champs[j];
		ft_memcpy(gen->field + i, ptr + PROG_HEADER_LENGTH, CHAMP_MAX_SIZE);
		j++;
		i += step;
	}
	dump_map(gen->field);
}
