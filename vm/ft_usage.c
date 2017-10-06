
#include "../op.h"

void	ft_usage(void)
{
	ft_printf("\n");
	ft_printf("Usage: ./corewar [-d N | -v] [-a] [[-n N] <champion1.cor>] <champion1.cor> <...>\n");
	ft_printf("    -a        : Prints output from \"aff\" (Default is to hide it)\n");
	ft_printf("    -d N      : Dumps memory after N cycles then exits\n");
	ft_printf("    -v        : Ncurses output mode\n");
	ft_printf("    -n N      : sets the number N of the next player\n");
	ft_printf("\n");
	exit(0);
}
