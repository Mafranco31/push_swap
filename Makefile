# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 15:03:30 by mafranco          #+#    #+#              #
#    Updated: 2023/09/15 11:41:39 by mafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

LIB	=	include/push_swap.h

CC		= cc

CFLAGS		= -Wall -Werror -Wextra -I.

RM		= rm -f

LIBFT_PATH = ./libft/
LIBFT	=	libft.a
LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT))

GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RESET		= \033[0m

SRC_DIR	=	src
SRC		= $(wildcard $(SRC_DIR)/*.c)

OBJ_DIR	=	.obj
OBJ	=	$(SRC:.c=.o)

%.o:	%.c $(LIB)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) 

lib:
	@make -C $(LIBFT_PATH)

$(NAME):: lib $(OBJ) $(OBJ_DIR)
	@$(CC) $(SRC) $(CFLAGS) $(LIBFT_LIB) -o $@
	@mv $(SRC_DIR)/*.o $(OBJ_DIR)

$(NAME)::
	@echo "$(GREEN)push_swap compiled$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(YELLOW)program push_swap deleted$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	make clean -C $(LIBFT_PATH)
	@echo "$(YELLOW)$(NAME) removed$(RESET)"

re: fclean all
	make fclean -C $(LIBFT_PATH)

.PHONY: all clean fclean re
