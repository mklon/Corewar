/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_into_bytcode.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:11:56 by amovchan          #+#    #+#             */
/*   Updated: 2017/10/13 16:49:57 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_coment(char *line)
{
	int		i;

	i = -1;
	while (line[++i] && line[i] < 33)
		;
	if (line[i] == COMMENT_CHAR || line[i] == ';' || line[i] == '\0')
	{
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

static int	ft_cmp_namne_comment(char **src)
{
	char	*str;
	int		i;

	str = *src;
	i = -1;
	if (!str || str[0] == '\0')
		return (1);
	while (*str && *str < 33)
		str++;
	if (!ft_strncmp(str, NAME_CMD_STRING, 5) ||
			!ft_strncmp(str, COMMENT_CMD_STRING, 8))
		return (0);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			break ;
	}
	if (str[i] != '\0')
		return (1);
	else
		return (0);
}

static int	ft_last_test(char **line, int fd, t_all **all)
{
	if (ft_cmp_namne_comment(line))
	{
		ft_strdel(line);
		if (last_byt(fd) == -1)
			return (-1);
	}
	ft_strdel(line);
	if (ft_search_availability_label(all) == -1)
		return (-1);
	return (0);
}

int			translation_into_bytcode(int fd, int *i, char *line, t_all **all)
{
	int		j;

	while (get_next_line(fd, &line) > 0)
	{
		(*i)++;
		j = 0;
		line = serch_coment(line);
		if (ft_coment(line))
			continue ;
		if (!ft_cmp_namne_comment(&line) && (*all)->header->prog_size > 0)
			break ;
		if (ft_serch_label(line, i, &j, all) == -1 ||
				ft_instruction(line, i, &j, all) == -1)
		{
			ft_strdel(&line);
			return (-1);
		}
		ft_strdel(&line);
	}
	if (ft_last_test(&line, fd, all) == -1)
		return (-1);
	return (1);
}
