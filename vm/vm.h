#ifndef VM_H
# define VM_H

# include "../op.h"
# include <stdint.h>

typedef struct s_general	t_general;
typedef struct s_player		t_player;

struct		s_general
{
	unsigned char		*field;
	unsigned int		total_cycles;
	unsigned int		process;
	unsigned int		cycle_to_die;
	unsigned int		cycle_delta;
	unsigned int		nbr_live;
	unsigned int		live_checks;
	int					dump;
	t_player			**players;
	int					champ_num;
	size_t				n_flag[MAX_PLAYERS + 1];
	size_t				no_flag[MAX_PLAYERS + 1];
};

struct	s_player
{
	unsigned char	*name;
	unsigned char	*comment;
	unsigned char	*opcode;
	int 			size;
	int 			num;
	unsigned int	last_live;
	unsigned int	nbr_lives;
};

void		ft_usage(void);
int			ft_error(char *message);
void		read_args(int ar, char **av, t_general *gen);
int			is_flag(char **args, size_t *i, t_general *gen);
int			is_valid_champ(char *arg);
int			is_champ(char *arg);
int			validate_champ(unsigned char **line, int i);
t_general	*gen_init(void);
void		write_to_map(t_general *gen);
void		dump_map(unsigned char *line);
void		read_players(char **av, t_general *gen);

#endif
