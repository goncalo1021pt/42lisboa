rm libft.a
find . -name "*.c" -type f -exec cc -Wall -Wextra -Werror -c {} \;
ar rc libft.a *.o
find . -name "*.o" -type f -delete