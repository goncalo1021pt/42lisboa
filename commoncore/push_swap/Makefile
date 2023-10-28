S = push_swap save_stack quicksort \
	lists/costs lists/lists lists/swap \
	lists/lists2

SRCS = $(addprefix srcs/,$(addsuffix .c, $(S)))

NAME = push_swap

COMPRESS = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJS_DIR = objs

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:srcs/%.c=%.o))

LIBFT_DIR = ./includes/libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo $(NAME) ready!

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all fclean clean re
