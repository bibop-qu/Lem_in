#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/07 16:41:17 by basle-qu          #+#    #+#              #
#    Updated: 2016/03/11 17:51:51 by basle-qu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS =	srcs/main.c srcs/tools.c srcs/init.c srcs/verif.c srcs/struct_tools.c srcs/print.c srcs/resolve.c
OBJS =	main.o tools.o init.o verif.o struct_tools.o print.o resolve.o
NAME = lem-in 
CFLAG = -Wall -Wextra -Werror

.PHONY: all $(NAME) test clean fclean re

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@make -C libft/ clean	
	@gcc -I includes -c $(CFLAG) $(SRCS)
	@gcc -I includes -L libft/ -lft $(OBJS) -o $(NAME)
	@echo "\033[1;36m##########   LEM-IN OK  ##########\033[00m"
	@make clean

test: fclean
	@gcc -I includes -c $(CFLAG) -g $(SRCS)
	@gcc -I includes -L libft/ -lft $(OBJS) -o $(NAME)
	@echo "\033[1;36m##########   LEM-IN OK  ##########\033[00m"
	@make clean

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

cleanall: fclean
	@make -C libft/ fclean

re: fclean $(NAME)
