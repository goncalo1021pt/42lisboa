NAME = philosophers
BONUS_NAME = philosophers_bonus

BONUS = $(addprefix bonus/,$(addsuffix .c, $(B)))
B = 

SRCS = $(addprefix srcs/,$(addsuffix .c, $(S)))
S = main r

COMPRESS = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
CC = cc

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:srcs/%.c=%.o))
BONUS_OBJS = $(addprefix $(OBJS_DIR_BONUS)/,$(BONUS:bonus/%.c=%.o))
OBJS_DIR = objs
OBJS_DIR_BONUS = objs_bonus

all: $(NAME) $(BONUS_NAME)
bonus: $(BONUS_NAME)

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_BONUS)/%.o: bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 
	@echo $(NAME) ready!

$(BONUS_NAME): $(BONUS_OBJS) 
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) 
	@echo $(BONUS_NAME) ready!

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJS_DIR_BONUS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)

fcount:
	@echo "you wrote quite some lines of code"
	@cat $(SRCS) | wc -l

run: all
	./$(NAME) includes/maps/test.ber

re: fclean all

.PHONY: all fclean clean re
