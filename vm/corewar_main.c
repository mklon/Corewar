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

int		main(int ar, char **av)
{
	size_t		i;
	char		**champs;
	size_t		j;

	i = 0;
	j = 0;
	champs = NULL;
	if (ar == 1)
		ft_usage();
	else
//		ft_printf("args"); // test
//		check_magic(av[1]); // test magic
		while (++i < ar)
		{
			if (is_flag(av, &i)) // checks if arg is a flag and adds to struct(yet to come)
				;
			else if (is_champ(av[i]) && get_champ(av[i], &champs, j)) // checks if arg is a champ (*.cor)
				j++;
			else
				ft_error("invalid input"); // proper error message
		}
	return (0);
}
