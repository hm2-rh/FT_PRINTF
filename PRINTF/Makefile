NAME = libftprintf.a
LIBFT_NAME = libft.a
CC_FLAGS = gcc -Wall -Wextra -Werror
SRCS = *.c
OBJS = *.o

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "-------------- MAKING libftprintf.a -----------------"
	@make -C libft/
	@cp -rf libft/$(LIBFT_NAME) ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS) : $(SRCS)
	@$(CC_FLAGS) -c $(SRCS)

clean :
	@echo "---------------- CLEANING OBJECTS -------------------"
	@make clean -C libft/
	@rm -rf *.o

fclean : clean
	@echo "--------------- CLEANING EVERYTHING -----------------"
	@make fclean -C libft/
	@rm -rf *.a

re : fclean all
