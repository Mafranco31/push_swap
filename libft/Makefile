# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafranco <mafranco@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 17:45:19 by mafranco          #+#    #+#              #
#    Updated: 2023/10/09 19:00:01 by mafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIB = src/libft.h

SRC = src/ft_atoi.c src/ft_isdigit.c src/ft_itoa.c src/ft_lstadd_back.c \
	src/ft_lstadd_front.c src/ft_lstclear.c src/ft_lstdelone.c \
	src/ft_lstlast.c src/ft_lstnew.c src/ft_lstsize.c src/ft_strlen.c

OBJ	=	$(SRC:.c=.o)

CC	=	cc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -I.

SRC_DIR =	src

GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RESET	= \033[0m


all: $(NAME) 

%.o: %.c $(LIB)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):: $(OBJ) $(LIB) $(OBJ_DIR)
	@ar rcs $(NAME) $(OBJ)

$(NAME)::
	@echo "$(GREEN)libft.a compiled$(RESET)"

clean:
	@$(RM) -r $(SRC_DIR)/*.o
	@echo "$(YELLOW)objects of LIBFT removed$(RESET)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)archive LIBFT removed$(RESET)"

re:	fclean all

.PHONY:	all clean fclean re
