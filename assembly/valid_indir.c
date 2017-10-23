/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_indir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:29:35 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 20:29:39 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		valid_indir(char *str, int *tab, int *j, t_prog **prog)
{
	int		i;

	i = 0;
	(*prog)->arg[tab[1]] = T_IND;
	while (str[i] && str[i] < 33)
		i++;
	if (str[i] == LABEL_CHAR)
		return (ft_islabel(str, tab, j, prog));
	if (str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && str[i] < 33)
		i++;
	if (str[i] != '\0')
		return (my_erormanager(str + i, ft_tab(tab[0], *j, 3), 2));
	(*prog)->value[tab[1]] = ft_atoi(str);
	return (T_IND);
}

char	*serch_coment(char *lin)
{
	int		i;
	char	*src;

	i = -1;
	while (lin[++i] && lin[i] != COMMENT_CHAR && lin[i] != ';')
		;
	if (lin[i] == '\0')
		return (lin);
	src = ft_strndup(lin, (size_t)i);
	src[i] = '\0';
	ft_strdel(&lin);
	return (src);
}

int		ft_out_space(char *str, int i)
{
	while (str[++i] && str[i] < 33)
		;
	return (i);
}
