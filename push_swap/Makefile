# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 14:08:56 by bkaras-g          #+#    #+#              #
#    Updated: 2025/07/18 16:04:35 by bkaras-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_print_list.c \
		ft_rotate.c \
		ft_swap.c \
		ft_push.c \
		ft_lstclear.c \
		ft_parsing.c \
		main.c

RM = rm -f
OBJ := $(patsubst %.c, %.o, $(SRC))
CC = cc
FLAGS = -Wall -Wextra -Werror -ggdb
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADER = push_swap.h

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(HEADER) $(LIBFT) Makefile
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
