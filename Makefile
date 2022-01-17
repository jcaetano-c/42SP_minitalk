# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 15:26:28 by jcaetano          #+#    #+#              #
#    Updated: 2022/01/14 15:32:42 by jcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server
SOURCE_S = ./src/server.c

CLIENT = client
SOURCE_C = ./src/client.c

SOURCE_U = ./src/utils.c

INC = ./include/

CC		=	gcc $(CFLAGS)
CFLAGS	=	-g3 $(WFLAGS) $(SAN)
WFLAGS	=	-Wall -Wextra -Werror
SAN		=	-fsanitize=address


all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(CLIENT): $(SOURCE_C) $(SOURCE_U) $(FT_PRINTF)
	$(CC) $(FLAGS) -I$(INC) $^ -o $@

$(SERVER): $(SOURCE_S) $(SOURCE_U) $(FT_PRINTF)
	$(CC) $(FLAGS) -I$(INC) $^ -o $@

clean:

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)

re: fclean all
