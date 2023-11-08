S = save_stack quicksort small_sort \
	send_cost lists/costs lists/costs2 lists/lists \
	src_aux lists/swap lists/lists2

MAIN_SRC = srcs/push_swap.c

BONUS = bonus/main.c bonus/checker_aux.c

SRCS = $(addprefix srcs/,$(addsuffix .c, $(S)))

NAME = push_swap

COMPRESS = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJS_DIR = objs

MAIN_OBS = $(addprefix $(OBJS_DIR)/,$(MAIN_SRC:srcs/%.c=%.o))

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:srcs/%.c=%.o))

LIBFT_DIR = ./includes/libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(MAIN_OBS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBS) $(OBJS) $(LIBFT)
	@echo $(NAME) ready!

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo libft compiled and ready!

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all fclean clean re
