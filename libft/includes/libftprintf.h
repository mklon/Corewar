/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:10:17 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/01 21:31:55 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ---------------- struct t_magic ---------------------
** print[6] - print order:
**		[0] - ' ', width space;
**		[1] - ' ', '-', '+', '#', sign, space or prefix;
**		[2] - '1' precision or '0' null flag;
**		[3] - '1' there's arg in buf, '0' if arg is 0 for exceptions;
**		[4] - ' ', width space if minus flag;
**	int	w - width;
**	int p - precision;
**	int r - result int;
**	int len - length of buf;
**	char mod: hh = f, h, l, ll = m, z, j;
**	char c - conversion flag ('%' for any other character, 'b' for binary);
**	char *buf - arg converted to str;
**	char *w_str - str with size of each unicode symbol in wide string,
**				  to detect precision later on;
*/

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define FLAG_SKIP(x) (x == ',' || x == ':' || x == ';' || x == '_')
# define FLAG_SIG(x) (x == '-' || x == '#' || x == '+' || x == ' '|| x == '.')
# define FLAG_SIG2(x) (x == '*')
# define FLAG_NUM(x) (x >= '0' && x <= '9')
# define FLAG_MOD(x) (x == 'h' || x == 'l' || x == 'z' || x == 'j')
# define FLAG_U(x) (x == 'u' || x == 'U' || x == 'b')
# define FLAG_I(x) (x == 'i' || x == 'd' || x == 'D')
# define FLAG_C(x) (x == 's' || x == 'S' || x == 'c' || x == 'C')
# define FLAG_X(x)  (x == 'o' || x == 'O' || x == 'x' || x == 'X')
# define FLAG_P(x) (x == 'p')
# define FLAG_PER(x) (x == '%')
# define FLAG_CON(x) (FLAG_U(x) || FLAG_I(x) || FLAG_C(x) || FLAG_X(x))
# define FLAG_XI(x) (FLAG_I(x) || FLAG_X(x))
# define FLAG_DIGIT(x) (FLAG_I(x) || FLAG_X(x) || FLAG_U(x))
# define BASE 10
# define PRINT 6
# define A(x) (x < 0) ? (-x) : (x)

typedef struct	s_magic
{
	char		print[6];
	int			w;
	int			p;
	int			r;
	int			len;
	char		mod;
	char		c;
	char		*buf;
}				t_magic;

int				ft_printf(const char *format, ...);
t_magic			*get_it(const char **fr, va_list ap, t_magic *m);
const char		*put_txt(const char *fr, int *ret);
const char		*skip_flags(const char *fr, char *fl);
char			get_mod(char fr, char fl);

t_magic			*init_struct(void);
void			clear_struct(t_magic *m, char fl);
void			del_struct(t_magic **m);

void			conv_arg(va_list ap, t_magic *m);
void			conv_unsigned(void *arg, t_magic *m);
void			conv_signed(void *arg, t_magic *m);
void			conv_char(void *arg, t_magic *m);
int				size_wchar(wchar_t w);
void			wstr_conv(wchar_t *arg, t_magic *m);
char			*wchar_conv(wchar_t w);

int				get_base(char c);
void			itoa_base(uintmax_t value, int base, t_magic *m);
void			itoa_int(intmax_t value, t_magic *m);

void			parce_it(const char *fr, size_t l, t_magic *m, va_list ap);
int				atoi_num(const char **fr);
void			parce_if_digit(char fr, t_magic *m);
void			clear_print(t_magic *m);

void			print_it(t_magic *m);
void			len_print(t_magic *m);
int				get_hash(t_magic *m);
void			print_0(t_magic *m);
void			print_1(t_magic *m);
void			print_2(t_magic *m);
void			print_3(t_magic *m);
void			print_str(t_magic *m, int l);
void			print_char(char c, t_magic *m);

#endif
