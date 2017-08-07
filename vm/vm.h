#ifndef VM_H
# define VM_H

#include "../op.h"

void	ft_usage(void);
int 	ft_error(char *message);
//int 	check_magic(char *av);
int 	is_flag(char **args, int *i);
int 	is_champ(char *arg);
int 	get_champ(char *arg, char ***champs, size_t j);


#endif