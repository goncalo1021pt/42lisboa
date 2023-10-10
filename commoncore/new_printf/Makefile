SRCS = ft_printf.c aux_functions.c

NAME = libftprintf.a

COMPRESS = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJS = $(SRCS:.c=.o)

LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

$(NAME): $(LIBFT) $(OBJS)
	@$(COMPRESS) $(NAME) $(OBJS) libft/*.o

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR) --no-print-directory

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFTDIR) clean --no-print-directory

fclean: clean
	@$(RM) $(NAME) ft_printf
	@$(MAKE) -C $(LIBFTDIR) fclean --no-print-directory

re: fclean all

test:
	$(CC) -o ft_printf $(CFLAGS) main.c $(NAME)

.PHONY: all fclean clean