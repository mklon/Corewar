#include "vm.h"

int 	ft_error(char *message)
{
	write(2, message, sizeof(message));
	write(1, message, sizeof(message));
	exit(1);
}
