#include "vm.h"

void	dump_map(char *line)
{
	int		i;
	int		k;
	int		j;

	i = -1;
	k = -1;
	j = -1;
	while (++k < 4096)
	{
		i = -1;
		ft_printf("%d:", ++j);
		while (++i < 32)
		{
			ft_printf("%d", (unsigned int)line[k]);
		}
		ft_printf("\n");
	}
}

unsigned int 	is_valid_num(char *arg, char flag)
{
	int		num;

	num = ft_atoi(arg);
	if (num <= 0)
		ft_error("bad numb in input line\n");
	if ((flag == 'n' && num <= MAX_PLAYERS) || flag == 'd')
		return(num);
	else
		ft_error("bad numb of players in input line\n");
	return (num);
}

int 	is_flag(char **args, size_t *i)
{
	if (args[*(i)][0] == '-')
	{
		if (ft_strequ(args[*i], "-v"))
			ft_printf("switch on vizualization");
		else if (ft_strequ(args[*i], "-d"))
			ft_printf("dumps nbr of cycles");
		else if (ft_strequ(args[*i], "-n"))
			ft_printf("adds num to player");
		else
			ft_error("invalid flag"); // proper error message
		return (1);
	}
	return (0);
}

int 	is_champ(char *arg)
{
	int		k;

	k = ft_strlen(arg);
	if (arg[k - 4] == '.' && arg[k - 3] == 'c' && arg[k - 2] == 'o'
		&& arg[k - 1] == 'r' && (arg[k] == '\0' || arg[k] == '\n'))
		return (1);
	else
		return (0);
}

int		validate_champ(unsigned char **line, int i)
{
 	unsigned int	magic;

	magic = (unsigned int)(*line)[0];
	magic = magic << 8;
	magic |= (unsigned int)(*line)[1];
	magic = magic << 8;
	magic |= (unsigned int)(*line)[2];
	magic = magic << 8;
	magic |= (unsigned int)(*line)[3];
	if (!(magic == 15369203))
	{
		ft_error("bad magic\n");
//		return (0);
	}
	magic = (unsigned int)(*line)[136];
	magic = magic << 8;
	magic |= (unsigned int)(*line)[137];
	magic = magic << 8;
	magic |= (unsigned int)(*line)[138];
	magic = magic << 8;
	magic |= (unsigned int)(*line)[139];
	if (!(magic == i - 2192) || magic > 4)
	{
		ft_error("bad prog_size\n");
//		return (0);
	}
	return (1);
}

int 	is_valid_champ(char *arg, char ***champs, size_t j)
{
	int 	fd;
	unsigned char 	*line;
	ssize_t len;

	line = ft_memalloc(2874);
	ft_printf("header: %u\n", 2192); // test
	ft_printf("FILE_MAX_LENGTH: %u\n", 2874); // test
	if (!is_champ(arg))
		ft_error("invalid input\n");
	if (!(*champs))
	{
		*champs = (char **)malloc(sizeof(char*) * (4 + 1));
		*champs[4] = NULL;
	}
	fd = open(arg, O_RDONLY);
	len = read(fd, line, 2874);
	if (fd == -1 || len == -1)
		ft_error("can't read the file\n");
	if (len < 2192)
		ft_error("the size of champion is to small\n");
	if (read(fd, NULL, 1))
		ft_error("the size of champion is to big\n");
	if (validate_champ(&line, len))
	{
		(*champs)[j] = ft_memalloc(len);
		ft_memcpy((*champs)[j], line, len);
	}
	free(line);
	ft_printf("valid champion\n"); // test
	return (1);
}
