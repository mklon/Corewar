/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amovchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:47:52 by amovchan          #+#    #+#             */
/*   Updated: 2017/09/14 20:56:28 by amovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <wchar.h>
# include <stdlib.h>
# include <inttypes.h>
# include <stdarg.h>

# define A(x) (x < 0 ? -(x) : x)
# define BUFF_SIZE 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_srt
{
	char			letar;
	char			zero_or_minus;
	char			plus;
	char			space;
	int				hesh;
	int				size;
	int				accur;
	int				width;
	int				rs;
	int				fd;
	int				ap;
	int				dolar;
	int				color;
	char			chr;
}					t_srt;

void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memcpy_rev(void *dst, const void *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_itoa(int n);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *little,
								size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_atoi(const char *str);
int					ft_isspace(int c);
int					ft_len_int(int n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_nb_words(char const *str, char c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isnegativ(int n);
int					ft_ln_w(char const *str, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
size_t				ft_lst_len(t_list *lst);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_printf(const char *format, ...);
int					ft_format(const char *format, va_list ap);
t_srt				*inicial_struct(t_srt *lst);
t_srt				*ft_print_format(t_srt *lst, const char *str,
						int *i, va_list ap);
int					atoidig(const char *str, int *i);
void				ft_specifiers(const char *str, int *i, t_srt *list);
int					flag_format(char c, t_srt *lst);
int					add_dot(const char *str, int *i, t_srt *lst, va_list ap);
void				ft_color(const char *s, int *i, va_list ap, t_srt *lst);
void				ft_color_print(char *str, t_srt *lst);
int					tayp(char c);
intmax_t			signed_size(va_list ap, t_srt *lst);
uintmax_t			unsigned_size(va_list ap, t_srt *lst);
char				*ft_getdouble(va_list ap, t_srt *lst);
char				*ft_getstr(va_list ap, t_srt *lst);
char				*ft_cast_f(va_list ap, t_srt *lst);
char				*ft_cast_e(va_list ap, t_srt *lst);
char				*ft_cast_el(va_list ap, t_srt *lst);
char				*ft_cast_gi(va_list ap, t_srt *lst);
char				*ft_cast_a(va_list ap, t_srt *lst);
char				*ft_str_dable_a(long double nb, int len, t_srt *lst);
char				*ft_str_zero(long double nb, t_srt *lst, char *s);
void				ft_ppp(char *c, char *b);
char				*ft_okrug_a(char *str);
char				*ft_zero(int len);
char				ft_char(int a);
long double			rang(long double nb, int *i);
char				*ft_strs(char *s, int *i, int nb);
char				*ft_pow_a(int pow);
char				*ft_getstr_a(long double nb, t_srt *lst);
char				*ft_str_double(long double nb, t_srt *lst);
char				*ft_okrug(long double nb, t_srt *lst);
char				*ft_cast(char *s1, char *s2);
char				*ft_pow(long double	nb, int len);
char				*ft_cast_al(va_list ap, t_srt *lst);
char				*ft_get_str_e(long double nb, t_srt *lst);
char				*ft_plus(char *str, t_srt *lst);
char				*ft_width(char *str, t_srt *lst);
char				*ft_accur(char *str, t_srt *lst);
char				*get_str(va_list ap, t_srt *lst);
int					ft_print(t_srt *lst, va_list ap, va_list tmp);
long double			ft_r_nbr(long double nbr);
char				*ft_strcpy_rev(char *s1, char *s2, char c, int j);
char				*ft_itoa_base(uintmax_t nb, int base);
char				*ft_accur_digits(char *str, t_srt *lst);
char				*ft_strhesh(char *str, t_srt *lst);
char				*ft_cast_unsigned(va_list ap, t_srt *lst, int base);
char				*ft_cast_long(va_list ap, t_srt *lst, int base);
char				*ft_cast_dl(va_list ap, t_srt *lst);
char				*ft_cast_di(va_list ap, t_srt *lst);
char				*ft_space(char *str, char c, int len, t_srt *slt);
char				*ft_cast_xl(va_list ap, t_srt *lst);
char				*itoa(long long int n);
char				*ft_strcast_p(va_list ap, t_srt *lst);
char				*ft_print_wchar_str(va_list ap, t_srt *lst);
char				*ft_cest_str(va_list ap, t_srt *lst);
void				ft_print_wchar(wchar_t c, char *str, int *i, int *len);
int					ft_cast_char(va_list ap, t_srt *lst);
int					ft_len_wchar(wchar_t *str);
char				*ft_apostroph(char *str, t_srt *lst);
void				ft_argn(int len, va_list ap, t_srt *lst);
long double			rang_e(long double nb, int *i);
char				*ft_getpow(int i);
char				*ft_str_g(va_list ap, t_srt *lst);
int					ft_printformat(const char *str, int *i,
						t_srt *lst, va_list ap);
void				ft_width_or_dolar(const char *str, int *i, t_srt *lst);
char				*ft_plus2(char *str, t_srt *lst);
char				*ft_strcpychar(char *s1, char *s2, int j, char c);
char				*ft_str_dable_a2(long double nb,
						int len, t_srt *lst, int i);
void				ft_ppp2(char *c, char *b);
char				*ft_getstr_a2(long double nb, t_srt *lst);
char				*ft_strs2(char *s, int *i, int nb);
char				*ft_pow_a2(int pow);
char				ft_char2(int a);
char				*ft_str_zero2(long double nb, t_srt *lst, char *s);
char				*ft_okrug_a2(char *str);
char				*ft_castnegativ(intmax_t nbr, t_srt *lst);
char				*ft_castb(va_list ap, t_srt *lst);
int					get_next_line(const int fd, char **line);
char				*ft_strndup(char *str, size_t len);
char				*ft_strnjoin(char const *s1, char const *s2, size_t len);

#endif
