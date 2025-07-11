# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 08:49:24 by bkaras-g          #+#    #+#              #
#    Updated: 2025/07/11 15:10:18 by bkaras-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = letzgooo_lists.out

SRC = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_lstsize.c \
		ft_lstlast.c \
		print_list.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_list_remove_if.c

OBJ := $(patsubst %.c, %.o, $(SRC))
CC = cc
FLAGS = -Wall -Werror -Wextra -ggdb
HEADER = list.h
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) Makefile
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
