# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 14:08:56 by bkaras-g          #+#    #+#              #
#    Updated: 2025/07/30 16:42:42 by bkaras-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = push_swap
BONUS_NAME = checker

SRC_DIR = Sources
SRC_FILES = ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_print_list.c \
		ft_rotate.c \
		ft_reverse_rotate.c \
		ft_swap.c \
		ft_push.c \
		ft_lstclear.c \
		ft_parsing.c \
		ft_init_stack.c \
		ft_sort.c \
		ft_sort_utils.c \
		ft_sort_utils_2.c \
		main.c

BONUS_SRC_FILES = ft_lstadd_back.c \
        ft_lstadd_front.c \
        ft_lstlast.c \
        ft_lstnew.c \
        ft_lstsize.c \
        ft_print_list.c \
        ft_rotate.c \
        ft_reverse_rotate.c \
        ft_swap.c \
        ft_push.c \
        ft_lstclear.c \
        ft_parsing.c \
        ft_init_stack.c \
        ft_sort.c \
        ft_sort_utils.c \
        ft_sort_utils_2.c \
        main_checker.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_SRC = $(addprefix $(SRC_DIR)/, $(BONUS_SRC_FILES))

RM = rm -f
OBJ := $(patsubst %.c, %.o, $(SRC))
CC = cc
FLAGS = -Wall -Wextra -Werror -ggdb
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADER = push_swap.h

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) 1>/dev/null

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(HEADER) $(LIBFT) Makefile
    @$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)
    @echo  "Bonus compilation ok"

$(NAME): $(OBJ) $(HEADER) $(LIBFT) Makefile
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo  "Compilation ok"


%.o: %.c
	@$(CC) $(FLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) 1>/dev/null
	@echo  "Clean done"
	@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) 1>/dev/null
	@$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

dev: all clean

.PHONY: all clean fclean re dev bonus
