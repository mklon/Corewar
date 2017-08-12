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

void	read_args(int ar, char **av)
{
	size_t		i;
	char		**champs;
	size_t		j;

	i = 0;
	j = 0;
	champs = NULL;
	while (++i < ar)
	{
		if (is_flag(av, &i)) // checks if arg is a flag and adds to struct(yet to come)
			;
		else if (is_valid_champ(av[i], &champs, j)) // checks if arg is a champ (*.cor)
			j++;
	}
}

int		main(int ar, char **av)
{
    t_general   *gen;

    if (ar == 1)
        ft_usage();
    gen = gen_init();
	read_args(ar, av);
//	while(1)
//		;
	return (0);
}
