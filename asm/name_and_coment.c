/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_and_coment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:45:59 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 18:46:05 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_search_name_or_coment(char *lin, char **name, int fd, int *tab)
{
	int		k;

	k = -1;
	while (lin[tab[0]] != '"')
	{
		(*name)[++k] = lin[tab[0]];
		if (k == tab[2])
		{
			free(tab);
			return (my_erormanager("", ft_tab(0, 0, 0), 8));
		}
		tab[0]++;
		if (lin[tab[0]] == '\0')
		{
			ft_strdel(&lin);
			get_next_line(fd, &lin);
			tab[1]++;
			tab[0] = 0;
		}
	}
	tab[0]++;
	while (lin[tab[0]] && lin[tab[0]] < 33)
		tab[0]++;
	return (0);
}

static int	ft_valid_name(char *lin, int *i, int fd, t_all **all)
{
	char	*name;
	int		j;
	int		*tab;

	j = 0;
	name = (*all)->header->prog_name;
	while (lin[j] && lin[j] < 33)
		j++;
	j += ft_strlen(NAME_CMD_STRING);
	while (lin[j] && lin[j] < 33)
		j++;
	if (lin[j] != '"')
		return (my_erormanager("", ft_tab(*i, j, 0), 1));
	j++;
	tab = ft_tab(j, *i, PROG_NAME_LENGTH);
	if (ft_search_name_or_coment(lin, &name, fd, tab) == -1)
		return (-1);
	*i = tab[1];
	j = tab[0];
	free(tab);
	if (lin[j] != '\0' && lin[j] != '#' && lin[j] != ';')
		return (my_erormanager(lin + j, ft_tab(*i, j, 1), 2));
	return (0);
}

static int	ft_valid_coment(char *lin, int *i, int fd, t_all **all)
{
	char	*name;
	int		j;
	int		*tab;

	j = 0;
	name = (*all)->header->comment;
	while (lin[j] && lin[j] < 33)
		j++;
	j += ft_strlen(COMMENT_CMD_STRING);
	while (lin[j] && lin[j] < 33)
		j++;
	if (lin[j] != '"')
		return (my_erormanager("", ft_tab(*i, j, 0), 1));
	j++;
	tab = ft_tab(j, *i, COMMENT_LENGTH);
	if (ft_search_name_or_coment(lin, &name, fd, tab) == -1)
		return (-1);
	*i = tab[1];
	j = tab[0];
	free(tab);
	if (lin[j] != '\0' && lin[j] != '#' && lin[j] != ';')
		return (my_erormanager(lin + j, ft_tab(*i, j, 1), 2));
	return (0);
}

static int	name_or_comment(char *line, int fd, int *i, t_all **all)
{
	int		j;

	j = 0;
	while (line[j] && line[j] < 33)
		j++;
	if (!ft_strncmp(line + j, NAME_CMD_STRING, 5))
	{
		if (ft_valid_name(line, i, fd, all) == -1)
			return (-1);
	}
	else if (!ft_strncmp(line + j, COMMENT_CMD_STRING, 8))
	{
		if (ft_valid_coment(line, i, fd, all) == -1)
			return (-1);
	}
	else
		return (my_erormanager(line, ft_tab(*i, j, 0), 9));
	return (0);
}

int			name_and_coment(int fd, int *i, t_all **all)
{
	char	*line;
	int		stop;

	stop = 0;
	while (get_next_line(fd, &line) > 0)
	{
		(*i)++;
		if (ft_coment(line))
			continue ;
		if (name_or_comment(line, fd, i, all) == -1)
		{
			ft_strdel(&line);
			return (-1);
		}
		stop++;
		ft_strdel(&line);
		if (stop == 2)
			break ;
	}
	return (1);
}
