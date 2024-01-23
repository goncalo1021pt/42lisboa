NAME = ft_display_file
SRCS = main.c ft_readfile.c ft_puterr.c 
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
CC = cc 
RM = rm -f


all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all
