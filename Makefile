# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 06:17:04 by jcaetano          #+#    #+#              #
#    Updated: 2022/01/08 09:14:21 by jcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minitalk

# FILES AND DIRECTORYS
INC		=	./include
SRC		=	./src
SRCS	=	server.c	\
			utils.c
OBJ		=	./obj
OBJS	=	$(addprefix $(OBJ)/,$(SRCS:.c=.o))

# COMANDS
GCC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -g $(SAN)
INCS	=	-I $(INC)
SAN		=	-g3 -fsanitize=address

$(OBJ)/%.o:	$(SRC)/%.c
			mkdir -p $(@D)
			$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):	$(OBJS) server

all:		$(NAME)

server:
			$(CC) $(CFLAGS) $(OBJS) $(INCS) -o server

clean:
			rm -fr ./obj

fclean:		clean
			rm -fr	server

re:			fclean all

.PHONY:		all bonus fsan clean fclean re server
