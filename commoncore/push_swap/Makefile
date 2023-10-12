SRCS =	

BONUS = 

NAME = 

COMPRESS = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

$(NAME): $(OBJS) 
	@$(COMPRESS) $(NAME) $(OBJS)

bonus: 

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re