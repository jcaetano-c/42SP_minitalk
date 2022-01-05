# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 11:33:07 by jcaetano          #+#    #+#              #
#    Updated: 2022/01/05 06:15:33 by jcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a
INC_DIR			=	./includes

SRC				=	./src
SRCS			=	ft_printf.c \
					ft_printf_chars.c \
					ft_printf_nbrs.c \
					ft_printf_hex.c

HEADER			=	$(INC_DIR)/ft_printf.h

OBJ				=	./bin
OBJS			=	$(addprefix $(OBJ)/,$(SRCS:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g
SAN				=	-g3 -fsanitize=address
INCS			=	-I $(INC_DIR) -I $(LIBFT_PATH)/$(INC_DIR)

AR				=	ar -rcs
RM				=	rm -rf
DIR_GUARD		=	mkdir -p $(@D)

$(OBJ)/%.o:	$(SRC)/%.c
				$(DIR_GUARD)
				$(CC) $(CFLAGS) $(INCS) -c $< -o $@ $(SAN)


all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJS) $(HEADER)
					cp	$(LIBFT) $(NAME)
					$(AR) $(NAME) $(OBJS)

$(LIBFT):
					$(MAKE) -C $(LIBFT_PATH)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(MAKE) -C $(LIBFT_PATH) clean
					$(RM) $(OBJ) *.out

fclean:				clean
					$(MAKE) -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft run test
