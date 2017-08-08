#include "../op.h"

void	ft_error(char *s)
{
	write(1, "\033[0;31mERROR: ", ft_strlen("\033[0;31mERROR: "));
	write(1, s, ft_strlen(s));
	write(1, "\033[;0m", ft_strlen("\033[;0m"));
	exit(1);
}

int		validate_champ(char *av)//(char **line, int i)
{
	unsigned char *mag;
	int fd;
	unsigned int magic;
//int i = 2215;//for zork.cor
int i = 2216;

	mag = ft_memalloc(2200);
	fd = open(av, O_RDONLY);
	read(fd, mag, 2192);

	magic = (unsigned int)mag[1];
	magic = magic << 8;
	magic |= (unsigned int)mag[2];
	magic = magic << 8;
	magic |= (unsigned int)mag[3];
	printf("magic: %u\n", magic);
	if (!((unsigned int)magic == 15369203))
	{
		ft_error("bad magic\n");
		return (0);
	}
	magic = (unsigned int)mag[136];
	magic = magic << 8;
	magic |= (unsigned int)mag[137];
	magic = magic << 8;
	magic |= (unsigned int)mag[138];
	magic = magic << 8;
	magic |= (unsigned int)mag[139];
	if (!((unsigned int)magic == i - 2192))
	{
	printf("i - 2192: %d\n", (i - 2192));
	printf("magic: %u\n", magic);

		ft_error("bad prog_size\n");
		return (0);
	}
	return (1);
}

// void	read_error(char *line)
// {

// }

// int		validate_champ(char **line, int i)
// {
// 	unsigned int	magic;

// 	magic = (unsigned int)*line[1];
// 	magic = magic << 8;
// 	magic |= (unsigned int)*line[2];
// 	magic = magic << 8;
// 	magic |= (unsigned int)*line[3];
// 	if (!((unsigned int)magic == 15369203))
// 	{
// 		ft_error("bad magic\n");
// 		return (0);
// 	}
// 	magic = (unsigned int)*line[136];
// 	magic = magic << 8;
// 	magic |= (unsigned int)*line[137];
// 	magic = magic << 8;
// 	magic |= (unsigned int)*line[138];
// 	magic = magic << 8;
// 	magic |= (unsigned int)*line[139];
// 	if (!((unsigned int)magic == i - 2192))
// 	{
// 		ft_error("bad prog_size\n");
// 		return (0);
// 	}
// 	return (1);
// }
