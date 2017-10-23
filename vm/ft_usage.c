/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:07:18 by msymkany          #+#    #+#             */
/*   Updated: 2017/10/12 13:07:21 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../op.h"

void	ft_usage(void)
{
	ft_printf("\n");
	ft_printf("Usage: ./corewar [-d N [-l | -g] | -v] [-a] [[-n N] ");
	ft_printf("<champion1.cor>] <champion2.cor> <...>\n");
	ft_printf("    -a        : Prints output from \"aff\" ");
	ft_printf("(Default is to hide it)\n");
	ft_printf("    -d N      : Dumps memory after N cycles then exits\n");
	ft_printf("    -v        : Ncurses output mode\n");
	ft_printf("    -n N      : sets the number N of the next player\n");
	ft_printf("    -g        : Show operations (DEBUG)\n");
	ft_printf("    -l        : Shows that champions are alive\n");
	ft_printf("\n");
	exit(0);
}
