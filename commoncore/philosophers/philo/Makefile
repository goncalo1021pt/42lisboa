NAME = philo

SRCS = $(addprefix srcs/,$(addsuffix .c, $(S)))
S = main read_input philo utils lists algo table

COMPRESS = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -pthread
sanitize = -fsanitize=address
CC = cc

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:srcs/%.c=%.o))

OBJS_DIR = objs

# Color codes
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m 
ORANGE = \033[0;33m
NC = \033[0m 

all: $(NAME)
  
$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	@echo "$(GREEN)$(NAME)$(NC) compiling..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME)$(NC) ready!"

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJS_DIR_BONUS)
	@echo "$(RED)$(NAME)$(NC)OBJS cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@echo "$(RED)$(NAME)$(NC)cleaned!"

s: fclean
	@echo "$(GREEN)$(NAME)$(NC) compiling with $(ORANGE)$(sanitize)...$(NC)"
	@$(CC) $(CFLAGS) $(SANITIZE) -o $(NAME) $(SRCS)
	@echo "$(GREEN)$(NAME)$(NC) ready!"

v: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

fcount:
	@echo "you wrote $(RED)$(shell cat $(SRCS) | wc -l)$(NC)lines of code"

run: all
	./$(NAME) 

re: fclean all

.PHONY: all fclean clean re 

