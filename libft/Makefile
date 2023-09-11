# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafranco <mafranco@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 17:45:19 by mafranco          #+#    #+#              #
#    Updated: 2023/09/11 15:51:47 by mafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIB = src/libft.h

SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ	=	$(SRC:.c=.o)

CC	=	cc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -I.

OBJ_DIR =	.obj
SRC_DIR =	src

GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RESET	= \033[0m


all: $(NAME) 

%.o: %.c $(LIB)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):: $(OBJ) $(LIB) $(OBJ_DIR)
	@ar rcs $(NAME) $(OBJ)
	@mv $(SRC_DIR)/*.o $(OBJ_DIR)

$(NAME)::
	@echo "$(GREEN)libft.a compiled$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(YELLOW)objects of LIBFT removed$(RESET)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)archive LIBFT removed$(RESET)"

re:	fclean all

.PHONY:	all clean fclean re
