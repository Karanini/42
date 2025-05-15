# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 15:52:17 by bkaras-g          #+#    #+#              #
#    Updated: 2025/05/02 17:17:03 by bkaras-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRC = ft_printf.c \
	$(addprefix libft/, \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putptr.c \
	ft_putnbr_fd.c \
	ft_put_hexnbr.c \
	ft_put_uint_fd.c \
	ft_strchr.c)

RM = rm -f
# We define OBJS like this because it's replacing the suffix of each file.
# $(SRC:%.c=%.o) is looking for a pattern. It is replacing only the name 
# of the function so it's not working when a directory is precised.   
OBJS := $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADER = ft_printf.h

all: $(LIBFT) $(NAME)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT) $(HEADER) Makefile
	ar rcs $(NAME) $(OBJS)

# We search for the headers in the current folder then in the libft
# folder, so that each function finds its header file. 
%.o: %.c
	$(CC) $(FLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
