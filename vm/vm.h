/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:37:40 by msymkany          #+#    #+#             */
/*   Updated: 2017/10/12 13:37:46 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../op.h"
# include <stdint.h>
# include <ncurses.h>
# include <unistd.h>

typedef struct s_general	t_general;
typedef struct s_player		t_player;
typedef struct s_process	t_process;
typedef struct s_op			t_op;

struct				s_general
{
	WINDOW			*map;
	WINDOW			*text;
	WINDOW			*board;
	t_player		**players;
	unsigned char	*line;
	t_process		*process;
	unsigned char	field[MEM_SIZE];
	unsigned char	colors[MEM_SIZE];
	unsigned char	holdup[MEM_SIZE];
	size_t			n_flag[MAX_PLAYERS + 1];
	size_t			no_flag[MAX_PLAYERS + 1];
	unsigned int	total_cycles;
	unsigned int	current_cycles;
	unsigned int	total_process;
	unsigned int	nbr_process;
	unsigned int	live_per_period;
	unsigned int	live_checks;
	unsigned int	champ_num;
	int				cycle_to_die;
	int				dump;
	int				aff;
	int				debug;
	int				visual;
	int				pause;
	int				limit;
	int				mark;
	int				low;
	int				game_over;
	int				winner;
	int				alive;
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

struct				s_process
{
	t_process		*next;
	uint32_t		reg[REG_NUMBER + 1];
	uint32_t		pc;
	uint32_t		live;
	uint32_t		num;
	int				op_num;
	int				on_hold;
	int				color;
	char			carry;
};

struct				s_op
{
	void			(*f)(t_general *gen, t_process *current,
						int op_num, uint32_t *args);
	size_t			nbr_arg;
	int				arg[MAX_ARGS_NUMBER];
	int				op_code;
	int				cycle;
	int				coding_byte;
	int				flag_direct_size;
};

t_op g_op[17];

void				ft_usage(void);
int					ft_error(char *message);
void				read_args(int ar, char **av, t_general *gen);
int					is_flag(char **args, size_t *i, t_general *gen);
void				is_n_flag(char **args, size_t *i, t_general *gen);
int					is_valid_champ(char *arg, t_general *gen, size_t j);
int					is_champ(char *arg);
int					validate_champ(unsigned char *line, size_t i);
int					is_valid_num(char *arg, char flag);
t_general			*gen_init(void);
void				read_players(char **av, t_general *gen);
void				write_player(t_general *g, size_t j);

void				write_to_map(t_general *gen);
void				dump_map(unsigned char *line);

void				check_lives(t_general *gen);
void				process(t_general *gen);
void				new_process(t_process *parent, t_process **head,
								uint32_t arg, int idx);
size_t				kill_process(t_general *gen);

uint32_t			check_pc(size_t pc);
void				fetch(t_general *gen, t_process *process, int op_num);
int					check_cod_byte(int op_num, unsigned char codbyte,
								size_t *step, uint32_t *args);
int					validate_cod_byte(int op_num, uint32_t *args);

void				uncode_args(unsigned char *field, t_process *proc,
								int op_num, uint32_t *ar);

uint32_t			convert_arg(unsigned char *field, size_t *curr,
								size_t size);
void				args_copy(uint32_t *args, uint32_t *args_val,
								size_t nbr_arg);
void				live_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				ld_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				st_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				add_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				sub_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				and_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				or_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				xor_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				zjmp_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				ldi_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				sti_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				fork_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				lld_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				lldi_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				lfork_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);
void				aff_op(t_general *gen, t_process *process,
								int op_num, uint32_t *args);

void				put_numb_on_field(t_general *gen, size_t copy_pc,
								int args, int colors);
int					val_reg(uint32_t type, uint32_t value);

/*
**			visual part
*/

/*
** v_first.c
*/
void				visual_init(t_general *gen);
void				start_graph(void);
void				draw_border(void);
void				color_init(void);
int					kbhit(void);

/*
** v_second.c
*/
void				initial_info(t_general *gen);
void				players_info(t_general *gen);
void				map_display(t_general *gen, int i, int j);

/*
** v_third.c
*/
void				pc_color_up(t_general *gen);
void				winner(t_general *gen);
void				limit_handel(t_general *gen, char c);
void				visual_apd(t_general *gen);
int					pressing(t_general *gen);

/*
** v_fourth.c
*/
void				scroll_tool(t_general *gen, int i, int sum);
void				scroll_loop(t_general *gen, int *array);
void				scroll_down(t_general *gen, int *array);

/*
** v_fifth.c
*/
int					scroll_check(t_general *gen);
void				print_symbol(t_general *gen, char c, int i);
void				pc_color_down(t_general *gen, size_t i);
void				scroll_array(t_general *gen, int *array, int *m);
void				holdup_decrease(t_general *gen);

#endif
