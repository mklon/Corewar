#ifndef VM_H
# define VM_H

# include "../op.h"
# include <stdint.h>

typedef struct s_general	t_general;
typedef struct s_player		t_player;
typedef struct s_process	t_process;
typedef struct s_op			t_op;

struct				s_general
{
//	unsigned char	field[MEM_SIZE];
	unsigned char	*field;
	unsigned int	total_cycles;
	unsigned int	current_cycles;
	unsigned int	nbr_process;
	int				cycle_to_die;
	unsigned int	live_per_period;
	unsigned int	live_checks;
	int				dump;
	int				visual;
	int				pause;
	t_player		**players;
	int				champ_num;
	int				game_over; //processing
	int				winner; //last reported alive
	size_t			n_flag[MAX_PLAYERS + 1];
	size_t			no_flag[MAX_PLAYERS + 1];
	unsigned char	*line;
	t_process		*process; //processing
};

struct				s_player
{
	char			*name;
	char			*comment;
	unsigned char	*opcode;
	size_t			size;
	int				num;
	unsigned int	last_live;
	unsigned int	declared_live;
};

struct				s_process //processing
{
	size_t			pc;
	char			carry;
	int				reg[REG_NUMBER + 1];
	unsigned int	live;
	int				on_hold;
	t_process		*next;
};

struct				s_op
{
	void			(*f)(t_general *gen, t_process *current, int op_num, int *args);
	int				nbr_arg;
	int				arg[MAX_ARGS_NUMBER];
	int				op_code;
	int				cycle;
	int				coding_byte;
	int				flag_direct_size;
};

t_op op[17];

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

void				check_lives(t_general *gen);
void				process(t_general *gen);
void				new_process(t_process *parent, t_process **head);
size_t				kill_process(t_process **head);

void				fetch(t_general *gen, t_process *process, int op_num);
void				fetch_args(unsigned char *field, t_process *proc, int op_num, int **args);
int					check_cod_byte(int op_num, unsigned char codbyte, int *step, int *args);
int					validate_cod_byte(int op_num, int *args);

void				live_op(t_general *gen, t_process *process, int op_num, int *args);
void				ld_op(t_general *gen, t_process *process, int op_num, int *args);
void				st_op(t_general *gen, t_process *process, int op_num, int *args);
void				add_op(t_general *gen, t_process *process, int op_num, int *args);
void				sub_op(t_general *gen, t_process *process, int op_num, int *args);
void				and_op(t_general *gen, t_process *process, int op_num, int *args);
void				or_op(t_general *gen, t_process *process, int op_num, int *args);
void				xor_op(t_general *gen, t_process *process, int op_num, int *args);
void				zjmp_op(t_general *gen, t_process *process, int op_num, int *args);
void				ldi_op(t_general *gen, t_process *process, int op_num, int *args);
void				sti_op(t_general *gen, t_process *process, int op_num, int *args);
void				fork_op(t_general *gen, t_process *process, int op_num, int *args);
void				lld_op(t_general *gen, t_process *process, int op_num, int *args);
void				lldi_op(t_general *gen, t_process *process, int op_num, int *args);
void				lfork_op(t_general *gen, t_process *process, int op_num, int *args);
void				aff_op(t_general *gen, t_process *process, int op_num, int *args);

#endif
