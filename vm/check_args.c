#include "vm.h"

int 	is_flag(char **args, int *i)
{
	if (args[*(i)][0] == '-')
	{
		ft_printf("%c", args[*i][0]);
		if (ft_strequ(args[*i], "-v"))
			ft_printf("switch on vizualization");
		else if (ft_strequ(args[*i], "-d"))
			ft_printf("dumps nbr of cycles");
		else if (ft_strequ(args[*i], "-n"))
			ft_printf("adds num to player");
		else
		{
			write(1, "wrong flag", 10);
			return (0);
		}
	}
	return (1);
}

int 	is_champ(char *arg)
{

	return (1);
}

int 	get_champ(char *arg, char ***champs, size_t j)
{


	return (1);
}
