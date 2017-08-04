#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msymkany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 11:05:45 by msymkany          #+#    #+#              #
#    Updated: 2016/12/19 15:43:02 by msymkany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_I = ./includes/libft.h
PRINTF_I = ./includes/libftprintf.h
INCLUDES = -I $(LIBFT_I) -I $(PRINTF_I)

SOURCE = libft/ft_isdigit.c \
            libft/ft_isalnum.c \
            libft/ft_isascii.c \
            libft/ft_isprint.c \
            libft/ft_toupper.c \
            libft/ft_tolower.c \
            libft/ft_isalpha.c \
            libft/ft_isspace.c \
            libft/ft_strdup.c \
            libft/ft_atoi.c \
            libft/ft_strlen.c \
            libft/ft_putchar.c \
            libft/ft_putstr.c \
            libft/ft_putendl.c \
            libft/ft_putnbr.c \
            libft/ft_strcpy.c \
            libft/ft_strncpy.c \
            libft/ft_strcmp.c \
            libft/ft_strncmp.c \
            libft/ft_strcat.c \
            libft/ft_strncat.c \
            libft/ft_strchr.c \
            libft/ft_strrchr.c \
            libft/ft_strstr.c \
            libft/ft_strnstr.c \
            libft/ft_memset.c \
            libft/ft_memcpy.c \
            libft/ft_bzero.c \
            libft/ft_memccpy.c \
            libft/ft_memcmp.c \
            libft/ft_memchr.c \
            libft/ft_memmove.c \
            libft/ft_strlcat.c \
            libft/ft_memalloc.c \
            libft/ft_strnew.c \
            libft/ft_memdel.c \
            libft/ft_strclr.c \
            libft/ft_strdel.c \
            libft/ft_striter.c \
            libft/ft_striteri.c \
            libft/ft_strmap.c \
            libft/ft_strmapi.c \
            libft/ft_strequ.c \
            libft/ft_strnequ.c \
            libft/ft_strsub.c \
            libft/ft_strjoin.c \
            libft/ft_trim.c \
            libft/ft_strtrim.c \
            libft/ft_putchar_fd.c \
            libft/ft_putstr_fd.c \
            libft/ft_putendl_fd.c \
            libft/ft_putnbr_fd.c \
            libft/ft_itoa.c \
            libft/ft_w_c.c \
            libft/ft_strsplit.c \
            libft/ft_lstnew.c \
            libft/ft_print_list.c \
            libft/ft_lstdelone.c \
            libft/ft_lstdel.c \
            libft/ft_lstadd.c \
            libft/ft_lstiter.c \
            libft/ft_lstmap.c \
            libft/get_next_line.c \
            libft/ft_extract_digits.c \
            libft/ft_isint.c \
            libft/ft_int_strnew.c \
            printf/ft_printf.c \
            printf/arg_cast_conversion.c \
            printf/convert_digit.c \
            printf/convert_wchar.c \
            printf/get_mod.c \
            printf/manage_struct.c \
            printf/parce_it.c \
            printf/print_char.c \
            printf/print_it.c \
            printf/print_order.c \
            printf/print_str.c \
            printf/put_txt.c \
            printf/skip_flags.c \

OBJECTS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all