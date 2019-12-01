# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/01 14:16:49 by hrhirha           #+#    #+#              #
#    Updated: 2019/12/01 14:16:52 by hrhirha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = *.c
OBJ = *.o

all : $(NAME)

$(NAME) : $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

$(OBJ) : $(SRC)
		@make -C libft/
		@$(CC) $(FLAGS) -c $(SRC) libft/*.c

clean :
		@make clean -C libft/
		@rm -rf *.o

fclean : clean
		@make fclean -C libft/
		@rm -rf *.a

re : fclean $(NAME)
