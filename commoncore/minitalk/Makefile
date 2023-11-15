S_client = client client_aux

S_server = server server_aux

BONUS =

SRCS_client = $(addprefix srcs/,$(addsuffix .c, $(S_client)))

SRCS_server = $(addprefix srcs/,$(addsuffix .c, $(S_server)))

NAME_client = client

NAME_server = server

BONUS_NAME =

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJS_DIR = objs

BONUS_OBJ = $(addprefix $(OBJS_DIR)/,$(BONUS:bonus/%.c=%.o))

OBJS_SERVER = $(addprefix $(OBJS_DIR)/,$(SRCS_server:srcs/%.c=%.o))

OBJS_CLIENT = $(addprefix $(OBJS_DIR)/,$(SRCS_client:srcs/%.c=%.o))

LIBFT_DIR = ./includes/libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME_client) $(NAME_server)

bonus: $(BONUS_NAME)

$(OBJS_DIR)/%.o: bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_client): $(OBJS_CLIENT) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME_client) $(OBJS_CLIENT) $(LIBFT)
	@echo $(NAME_client) ready!

$(NAME_server): $(OBJS_SERVER) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME_server) $(OBJS_SERVER) $(LIBFT)
	@echo $(NAME_server) ready!

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
	@$(RM) $(NAME_client) $(NAME_server)
	@$(RM) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all bonus fclean clean re
