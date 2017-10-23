#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msymkany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 17:19:36 by msymkany          #+#    #+#              #
#    Updated: 2017/10/12 17:19:52 by msymkany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = corewar

SOURCE = vm/corewar_main.c \
		vm/ft_usage.c \
		vm/ft_error.c \
		vm/read_args.c \
		vm/check_args.c \
		vm/general_struct.c \
		vm/playground_prep.c \
		vm/process_struct.c \
		vm/processing.c \
		vm/fetch.c \
		vm/uncode_args.c \
		vm/op.c \
		vm/v_first.c \
		vm/v_second.c \
		vm/v_third.c \
		vm/v_fourth.c \
		vm/v_fifth.c \
		vm/operations/a1_live.c \
		vm/operations/a2_ld.c \
		vm/operations/a3_st.c \
		vm/operations/a4_add.c \
		vm/operations/a5_sub.c \
		vm/operations/a6_and.c \
		vm/operations/a7_or.c \
		vm/operations/a8_xor.c \
		vm/operations/a9_zjmp.c \
		vm/operations/a10_ldi.c \
		vm/operations/a11_sti.c \
		vm/operations/a12_fork.c \
		vm/operations/a13_lld.c \
		vm/operations/a14_lldi.c \
		vm/operations/a15_lfork.c \
		vm/operations/a16_aff.c \

OBJECTS = $(SOURCE:.c=.o)

NAME_2 = asm

SOURCE_2 = assembly/coding_byte.c \
		assembly/ft_argument.c \
		assembly/ft_compiler.c \
		assembly/ft_dell_all.c \
		assembly/ft_instruction.c \
		assembly/ft_size_program.c \
		assembly/last_byt.c \
		assembly/main.c \
		assembly/my_errormeneger.c \
		assembly/name_and_coment.c \
		assembly/search_availability_label.c \
		assembly/serch_label.c \
		assembly/translation_into_bytcode.c \
		assembly/valid_direct.c \
		assembly/valid_indir.c \
		assembly/valid_registr.c \
		assembly/write_program.c \

OBJECTS_2 = $(SOURCE_2:.c=.o)

CC = gcc
FL = -Wall -Wextra -Werror

FIL_I = vm/vm.h
INC = -I $(FIL_I)

FIL_I_2 = asm/asm.h
INC_2 = -I $(FIL_I_2)

LIBFT_DIR = ./libft/

all: $(NAME_2) $(NAME) done

$(NAME): $(OBJECTS) $(LIBFT_DIR)libft.a
		@$(CC) $(FL) $(OBJECTS) -o $(NAME) -L$(LIBFT_DIR) -lft -lncurses

$(NAME_2): $(OBJECTS_2) $(LIBFT_DIR)libft.a
		@$(CC) $(FL) $(OBJECTS_2) -o $(NAME_2) -L$(LIBFT_DIR) -lft

%.o: %.c
	@$(CC) $(FL) -c $< -o $@

$(LIBFT_DIR)libft.a:
		@make -C $(LIBFT_DIR)
		@echo "\033[;32m\t==== Libft is ready ====\033[33;0m"

.PHONY: clean fclean re

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJECTS)
	@rm -f $(OBJECTS_2)
	@rm -f assembly/*~ assembly/*.# 
	@rm -f vm/*~ vm/*.# 
	@echo "\033[;32m\t==== It's clean ====\033[33;0m"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME) $(NAME_2)

re: fclean all

done:
	@echo "\033[;34m\t==== The project is ready ====\033[33;0m"
	@say -v "Alex" "magic"
