# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 10:07:39 by gfontao-          #+#    #+#              #
#    Updated: 2023/09/20 10:51:09 by gfontao-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
SRCS = $(addprefix srcs/,$(SOURCES))
INCLUDES = includes/
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