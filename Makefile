# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 09:17:57 by hrhirha           #+#    #+#              #
#    Updated: 2019/12/10 09:30:02 by hrhirha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_NAME = libft.a
CC_FLAGS = gcc -Wall -Wextra -Werror
SRCS = *.c
OBJS = *.o

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft/
	@cp -rf libft/$(LIBFT_NAME) ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS) : $(SRCS)
	@$(CC_FLAGS) -c $(SRCS)

clean :
	@make clean -C libft/
	@rm -rf *.o

fclean : clean
	@make fclean -C libft/
	@rm -rf *.a

re : fclean all
