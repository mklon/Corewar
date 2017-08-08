#include "vm.h"

int 	ft_error(char *message)
{

	write(2, message, ft_strlen(message));
	exit(1);
}
