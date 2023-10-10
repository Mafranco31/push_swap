# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 15:03:30 by mafranco          #+#    #+#              #
#    Updated: 2023/10/10 12:31:45 by mafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

LIB	=	include/push_swap.h

CC		= cc

CFLAGS		= -Wall -Werror -Wextra -I.

RM		= rm -f

LIBFT_PATH = ./libft/
LIBFT	=	-L./libft -lft

GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RESET		= \033[0m

SRC_DIR	=	src
SRC		= src/algo.c src/makelist.c src/printlist.c src/push_swap.c \
		src/rules/error.c src/rules/push.c src/rules/rotate.c \
		src/rules/swap.c src/start/bullestart.c src/start/bullestart4.c \
		src/start/bullestart5.c src/getparts.c src/sortinb.c src/sortina.c

OBJ	=	$(SRC:.c=.o)

%.o:	%.c $(LIB)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) 

lib:
	@make -C $(LIBFT_PATH)

$(NAME): lib $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) $(LIBFT) -o $@
	@echo "$(GREEN)push_swap compiled$(RESET)"

clean:
	@$(RM) -r $(SRC_DIR)/*.o $(SRC_DIR)/rules/*.o $(SRC_DIR)/start/*.o
	@make clean -C $(LIBFT_PATH)
	@echo "$(YELLOW)objects push_swap deleted$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(YELLOW)$(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
