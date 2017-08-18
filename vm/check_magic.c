#include "vm.h"
#include <stdio.h>

int 	check_magic(char *av)
{
	unsigned char *mag;
	int fd;
	unsigned int magic;
	int i;

//	magic = 0;
	mag = ft_memalloc(4);
	fd = open(av, O_RDONLY);
	read(fd, mag, 4);
//	magic = (unsigned int *)mag;

	magic = (unsigned int)mag[1];
	magic = magic << 8;
	magic |= (unsigned int)mag[2];
	magic = magic << 8;
	magic |= (unsigned int)mag[3];

	i = COREWAR_EXEC_MAGIC;

	printf("magic: %u", magic);
	return (0);
}
