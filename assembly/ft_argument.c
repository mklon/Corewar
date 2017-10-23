/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:28:17 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 20:52:12 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_prog	*last_elem(t_prog *prog)
{
	t_prog		*lst;

	lst = prog;
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static int		valid_argument(char *str, int *i, int *j, t_prog **prog)
{
	int			res;

	while (*str && *str < 33 && (*j)++)
		str++;
	if (str[0] == DIRECT_CHAR)
		res = valid_direkt(str, i, j, prog);
	else if (str[0] == 'r')
		res = valid_registr(str, i, j, prog);
	else
		res = valid_indir(str, i, j, prog);
	free(i);
	return (res);
}

static int		serch_argument(char **agr, int *i, int *j, t_all **all)
{
	t_prog		*prog;
	int			k;

	k = -1;
	prog = last_elem((*all)->prog);
	prog->caret = (*all)->header->prog_size;
	while (agr[++k])
	{
		if (valid_argument(agr[k], ft_tab(*i, k, 0), j, &prog) == -1)
			return (-1);
		if ((g_tab[prog->i].arg[k] & prog->arg[k]) != prog->arg[k])
			return (my_erormanager(g_tab[prog->i].name, ft_tab(0, 0, k), 4));
		if (k > g_tab[prog->i].count_arg)
			return (my_erormanager(g_tab[prog->i].name, ft_tab(0, 0, k), 4));
		(*j) += ft_strlen(agr[k]) - 1;
	}
	if (g_tab[prog->i].coding_byte == 1)
		prog->coding_byte = ft_coding_byt(prog);
	if (k != g_tab[prog->i].count_arg)
		return (my_erormanager(g_tab[prog->i].name, ft_tab(0, 0, 0), 3));
	(*all)->header->prog_size += ft_size_program(prog);
	return (0);
}

static void		ft_dell_arrey(char ***av)
{
	char		**buf;
	int			i;

	i = -1;
	buf = *av;
	while (buf[++i])
		ft_strdel(&(buf[i]));
	free(buf);
	*av = NULL;
}

int				ft_argument(char *line, int *i, int *j, t_all **all)
{
	char		*src;
	char		**argument;
	int			k;

	k = -1;
	src = line;
	while (++k < (*j))
		src++;
	if (!(argument = ft_strsplit(src, SEPARATOR_CHAR)) || !*argument)
		return (my_erormanager("\0", ft_tab(*i, *j, 0), 2));
	if (serch_argument(argument, i, j, all) == -1)
	{
		ft_dell_arrey(&argument);
		return (-1);
	}
	ft_dell_arrey(&argument);
	return (0);
}
