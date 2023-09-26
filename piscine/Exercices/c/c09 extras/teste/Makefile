CFLAGS += -Wall -Wextra -Werror

MY_SOURCES = main.c ft_putstr.c ft_strlen.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

NAME = program

a_prog: my_rule $(MY_OBJECTS)
	cc -o $(NAME) $(CFLAGS) $(MY_OBJECTS)

my_rule:
	echo i will compile my files $(MY_SOURCES)

clean:
	rm *.o program