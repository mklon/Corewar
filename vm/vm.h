#ifndef VM_H
# define VM_H

#include "../op.h"
#include <stdint.h>

typedef struct s_general	t_general;

struct		s_general
{
	unsigned char	*field;
	unsigned int	total_cycles;
    unsigned int    process;
	unsigned int	cycle_to_die;
	unsigned int	nbr_lives;
	unsigned int	last_live;
	int		dump;
	unsigned char		**champs;
    int             champ_num;
//    unsigned int    ;
//    unsigned int    ;
};

void	ft_usage(void);
int 	ft_error(char *message);
void	read_args(int ar, char **av, t_general *gen);
int 	is_flag(char **args, size_t *i, t_general *gen);
int 	is_valid_champ(char *arg, char ***champs, size_t j);
int 	is_champ(char *arg);
int		validate_champ(unsigned char **line, int i);
t_general   *gen_init(void);

#endif
