#ifndef VM_H
# define VM_H

# include "../op.h"
# include <stdint.h>

typedef struct s_general	t_general;
typedef struct s_player		t_player;
typedef struct s_process	t_process;

struct				s_general
{
//	unsigned char	field[MEM_SIZE];
	unsigned char	*field;
	unsigned int	total_cycles;
	unsigned int	current_cycles;
	unsigned int	process;
	unsigned int	cycle_to_die;
	unsigned int	cycle_delta;
	unsigned int	nbr_live;
	unsigned int	live_checks;
	int				dump;
	t_player		**players;
	int				champ_num;
	int				winner; //processing
	size_t			n_flag[MAX_PLAYERS + 1];
	size_t			no_flag[MAX_PLAYERS + 1];
	unsigned char	*line;
};

struct				s_player
{
	char			*name;
	char			*comment;
	unsigned char	*opcode;
	size_t			size;
	int				num;
	unsigned int	last_live;
	unsigned int	nbr_lives;
	t_process		process; //processing
};

struct				s_process //processing
{
	size_t			pc;
	char			carry;
	int				reg[REG_NUMBER];
	unsigned int	live;
	t_process		next;
};

void				ft_usage(void);
int					ft_error(char *message);
void				read_args(int ar, char **av, t_general *gen);
int					is_flag(char **args, size_t *i, t_general *gen);
void				is_n_flag(char **args, size_t *i, t_general *gen);
int					is_valid_champ(char *arg, t_general *gen, size_t j);
int					is_champ(char *arg);
int					validate_champ(unsigned char *line, int i);
int					is_valid_num(char *arg, char flag);
t_general			*gen_init(void);
void				read_players(char **av, t_general *gen);
void				write_player(t_general *gen, size_t j);

void				write_to_map(t_general *gen);
void				dump_map(unsigned char *line);

#endif
