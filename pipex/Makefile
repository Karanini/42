# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 14:08:56 by bkaras-g          #+#    #+#              #
#    Updated: 2025/08/29 15:09:43 by bkaras-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = pipex
BONUS_NAME = pipex

SRC_DIR = Sources
BONUS_DIR = Bonus
SRC_FILES = tunelling_multipipe.c \
			dup2_children.c \
			parsing.c \
			init_list.c \
			ft_print_list.c \
			cleaning.c \
			utils.c \
			main.c
			
SRC_BONUS_FILES = tunelling_multipipe_bonus.c \
			dup2_children_bonus.c \
			parsing_bonus.c \
			init_list_bonus.c \
			ft_print_list_bonus.c \
			cleaning_bonus.c \
			utils_bonus.c \
			main_bonus.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRC_BONUS = $(addprefix $(BONUS_DIR)/, $(SRC_BONUS_FILES))

RM = rm -f
OBJ := $(patsubst %.c, %.o, $(SRC))
BOBJ := $(patsubst %.c, %.o, $(SRC_BONUS))
CC = cc
FLAGS = -Wall -Wextra -Werror -ggdb
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADER = pipex.h
HEADER_BONUS = pipex_bonus.h

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) 1>/dev/null

$(NAME): $(OBJ) $(HEADER) $(LIBFT) Makefile
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo  "Mandatory part compilation ok"

%.o: %.c
	@$(CC) $(FLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

bonus: $(BOBJ) $(HEADER_BONUS) $(LIBFT) Makefile
	@$(CC) $(FLAGS) $(BOBJ) $(LIBFT) -o $(BONUS_NAME)
	@echo  "Bonus part compilation ok"

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) 1>/dev/null
	@$(RM) $(OBJ)
	@$(RM) $(BOBJ)
	@echo  "Clean done"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) 1>/dev/null
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)

re: fclean all

dev: all clean

.PHONY: all clean fclean re dev bonus
