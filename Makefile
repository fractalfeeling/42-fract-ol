# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 17:13:42 by lwee              #+#    #+#              #
#    Updated: 2022/11/15 22:08:43 by lwee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS += -Wall -Wextra -Werror -std=c99

FILES := main init render mandelbrot julia mandelbox event
SRC_DIR = src/
OBJ_DIR = src/
INC_DIR = inc/
INC += -I$(INC_DIR)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LINKFT += -Llibft -lft
LINKMLX += -Lminilibx -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
SRC_B = $(addprefix $(SRC_DIR), $(addsuffix .c, $(BONUS)))
OBJ_B = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(BONUS)))

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INC)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(INC) $(LINKFT) $(LINKMLX)

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: all

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
