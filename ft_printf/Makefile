# this Makefile must compile the libft by using the libft's 
# Makefile, then compile the project
# How to use another Makefile in this Makefile ?

NAME = libftprintf.a
RM = rm -f
OBJS := $(SRC:%.c=%.o)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
