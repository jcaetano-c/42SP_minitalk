# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 06:17:04 by jcaetano          #+#    #+#              #
#    Updated: 2022/01/12 15:41:17 by jcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minitalk

# FILES AND DIRECTORYS
INC		=	./include
SRC		=	./src
SRCS	=	utils.c
OBJ		=	./obj
OBJS	=	$(addprefix $(OBJ)/,$(SRCS:.c=.o))

# COMANDS
GCC		=	gcc
CFLAGS	=	-g $(WFLAGS) $(SAN)
WFLAGS	=	-Wall -Wextra -Werror
SAN		=	-g3 -fsanitize=address
INCS	=	-I $(INC)

$(OBJ)/%.o:	$(SRC)/%.c
			@echo "Compilando $<"
			mkdir -p $(@D)
			$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):	$(OBJS)

all:		$(NAME) server client

server:
			@echo "Compilando server"
			$(CC) $(CFLAGS) $(SRC)/server.c $(OBJS) $(INCS) -o server

client:
			@echo "Compilando client"
			$(CC) $(CFLAGS) $(SRC)/client.c $(OBJS) $(INCS) -o client

clean:
			@rm -fr ./obj

fclean:		clean
			@rm -fr	server
			@rm -fr	client

re:			fclean all

.PHONY:		all bonus fsan clean fclean re server client
