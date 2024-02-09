NAME = philosophers
BONUS_NAME = philosophers_bonus

BONUS = $(addprefix bonus/,$(addsuffix .c, $(B)))
B = 

SRCS = $(addprefix srcs/,$(addsuffix .c, $(S)))
S = main read_input philo utils lists 

COMPRESS = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
CC = cc

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:srcs/%.c=%.o))

BONUS_OBJS = $(addprefix $(OBJS_DIR_BONUS)/,$(BONUS:bonus/%.c=%.o))
OBJS_DIR = objs
OBJS_DIR_BONUS = objs_bonus

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Color codes
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m 
ORANGE = \033[0;33m
NC = \033[0m 

all: $(NAME) 
bonus: $(BONUS_NAME)
  

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_BONUS)/%.o: bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	@echo "$(GREEN)$(NAME)$(NC) compiling..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME)$(NC) ready!"

$(BONUS_NAME): $(BONUS_OBJS) 
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) 
	@echo $(BONUS_NAME)ready!

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJS_DIR_BONUS)
	@echo "$(RED)$(NAME)$(NC)OBJS cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@echo "$(RED)$(NAME)$(NC)cleaned!"

v: 
	make re && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions="supression.supp" ./$(NAME)

fcount:
	@echo "you wrote $(RED)$(shell cat $(SRCS) | wc -l)$(NC)lines of code"

run: all
	./$(NAME) 

re: fclean all

.PHONY: all fclean clean re

