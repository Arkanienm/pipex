NAME        = pipex

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

SRCS        = srcs/pipex.c srcs/ft_split.c srcs/ft_functions.c \
			  srcs/pipex_utils.c srcs/execute.c


OBJS        = $(SRCS:.c=.o)
FT_PRINTF       = ./srcs/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./srcs/ft_printf
	$(CC) $(OBJS) $(FT_PRINTF) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C ./srcs/ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C ./srcs/ft_printf

re: fclean all

.PHONY: all clean fclean re
