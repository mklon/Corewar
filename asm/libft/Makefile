#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amovchan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 14:47:27 by amovchan          #+#    #+#              #
#    Updated: 2017/04/25 17:04:00 by amovchan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FLAG = -Wall -Wextra -Werror

G = gcc

SRC = 	ft_atoi.c \
		ft_bzero.c \
		ft_strndup.c \
		ft_strnjoin.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isnegativ.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_itoa.c \
		ft_len_int.c \
		ft_ln_w.c \
		ft_lstadd.c \
		ft_lst_len.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy_rev.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_nb_words.c \
		ft_putchar_fd.c \
		ft_putchar.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_cast_str.c \
		ft_casta.c \
		ft_caststr_a.c \
		ft_caststr_e.c \
		ft_color.c \
		ft_getstr.c \
		ft_itoa_base.c \
		ft_print_wchar.c \
		ft_print.c \
		ft_printf.c \
		ft_specifiers.c \
		ft_str_duble.c \
		ft_strcasr_p.c \
		ft_struct_format.c \
		ft_width.c \
		itoa.c \
		pars.c \
		argn.c \
		cast_duble2.c \
		ceil_floar.c \
		format.c \
		ft_accur_digits.c \
		ft_accur.c \
		ft_apostroph.c \
		ft_casr_doubl.c \
		ft_cast_digit.c \
		ft_cast_g.c \
		caststr_a.c \
		caststra.c \
		ft_cast_dig2.c \
		ft_cast_size.c \
		ft_castb.c \
		get_next_line.c

HDR = libft.h

OBJ = $(SRC:.c=.o)

DEL = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
		@ar -cru $(NAME) $(OBJ)
		@ranlib $(NAME)

%.o: %.c libft.h
		@$(G) -c -o $@ $<
clean:
		@$(DEL) $(OBJ)

fclean: clean
		@$(DEL) $(NAME)

re: fclean all
