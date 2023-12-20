NAME = so_long
BONUS_NAME = so_long_bonus

BONUS = $(addprefix bonus/,$(addsuffix .c, $(B)))
B = so_long read_input check_map verify_map close_program \
	$(GRAPHICS_B)

G_B = mlx_start packman packman_init map map_init map_init2 img hooks hooks2
GRAPHICS_B = $(addprefix graphics/,$(G_B))

SRCS = $(addprefix srcs/,$(addsuffix .c, $(S)))
S = so_long read_input check_map verify_map close_program \
	$(GRAPHICS)

G = mlx_start packman packman_init map map_init map_init2 img hooks hooks2
GRAPHICS = $(addprefix graphics/,$(G))

COMPRESS = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
CC = cc

MLX_DIR = ./includes/minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a -lXext -lX11 -lm -lz

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:srcs/%.c=%.o))
BONUS_OBJS = $(addprefix $(OBJS_DIR_BONUS)/,$(BONUS:bonus/%.c=%.o))
OBJS_DIR = objs
OBJS_DIR_BONUS = objs_bonus
LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME) $(BONUS_NAME)
bonus: $(BONUS_NAME)

debug: CFLAGS += -g3 -fPIE
debug: re

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_BONUS)/%.o: bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)
	@echo $(NAME) ready!

$(BONUS_NAME): $(MLX) $(BONUS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LIBFT) $(MLX)
	@echo $(BONUS_NAME) ready!

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo libft compiled and ready!

$(MLX):
	@$(MAKE) -C $(MLX_DIR) --no-print-directory
	@echo $(MLX) compiled and ready!

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJS_DIR_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

fcount:
	@echo "you wrote quite some lines of code"
	@cat $(SRCS) | wc -l

run: all
	./$(NAME) includes/maps/test.ber

re: fclean all

.PHONY: all fclean clean re
