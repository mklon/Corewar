/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serch_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:05:27 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 20:05:32 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_strnduplen(char *str, int *start, int finish)
{
	char	*src;
	int		i;

	i = -1;
	src = (char*)malloc(sizeof(char) * (finish - (*start)) + 1);
	while (*start < finish)
		src[++i] = str[(*start)++];
	src[++i] = '\0';
	return (src);
}

static int	serch_dublikat_label(char *name, int i, int j, t_all **all)
{
	t_stak	*lst;

	if (!name || !(*all)->stak)
		return (1);
	lst = (*all)->stak;
	while (lst)
	{
		if (!ft_strcmp(name, lst->funk_name))
		{
			ft_printf("{fd}Label with this name already exists [TOKEN]"
				"[%{fd}03d{fd}:%{fd}03d{fd}] \"%{fd}s{fd}\"\n",
				2, 2, i, 2, 2, j, 2, 2, name, 2);
			return (-1);
		}
		lst = lst->next;
	}
	return (1);
}

static void	new_label(char *name, t_all **all)
{
	t_stak	*lst;

	if (!(*all)->stak)
	{
		(*all)->stak = (t_stak*)malloc(sizeof(t_stak));
		lst = (*all)->stak;
	}
	else
	{
		lst = (*all)->stak;
		while (lst->next)
			lst = lst->next;
		lst->next = (t_stak*)malloc(sizeof(t_stak));
		lst = lst->next;
	}
	lst->funk_name = name;
	lst->caret_size = (*all)->header->prog_size;
	lst->next = NULL;
}

int			ft_serch_label(char *line, int *i, int *j, t_all **all)
{
	int		k;
	char	*name;

	name = NULL;
	while (line[(*j)] && line[(*j)] < 33)
		(*j)++;
	k = *j;
	while (ft_strchr(LABEL_CHARS, (int)line[k]))
		k++;
	if (line[k] >= 65 && line[k] <= 97)
		return (my_erormanager(NULL, ft_tab(*i, *j, 0), 1));
	if (line[k] == LABEL_CHAR)
	{
		name = ft_strnduplen(line, j, k);
		if ((serch_dublikat_label(name, *i, *j, all)) == -1)
		{
			ft_strdel(&name);
			return (-1);
		}
		new_label(name, all);
		(*j)++;
	}
	return (0);
}
