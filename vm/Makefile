
NAME = corewar

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

FIL_I = vm.h
INCLUDES = -I $(FIL_I)

SOURCE = corewar_main.c \
		ft_usage.c \
        
OBJECTS = $(SOURCE:.c=.o)

LIBFT_DIR = ../libft/

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_DIR)libft.a
		$(CC) $(FL) $(OBJECTS) -o $(NAME) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(FL) -c $< -o $@

$(LIBFT_DIR)libft.a:
		make -C $(LIBFT_DIR)

.PHONY: clean fclean re

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all