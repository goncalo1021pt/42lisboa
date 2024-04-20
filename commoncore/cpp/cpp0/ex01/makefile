NAME = phonebook

SRCS = $(addprefix srcs/,$(addsuffix .cpp, $(S)))
S = PhoneBook

RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98
SFLAGS = -fsanitize=address
CC = c++

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:srcs/%.cpp=%.o))
SOBJS = $(addprefix $(OBJS_DIR_S)/,$(SRCS:srcs/%.cpp=%.o))

OBJS_DIR = objs
OBJS_DIR_S = s_objs

# Color codes
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m 
ORANGE = \033[0;33m
NC = \033[0m 

all: $(NAME)

$(OBJS_DIR)/%.o: srcs/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_S)/%.o: srcs/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(SFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN)$(NAME)$(NC) compiling..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME)$(NC) ready!"

s: fclean $(SOBJS)
	@echo "$(GREEN)$(NAME)$(NC) compiling..."
	@$(CC) $(CFLAGS) $(SFLAGS) -o $(NAME) $(SOBJS) 
	@echo "$(GREEN)$(NAME)$(NC) ready!"

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJS_DIR_BONUS)
	@$(RM) -r $(OBJS_DIR_S)
	@echo "$(RED)$(NAME)$(NC)OBJS cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@echo "$(RED)$(NAME)$(NC)cleaned!"

v: 
	make re && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --suppressions="supression.supp" ./$(NAME)

fcount:
	@echo "you wrote $(RED)$(shell cat $(SRCS) | wc -l)$(NC)lines of code"

run: all
	./$(NAME) 

re: fclean all

.PHONY: all fclean clean re
