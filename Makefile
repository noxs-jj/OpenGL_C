#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/02 11:51:53 by jmoiroux          #+#    #+#              #
#    Updated: 2014/01/19 18:24:38 by jmoiroux         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Makefile parent who call Makefile soon from libft
# add llvm- in CC= line if you need depends update of computer

COMPIL = gcc -Wall -Wextra -Werror -w

RM = rm -rf

HEADER = glide.h

NAME = open3d

SRC = \
main.c

OBJS = $(SRC:.c=.o)

LIB = libft/libft.a
GL = -framework GLUT -framework OpenGL -framework Cocoa

all : $(NAME)

$(LIB):
	make -C libft

%.o: %.c $(HEADER)
	$(COMPIL) $(SRC) -I /libft -I /includes -c $<

$(NAME): $(LIB) $(MLX) $(OBJS)
	$(COMPIL) $(OBJS) -o $(NAME) $(GL) -L libft -lft

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
