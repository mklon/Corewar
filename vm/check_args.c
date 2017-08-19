#include "vm.h"

unsigned int		is_valid_num(char *arg, char flag)
{
	int		num;

	num = ft_atoi(arg);
	if (num <= 0)
		ft_error("bad numb in input line\n");
	if (!((flag == 'n' && num <= MAX_PLAYERS) || flag == 'd'))
		ft_error("bad numb of players in input line\n");
	return((unsigned int)num);
}

int					is_flag(char **args, size_t *i, t_general *gen)
{
	unsigned int	j;

	j = 0;
	if (args[*(i)][0] == '-')
	{
		if (ft_strequ(args[*i], "-v"))
		{
			ft_printf("switch on vizualization\n");
		}
		else if (ft_strequ(args[*i], "-d"))
		{
			if (!args[*i + 1])
				ft_error("Not enough argumets\n");
			gen->dump = is_valid_num(args[++(*i)], 'd');
			ft_printf("dumps %d cycles", gen->dump); // test
		}
		else if (ft_strequ(args[*i], "-n"))
		{
			if (!args[*i + 1] || !args[*i + 2])
				ft_error("Not enough argumets\n");
			if (gen->champ_num == MAX_PLAYERS)
				ft_error("To many champions\n");
			j = is_valid_num(args[++(*i)], 'n');
			(gen->n_flag[j]) ? ft_error("Wrong num of player\n") : 0;
			if (is_champ(args[++(*i)]))
				gen->n_flag[j] = *i;
			else
				ft_error("Wrong type of file (-n flag)\n");
			gen->champ_num++;
			ft_printf("adds num to player\n");	// test
		}
		else
			ft_error("invalid flag\n"); // proper error message
		return (1);
	}
	return (0);
}

int 				is_champ(char *arg)
{
	int		k;

	k = ft_strlen(arg);
	if (arg[k - 4] == '.' && arg[k - 3] == 'c' && arg[k - 2] == 'o'
		&& arg[k - 1] == 'r' && (arg[k] == '\0' || arg[k] == '\n'))
		return (1);
	else
		return (0);
}

int		validate_champ(unsigned char *line, int i)
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
	{
		ft_error("bad magic\n");
//		return (0);
	}
	magic = (unsigned int)line[136];
	magic = magic << 8;
	magic |= (unsigned int)line[137];
	magic = magic << 8;
	magic |= (unsigned int)line[138];
	magic = magic << 8;
	magic |= (unsigned int)line[139];
	if (!(magic == i - PROG_HEADER_LENGTH) || magic > CHAMP_MAX_SIZE)
	{
		ft_error("bad prog_size\n");
//		return (0);
	}
	return (1);
}

void		write_player(t_general *gen, size_t j)
{
	unsigned int	size;
	int				i;
	int				k;

	i = -1;
	size = (unsigned int)(gen->line)[136];
	size = size << 8;
	size |= (unsigned int)(gen->line)[137];
	size = size << 8;
	size |= (unsigned int)(gen->line)[138];
	size = size << 8;
	size |= (unsigned int)(gen->line)[139];
	k = (int)size;
	gen->players[j] = (t_player *)ft_memalloc(sizeof(t_player));
	(gen->players)[j]->name = ft_strdup((char *)gen->line + 4);
	(gen->players)[j]->comment = ft_strdup((char *)gen->line + PROG_NAME_LENGTH + 12);
	(gen->players)[j]->opcode = (unsigned char *)ft_memalloc(k * sizeof(unsigned char));
	(gen->players)[j]->size = (size_t)size;
	while (--k)
		(gen->players)[j]->opcode[++i] = (char)(gen->line)[i + 2192];

	ft_printf("[%d]name = %s\n", j,(gen->players)[j]->name);//delete
	ft_printf("[%d]comment = %s\n", j,(gen->players)[j]->comment);
	ft_printf("[%d]opcode = %s\n", j,(char *)(gen->players)[j]->opcode);
	ft_printf("size = %d\n", (int)size);
	ft_printf("a5=%c\n\n", (char)(gen->line)[4]);
	ft_printf("a6=%c\n\n", (char)(gen->line)[5]);
}

int 	is_valid_champ(char *arg, t_general *gen, size_t j)
{
	int 	fd;
	ssize_t len;

	ft_printf("header: %u\n", PROG_HEADER_LENGTH); // test
	ft_printf("FILE_MAX_LENGTH: %u\n", FILE_MAX_LENGTH); // test
	gen->line = ft_memalloc(FILE_MAX_LENGTH);
	fd = open(arg, O_RDONLY);
	len = read(fd, gen->line, FILE_MAX_LENGTH);
	ft_printf("len: %u\n", len); // test
	if (fd == - 1 || len == -1)
		ft_error("can't read the fi®le\n");
	if (len < PROG_HEADER_LENGTH)
		ft_error("the size of champion is to small\n");
	if (read(fd, NULL, 1))
		ft_error("the size of champion is to big\n");
	if (validate_champ(gen->line, len))
	{
		write_player(gen, j);
		free(gen->line);
		ft_printf("valid champion\n"); // test
	}
	return (1);
}

void				read_players(char **av, t_general *gen)
{
	size_t		j;
	size_t		i;

	j = 0;
	gen->players = (t_player **)ft_memalloc(sizeof(t_player *) * gen->champ_num);
	while (j < gen->champ_num)
	{
		i = gen->n_flag[j + 1];
		if (is_valid_champ(av[i], gen, j))
		{
			gen->players[j]->num = (j + 1) * -1;
			j++;
		}
	}
}
