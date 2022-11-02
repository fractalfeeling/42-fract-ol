# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 15:07:48 by lwee              #+#    #+#              #
#    Updated: 2022/10/24 16:46:28 by lwee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS += -Wall -Wextra -Werror -std=c99

FILES := ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_strlen \
		ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memmove \
		ft_strlcpy \
		ft_strlcat \
		ft_toupper \
		ft_tolower \
		ft_strchr \
		ft_strrchr \
		ft_strncmp \
		ft_memchr \
		ft_memcmp \
		ft_strnstr \
		ft_atoi \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd
BONUS := ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstdelone \
		ft_lstclear \
		ft_lstiter \
		ft_lstmap

SRC_DIR = .
OBJ_DIR = .
INC_DIR = ../inc
INC += -I$(INC_DIR)

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
SRC_B = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(BONUS)))

OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))
OBJ_B = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(BONUS)))

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INC)

$(NAME): $(OBJ)
	ar rcs $@ $^

bonus: $(OBJ) $(OBJ_B)
	ar rcs $(NAME) $^

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
