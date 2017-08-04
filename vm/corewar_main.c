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
		while (++i < ar)
		{
			if (is_flag(av[i])) // checks if arg is a flag and executes(?) one
				;
			else if (is_champ(av[i])) // checks if arg is a champ (*.cor)
			{
				champs = get_champ(av[i], champs, j); // if !champs-array - malloc. reads bytecode to array, calls validate_champ function, returns array
				j++;
			}
			else
				error("invalid input"); // proper error message
		}
	return (0);
}
