#include "vm.h"

unsigned int 	is_valid_num(char *arg, char flag)
{
	return(num);
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
	if (!(magic == COREWAR_EXEC_MAGIC))
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
	if (!(magic == i - PROG_HEADER_LENGTH) || magic > CHAMP_MAX_SIZE)
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

	line = ft_memalloc(FILE_MAX_LENGTH);
	ft_printf("header: %u\n", PROG_HEADER_LENGTH); // test
	ft_printf("FILE_MAX_LENGTH: %u\n", FILE_MAX_LENGTH); // test
	if (!is_champ(arg))
		ft_error("invalid input\n");
	if (!(*champs))
	{
		*champs = (char **)malloc(sizeof(char*) * (MAX_PLAYERS + 1));
		*champs[MAX_PLAYERS] = NULL;
	}
	fd = open(arg, O_RDONLY);
	len = read(fd, line, FILE_MAX_LENGTH);
	if (fd == -1 || len == -1)
		ft_error("can't read the file\n");
	if (len < PROG_HEADER_LENGTH)
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
