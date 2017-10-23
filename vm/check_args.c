/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:08:31 by msymkany          #+#    #+#             */
/*   Updated: 2017/10/12 13:08:33 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		is_valid_num(char *arg, char flag)
{
	int		num;

	num = ft_atoi(arg);
	if (num <= 0)
		ft_error("Wrong number after flag in input line\n");
	if (!((flag == 'n' && num <= MAX_PLAYERS) || flag == 'd'))
		ft_error("Wrong number of players in input line\n");
	return (num);
}

int		validate_champ(unsigned char *line, size_t i)
{
	unsigned int	magic;

	magic = (unsigned int)line[0];
	magic = magic << 8;
	magic |= (unsigned int)line[1];
	magic = magic << 8;
	magic |= (unsigned int)line[2];
	magic = magic << 8;
	magic |= (unsigned int)line[3];
	if (!(magic == COREWAR_EXEC_MAGIC))
		ft_error("Wrong magic number\n");
	magic = (unsigned int)line[136];
	magic = magic << 8;
	magic |= (unsigned int)line[137];
	magic = magic << 8;
	magic |= (unsigned int)line[138];
	magic = magic << 8;
	magic |= (unsigned int)line[139];
	if (!(magic == i - PROG_HEADER_LENGTH) || magic > CHAMP_MAX_SIZE)
		ft_error("Program size mismatch\n");
	return (1);
}

int		is_valid_champ(char *arg, t_general *gen, size_t j)
{
	int		fd;
	ssize_t	len;

	gen->line = ft_memalloc(FILE_MAX_LENGTH);
	fd = open(arg, O_RDONLY);
	len = read(fd, gen->line, FILE_MAX_LENGTH);
	if (fd == -1 || len == -1)
		ft_error("can't read the file\n");
	if (len < PROG_HEADER_LENGTH)
		ft_error("the size of champion is to small\n");
	if (read(fd, NULL, 1))
		ft_error("the size of champion is to big\n");
	if (validate_champ(gen->line, len))
	{
		write_player(gen, j);
		free(gen->line);
		gen->line = NULL;
	}
	return (1);
}

void	write_player(t_general *g, size_t j)
{
	unsigned int	size;
	int				i;
	int				k;

	i = 0;
	size = (unsigned int)(g->line)[136];
	size = size << 8;
	size |= (unsigned int)(g->line)[137];
	size = size << 8;
	size |= (unsigned int)(g->line)[138];
	size = size << 8;
	size |= (unsigned int)(g->line)[139];
	k = (int)size;
	g->players[j] = (t_player *)ft_memalloc(sizeof(t_player));
	(g->players)[j]->size = (size_t)size;
	(g->players)[j]->name = ft_strdup((char *)g->line + 4);
	(g->players)[j]->comment =
			ft_strdup((char *)g->line + PROG_NAME_LENGTH + 12);
	(g->players)[j]->opcode =
			(unsigned char *)ft_memalloc((k) * sizeof(unsigned char));
	while (k--)
	{
		(g->players)[j]->opcode[i] = (char)(g->line)[i + PROG_HEADER_LENGTH];
		i++;
	}
}

void	read_players(char **av, t_general *gen)
{
	size_t		j;
	size_t		i;

	j = 0;
	gen->players = (t_player **)malloc(sizeof(t_player *) * gen->champ_num);
	while (j < gen->champ_num)
	{
		i = gen->n_flag[j + 1];
		if (is_valid_champ(av[i], gen, j))
		{
			gen->players[j]->num = -1 * (j + 1);
			j++;
		}
	}
}
