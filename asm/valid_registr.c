/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_registr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:31:25 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 20:31:29 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	serch_endlin(char *str, int *tab, int j)
{
	int		i;

	i = 0;
	while (str[++i] && ft_isdigit(str[i]))
		;
	while (str[i] && str[i] < 33)
		i++;
	if (str[i] == 'r')
		return (my_erormanager(str + i, ft_tab(tab[0], j + i, 2), 2));
	if (str[i] != '\0')
		return (my_erormanager(str + i, ft_tab(tab[0], j + i, 1), 2));
	else
		return (0);
}

int			valid_registr(char *str, int *tab, int *j, t_prog **prog)
{
	int		nb;

	nb = 0;
	(*prog)->arg[tab[1]] = T_REG;
	if (serch_endlin(str, tab, *j) == -1)
		return (-1);
	nb = ft_atoi(str + 1);
	if (nb <= 0 || nb > REG_NUMBER)
		return (my_erormanager(str, ft_tab(tab[0], *j, 1), 2));
	(*prog)->value[tab[1]] = nb;
	return (T_REG);
}
