/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:45:22 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 20:45:26 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "op.h"
# define BYTE 8

typedef	struct		s_stak
{
	char			*funk_name;
	unsigned int	caret_size;
	struct s_stak	*next;
}					t_stak;

typedef struct		s_prog
{
	int				i;
	char			*label1;
	char			*label2;
	char			*label3;
	int				i_j[2];
	int				value[MAX_ARGS_NUMBER];
	unsigned int	caret;
	int				coding_byte;
	int				arg[MAX_ARGS_NUMBER];
	struct s_prog	*next;
}					t_prog;

typedef struct		s_all
{
	int				flag_name;
	int				flag_commet;
	t_prog			*prog;
	t_stak			*stak;
	t_header		*header;
}					t_all;

int					ft_compiler(char *str, char *name);
int					my_erormanager(char *str, int *tab, int error);
int					*ft_tab(int i, int j, int k);
int					translation_into_bytcode(int fd,
									int *i, char *line, t_all **all);
int					ft_serch_label(char *line, int *i, int *j, t_all **all);
char				*ft_strnduplen(char *str, int *start, int finish);
int					ft_instruction(char *line, int *i, int *j, t_all **all);
int					ft_argument(char *line, int *i, int *j, t_all **all);
int					valid_direkt(char *str, int *i, int *j, t_prog **prog);
int					valid_registr(char *str, int *tab, int *j, t_prog **prog);
int					valid_indir(char *str, int *tab, int *j, t_prog **prog);
int					ft_coding_byt(t_prog *prog);
unsigned int		ft_size_program(t_prog *prog);
int					ft_search_availability_label(t_all **all);
void				ft_write_program(t_all *all, char *str);
int					ft_coment(char *line);
int					name_and_coment(int fd, int *i, t_all **all);
char				*serch_coment(char *lin);
void				ft_dell_all(t_all **all);
int					ft_islabel(char *str, int *i, int *j, t_prog **prog);
int					last_byt(int fd);
int					ft_stop_valod(char **line, t_all *all);
int					ft_out_space(char *str, int i);

#endif
