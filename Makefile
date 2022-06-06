NAME = fractol
all : $(NAME)
$(NAME) :
	gcc -c *.c
	gcc -Wall -Wextra -Werror -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit  *.o  -o $(NAME)
clean :
	rm -rf *.o
fclean : clean
	rm -rf $(NAME)
re : fclean all