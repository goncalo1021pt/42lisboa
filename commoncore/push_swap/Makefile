S = save_stack quicksort small_sort \
	send_cost lists/costs lists/costs2 lists/lists \
	src_aux lists/swap lists/lists2

MAIN_SRC = srcs/push_swap.c

BONUS = bonus/checker.c bonus/checker_aux.c

SRCS = $(addprefix srcs/,$(addsuffix .c, $(S)))

NAME = push_swap

BONUS_NAME = checker

COMPRESS = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJS_DIR = objs

BONUS_OBJ = $(addprefix $(OBJS_DIR)/,$(BONUS:bonus/%.c=%.o))

MAIN_OBS = $(addprefix $(OBJS_DIR)/,$(MAIN_SRC:srcs/%.c=%.o))

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:srcs/%.c=%.o))

LIBFT_DIR = ./includes/libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

bonus: $(BONUS_NAME)

$(OBJS_DIR)/%.o: bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(MAIN_OBS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBS) $(OBJS) $(LIBFT)
	@echo $(NAME) ready!

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo libft compiled and ready!

$(BONUS_NAME): $(OBJS) $(BONUS_OBJ)
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJS) $(BONUS_OBJ) $(LIBFT)
	@echo $(BONUS_NAME) ready!

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all bonus fclean clean re
