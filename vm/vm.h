#ifndef VM_H
# define VM_H

#include "../op.h"

typedef struct s_general	t_general;

struct		s_general
{
	char	*field;
	unsigned int	total_cycles;
	unsigned int	cycle_to_die;
	unsigned int	nbr_lives;
	unsigned int	last_live;
	unsigned int	dump;
	char		**champs;


};

void	ft_usage(void);
int 	ft_error(char *message);
int 	is_flag(char **args, size_t *i);
int 	is_valid_champ(char *arg, char ***champs, size_t j);
int 	is_champ(char *arg);
int		validate_champ(unsigned char **line, int i);

#endif