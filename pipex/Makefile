# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 14:08:56 by bkaras-g          #+#    #+#              #
#    Updated: 2025/08/06 15:18:04 by bkaras-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = pipex

SRC_DIR = Sources
SRC_FILES = tunelling.c \
			parsing.c \
			init_stack.c \
			ft_print_list.c \
			cleaning.c \
			main.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

RM = rm -f
OBJ := $(patsubst %.c, %.o, $(SRC))
CC = cc
FLAGS = -Wall -Wextra -Werror -ggdb
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADER = pipex.h

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) 1>/dev/null

$(NAME): $(OBJ) $(HEADER) $(LIBFT) Makefile
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo  "Compilation ok"

%.o: %.c
	@$(CC) $(FLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) 1>/dev/null
	@echo  "Clean done"
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) 1>/dev/null
	@$(RM) $(NAME)

re: fclean all

dev: all clean

.PHONY: all clean fclean re dev
