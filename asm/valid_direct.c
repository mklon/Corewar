/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_direct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:18:11 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 20:18:16 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	name_lable(char *str, int *i, t_prog **prog, int k)
{
	char	*name;
	int		z;

	name = (char*)malloc(sizeof(char) * k - 1);
	k = 0;
	z = -1;
	while (str[++k] && str[k] > 33)
		name[++z] = str[k];
	name[++z] = '\0';
	if (i[1] == 0)
		(*prog)->label1 = name;
	else if (i[1] == 1)
		(*prog)->label2 = name;
	else
		(*prog)->label3 = name;
}

int			ft_islabel(char *str, int *i, int *j, t_prog **prog)
{
	int		k;
	int		z;

	k = 0;
	if (str[1] < 33)
		return (my_erormanager("", ft_tab(i[0], (*j) + 1, 0), 1));
	(*prog)->i_j[0] = *i;
	(*prog)->i_j[1] = *j;
	while (str[++k] && str[k] > 33)
	{
		if (!ft_strchr(LABEL_CHARS, str[k]))
			return (my_erormanager("", ft_tab(i[0], (*j) + k, 0), 1));
	}
	z = k;
	while (str[z] && str[z] < 33)
		z++;
	if (str[z] != '\0')
		return (my_erormanager(str + z, ft_tab(i[0], (*j) + z, 4), 2));
	name_lable(str, i, prog, k);
	return (0);
}

int			valid_direkt(char *str, int *i, int *j, t_prog **prog)
{
	int		k;

	k = 1;
	(*prog)->arg[i[1]] = T_DIR;
	if (str[0] == DIRECT_CHAR && str[1] < 33)
		return (my_erormanager((str + k), ft_tab(i[0], (*j) + 1, 0), 1));
	if (str[1] == LABEL_CHAR)
		return (ft_islabel(str + 1, i, j, prog));
	if (str[k] == '-')
		k++;
	while (str[k] && ft_isdigit(str[k]))
		k++;
	while (str[k] && str[k] < 33)
		k++;
	if (str[k] != '\0')
		return (my_erormanager((str + k), ft_tab(i[0], (*j) + k, 4), 2));
	(*prog)->value[i[1]] = ft_atoi(str + 1);
	return (0);
}
