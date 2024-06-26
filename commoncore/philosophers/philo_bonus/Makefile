BONUS_NAME = philo_bonus

BONUS = $(addprefix bonus/,$(addsuffix .c, $(B)))
B = main read_input philo utils lists algo algo_utils table

COMPRESS = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -pthread
sanitize = -fsanitize=address
CC = cc

BONUS_OBJS = $(addprefix $(OBJS_DIR_BONUS)/,$(BONUS:bonus/%.c=%.o))
OBJS_DIR_BONUS = objs_bonus

# Color codes
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m 
ORANGE = \033[0;33m
NC = \033[0m 

bonus: $(BONUS_NAME)

$(OBJS_DIR_BONUS)/%.o: bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME): $(BONUS_OBJS) 
	@echo "$(GREEN)$(BONUS_NAME)$(NC) compiling..."
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) 
	@echo "$(GREEN)$(BONUS_NAME)$(NC) ready!"

clean:
	@$(RM) -r $(OBJS_DIR_BONUS)
	@echo "$(RED)$(BONUS_NAME)$(NC)OBJS cleaned!"

fclean: clean
	@$(RM) $(BONUS_NAME)
	@echo "$(RED)$(BONUS_NAME)$(NC)cleaned!"

s: fclean
	@echo "$(GREEN)$(BONUS_NAME)$(NC) compiling with $(ORANGE)$(sanitize)...$(NC)"
	@$(CC) $(CFLAGS) $(SANITIZE) -o $(BONUS_NAME) $(BONUS)
	@echo "$(GREEN)$(BONUS_NAME)$(NC) ready!"

v: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

fcount:
	@echo "you wrote $(RED)$(shell cat $(BONUS) | wc -l)$(NC)lines of code"

run: all
	./$(NAME) 

re: fclean all

.PHONY: all fclean clean re
