
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
        operations/1_live.c \
        operations/2_ld.c \
        operations/3_st.c \
        operations/4_add.c \
        operations/5_sub.c \
        operations/6_and.c \
        operations/7_or.c \
        operations/8_xor.c \
        operations/9_zjmp.c \
        operations/10_ldi.c \
        operations/11_sti.c \
        operations/12_fork.c \
        operations/13_lld.c \
        operations/14_lldi.c \
        operations/15_lfork.c \
        operations/16_aff.c \

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