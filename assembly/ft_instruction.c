/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:46:03 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 17:46:06 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*serch_name_instruction(char *line, int *j)
{
	char	*name;
	int		len;

	len = *j;
	name = NULL;
	while (line[len] && line[len] >= 97 && line[len] <= 122)
		len++;
	if (len != 0 && len != *j)
		name = ft_strnduplen(line, j, len);
	return (name);
}

static int	serch_instruction(char *name, int *i, int *j)
{
	int		k;
	int		count;

	k = -1;
	count = -1;
	while (++k < 16)
	{
		if (!ft_strcmp(g_tab[k].name, name))
		{
			count = k;
			break ;
		}
	}
	if (count == -1)
	{
		return (my_erormanager(name,
					ft_tab(*i, ((*j) - (int)ft_strlen(name)), 0), 5));
	}
	return (count);
}

static void	new_line_prog(int nbr, t_all **all)
{
	t_prog	*lst;

	if (!(*all)->prog)
	{
		(*all)->prog = (t_prog*)malloc(sizeof(t_prog));
		lst = (*all)->prog;
	}
	else
	{
		lst = (*all)->prog;
		while (lst->next)
			lst = lst->next;
		lst->next = (t_prog*)malloc(sizeof(t_prog));
		lst = lst->next;
	}
	lst->i = nbr;
	lst->label1 = NULL;
	lst->label2 = NULL;
	lst->label3 = NULL;
	lst->next = NULL;
}

int			ft_instruction(char *line, int *i, int *j, t_all **all)
{
	char	*name;
	int		nb_instruction;

	while (line[(*j)] && line[(*j)] < 33)
		(*j)++;
	if (!line || line[(*j)] == '\0')
		return (0);
	if (!(name = serch_name_instruction(line, j)) || name[0] == '\0')
		return (my_erormanager("", ft_tab(*i, *j, 0), 1));
	if (line[(*j)] == SEPARATOR_CHAR)
	{
		ft_strdel(&name);
		return (my_erormanager(",", ft_tab(*i, *j, 0), 2));
	}
	else if ((nb_instruction = serch_instruction(name, i, j)) == -1)
	{
		ft_strdel(&name);
		return (-1);
	}
	ft_strdel(&name);
	new_line_prog(nb_instruction, all);
	while (line[(*j)] && line[(*j)] < 33)
		(*j)++;
	return (ft_argument(line, i, j, all));
}
