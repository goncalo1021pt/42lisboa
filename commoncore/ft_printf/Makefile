SRCS = ft_printf.c

NAME = libftprintf.a

COMPRESS = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(COMPRESS) $(NAME) $(OBJS)

$(OBJS):
	@$(make) -C $(LIBFT)
	@$(CC) -c $(CFLAGS) $(SRCS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean