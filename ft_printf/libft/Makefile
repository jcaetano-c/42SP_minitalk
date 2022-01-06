# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaetano <jcaetanostudent.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/05 13:39:23 by vbrazhni          #+#    #+#              #
#    Updated: 2021/11/19 08:03:45 by jcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

H_LIST = \
	libft.h\
	get_next_line.h
H_DIR = includes/
HEADERS = $(addprefix $(H_DIR), $(H_LIST))

S_DIR = src/
S_LIST = \
	ft_atoi.c			\
	ft_bzero.c			\
	ft_calloc.c			\
	ft_isalnum.c		\
	ft_isalpha.c 		\
	ft_isascii.c 		\
	ft_isdigit.c 		\
	ft_isprint.c 		\
	ft_itoa.c 			\
	ft_lstadd_back.c	\
	ft_lstadd_front.c	\
	ft_lstclear.c 		\
	ft_lstdelone.c 		\
	ft_lstiter.c 		\
	ft_lstlast.c 		\
	ft_lstmap.c 		\
	ft_lstnew.c 		\
	ft_lstsize.c 		\
	ft_memchr.c 		\
	ft_memcmp.c 		\
	ft_memcpy.c 		\
	ft_memmove.c 		\
	ft_memset.c 		\
	ft_putchar_fd.c 	\
	ft_putendl_fd.c 	\
	ft_putnbr_fd.c 		\
	ft_putstr_fd.c 		\
	ft_split.c 			\
	ft_strchr.c 		\
	ft_strdup.c 		\
	ft_striteri.c 		\
	ft_strjoin.c 		\
	ft_strlcat.c 		\
	ft_strlcpy.c 		\
	ft_strlen.c 		\
	ft_strmapi.c 		\
	ft_strncmp.c 		\
	ft_strnstr.c 		\
	ft_strrchr.c 		\
	ft_strtrim.c 		\
	ft_substr.c 		\
	ft_tolower.c 		\
	ft_toupper.c 		\
	get_next_line.c 	\
	ft_strlower.c 		\
	ft_strcmp.c 		\
	ft_min.c			\
	ft_max.c			\
	ft_absolute.c 		\
	ft_isspace.c 		\
	ft_atof.c			\

SOURCES = $(addprefix $(S_DIR), $(S_LIST))

O_DIR = objects/
O_LIST = $(patsubst %.c, %.o, $(S_LIST))
OBJECTS = $(addprefix $(O_DIR), $(O_LIST))

CC = gcc
FLAGS = -Wall -Werror -Wextra -c -lm -lbsd
INCLUDES = -I $(H_DIR)

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(O_DIR) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@echo "$(GREEN)$(NAME) was created$(RESET)"

$(O_DIR):
	@mkdir -p $(O_DIR)
	@echo "$(GREEN)$(NAME): $(O_DIR) was created$(RESET)"

$(O_DIR)%.o: $(S_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) $< -o $@
	@echo "$(GREEN)$@ was created$(RESET)"
clean:
	@rm -rf $(O_DIR)
	@echo "$(RED)$(O_DIR) directory was deleted$(RESET)"
	@echo "$(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
