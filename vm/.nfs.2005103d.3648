
NAME = corewar

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

FIL_I = vm.h
INCLUDES = -I $(FIL_I)

SOURCE = corewar_main.c \
		ft_usage.c \
		ft_error.c \
		read_args.c \
		check_args.c \
		general_struct.c \
		playground_prep.c \
        process_struct.c \
        processing.c \
        fetch.c \
        uncode_args.c \
        op.c \
        v_first.c \
        v_second.c \
        v_third.c \
        v_fourth.c \
        v_fifth.c \
        operations/a1_live.c \
        operations/a2_ld.c \
        operations/a3_st.c \
        operations/a4_add.c \
        operations/a5_sub.c \
        operations/a6_and.c \
        operations/a7_or.c \
        operations/a8_xor.c \
        operations/a9_zjmp.c \
        operations/a10_ldi.c \
        operations/a11_sti.c \
        operations/a12_fork.c \
        operations/a13_lld.c \
        operations/a14_lldi.c \
        operations/a15_lfork.c \
        operations/a16_aff.c \

OBJECTS = $(SOURCE:.c=.o)

LIBFT_DIR = ../libft/

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_DIR)libft.a
		$(CC) $(FL) $(OBJECTS) -o $(NAME) -L$(LIBFT_DIR) -lft -lncurses

%.o: %.c
	$(CC) $(FL) -c $< -o $@

$(LIBFT_DIR)libft.a:
		make -C $(LIBFT_DIR)

.PHONY: clean fclean re

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJECTS)
	rm -f *~ *#

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all