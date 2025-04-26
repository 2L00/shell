
NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
READLINE = -lreadline

SRCS = mini.c create_prompt.c path_name.c run_simple_cmd.c \
	single_or_double.c unclosed_quotes.c ft_split_shell.c 

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re