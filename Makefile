NAME        = pipex
NAME_BONUS  = pipex_bonus

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

SRCS        = srcs/pipex.c

BONUS_SRCS  = srcs_bonus/pipex.c

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)
FT_PRINTF       = ./srcs/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./srcs/ft_printf
	$(CC) $(OBJS) $(FT_PRINTF) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	make -C ./srcs/ft_printf
	$(CC) $(BONUS_OBJS) $(FT_PRINTF) -o $(NAME_BONUS)
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C ./srcs/ft_printf

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C ./srcs/ft_printf

re: fclean all

.PHONY: all clean fclean re bonus
