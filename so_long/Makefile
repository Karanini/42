# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 14:08:56 by bkaras-g          #+#    #+#              #
#    Updated: 2025/09/05 14:47:57 by bkaras-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = so_long
BONUS_NAME = so_long

SRC_DIR = Sources
BONUS_DIR = Bonus
SRC_FILES = init_mlx_data.c \
			parsing_1.c \
			parsing_2.c \
			generate_map.c \
			event_handlers.c \
			screen_utils.c \
			print_utils.c \
			cleaning.c \
			main.c

SRC_BONUS_FILES = init_mlx_data_bonus.c \
			generate_map_bonus.c \
			event_handlers_bonus.c \
			cleaning_bonus.c \
			main_bonus.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRC_BONUS = $(addprefix $(BONUS_DIR)/, $(SRC_BONUS_FILES))

RM = rm -f
OBJ := $(patsubst %.c, %.o, $(SRC))
BOBJ := $(patsubst %.c, %.o, $(SRC_BONUS))
CC = cc
FLAGS = -Wall -Wextra -Werror -ggdb
X_LIB = -Iminilibx-linux -Lminilibx-linux -lmlx_Linux -lX11 -lXext
X_LIB_OBJ = -Iminilibx-linux
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADER = so_long.h
HEADER_BONUS = so_long_bonus.h

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) 1>/dev/null

$(NAME): $(OBJ) $(HEADER) $(LIBFT) Makefile
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(X_LIB) -o $(NAME)
	@echo  "Mandatory part compilation ok"

%.o: %.c
	@$(CC) $(FLAGS) -I. -I$(LIBFT_DIR) $(X_LIB_OBJ) -c $< -o $@

bonus: $(BOBJ) $(HEADER_BONUS) $(LIBFT) Makefile
	@$(CC) $(FLAGS) $(BOBJ) $(LIBFT) $(X_LIB) -o $(BONUS_NAME)
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
