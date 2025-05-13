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

NAME = libft.a

SRC = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_put_hexnbr.c \
		ft_putptr.c

BSRC = $(addsuffix _bonus.c, ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstdelone \
		ft_lstclear \
		ft_lstiter \
		ft_lstmap)

OBJ := $(SRC:%.c=%.o)
BOBJ := $(BSRC:%.c=%.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = libft.h
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) Makefile
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(OBJ) $(BOBJ) $(HEADER) Makefile
	$(AR) $(NAME) $(OBJ) $(BOBJ)

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
