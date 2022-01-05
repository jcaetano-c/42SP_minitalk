# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 06:17:04 by jcaetano          #+#    #+#              #
#    Updated: 2022/01/05 06:21:03 by jcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FILES AND DIRECTORYS

INC_DIR	=	./includes
OBJ		=	./bin
OBJS	=	$(addprefix $(OBJ)/,$(SRCS:.c=.o))

# COMANDS
GCC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -g $(SAN)
INCS	=	-I $(INC_DIR)
SAN		=	-g3 -fsanitize=address


