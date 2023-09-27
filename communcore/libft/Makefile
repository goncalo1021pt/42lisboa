SOURCES = 

INCLUDES = libft.h

NAME = libft.a

COMPRESS = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

CC = cc

OBJECTS = $(SRCS:.c=.o)

$(NAME): $(OBJECTS)
	$(COMPRESS) $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all