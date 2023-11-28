NAME = so_long
S = so_long read_input verify_map test_mlx
G

SRCS = $(addprefix srcs/,$(addsuffix .c, $(S)))

COMPRESS = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
CC = cc

MLX_DIR = ./includes/minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a -lXext -lX11 -lm -lz

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:srcs/%.c=%.o))
LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

debug: CFLAGS += -g3 -fPIE
debug: re

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)
	@echo $(NAME) ready!

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo libft compiled and ready!

$(MLX):
	@$(MAKE) -C $(MLX_DIR) --no-print-directory
	@echo $(MLX) compiled and ready!

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

run: all
	./$(NAME) map.ber

re: fclean all

.PHONY: all fclean clean re
