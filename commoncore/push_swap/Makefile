SRCS = push_swap.c save_stack.c lists/lists.c lists/swap.c lists/lists2.c

NAME = push_swap

COMPRESS = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./includes/libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all fclean clean re