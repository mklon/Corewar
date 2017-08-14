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

void	read_args(int ar, char **av, t_general *gen)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (++i < ar)
	{
		if (is_flag(av, &i, gen)) // checks if arg is a flag and adds to struct
			;
		else if (is_champ(av[i]))
		{
		}

	}
//	is_valid_champ(av[i], gen->champs, j);
}

int		main(int ar, char **av)
{
    t_general   *gen;

    if (ar == 1)
        ft_usage();
    gen = gen_init();
	read_args(ar, av, gen);
//	while(1)
//		;
	return (0);
}
