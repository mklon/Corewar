/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 17:52:03 by msymkany          #+#    #+#             */
/*   Updated: 2017/08/03 18:01:51 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	check_n_flag(t_general *gen)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	j = 1;
	k = MAX_PLAYERS - gen->champ_num;
	while (k > 0)
	{
		if (gen->n_flag[gen->champ_num + k] != 0)
			ft_error("bad order of numb after flag -n\n");
		k--;
	}
	while (++i <= gen->champ_num)
	{
		if (gen->n_flag[i] == 0)
		{
			gen->n_flag[i] = gen->no_flag[j];
			j++;
		}
	}
}

void	read_args(int ar, char **av, t_general *gen)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 1;
	while (++i < ar)
	{
		if (is_flag(av, &i, gen)) // checks if arg is a flag and adds to struct
			;
		else if (is_champ(av[i]))
		{
			if (gen->champ_num == MAX_PLAYERS)
				ft_error("To many champions\n");
			gen->no_flag[j++] = i;
			gen->champ_num++;
		}
		else
			ft_error("Invalid input file\n");
	}
	if (gen->champ_num == 0)
		ft_error("No champions\n");
	check_n_flag(gen);
	read_players(av, gen);
	//	write_to_map(gen);
}

int		main(int ar, char **av)
{
    t_general   *gen;
	size_t 		j; //test

	j = 1; // test
    if (ar == 1)
        ft_usage();
    gen = gen_init();
	read_args(ar, av, gen);

//	while(1)
//		;
	return (0);
}
