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

COMPIL = gcc -Wall -Wextra -Werror -w
#COMPIL = clang -Wall -Wextra -Werror -w

RM = rm -rf

HEADER = glide.h

ifeq "$(PLATFORM)" "WIN32"	#Mac
NAME = open3d.exe
else						#Linux & Mac
NAME = open3d
endif

PLATFORM := $(shell uname)

SRC = \
main.c \
2d_triangle.c \
2d_triforce.c \
keyword.c

OBJS = $(SRC:.c=.o)

LIB = libft/libft.a

ifeq "$(PLATFORM)" "Darwin"	#Mac
GL = -framework GLUT -framework OpenGL -framework Cocoa
else						#Linux
GL = -lGL -lGLU -lglut
endif
ifeq "$(PLATFORM)" "Win32"	#Windows
GL = -lopengl32 -lglu32 -lglut32
endif

all : $(NAME)

$(LIB):
	make -C libft

%.o: %.c $(HEADER)
	$(COMPIL) $(SRC) -I /libft -I /includes -c $<

$(NAME): $(LIB) $(MLX) $(OBJS)
	$(COMPIL) $(OBJS) -o $(NAME) $(GL) -L libft -lft
	@echo "----------------- Compil for $(PLATFORM)... Done -----------------"

clean:
	$(RM) $(OBJS)
	make clean -C libft
	@echo "----------------- Clean for $(PLATFORM)... Done -----------------"

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	@echo "----------------- FClean for $(PLATFORM)... Done -----------------"

re: fclean all

.PHONY: all clean fclean re
