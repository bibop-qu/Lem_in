# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afollin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/07 17:30:21 by afollin           #+#    #+#              #
#    Updated: 2016/03/17 19:53:45 by basle-qu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			attention a bien virer le -g
GCC =		gcc -Wall -Werror -Wextra -g
NAME =		lem-in
SRC =	srcs/main.c srcs/tools.c srcs/init.c srcs/verif.c srcs/struct_tools.c srcs/print.c srcs/resolve.c

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

lem-in:		$(OBJ)
			make -C libft
			$(GCC) -I includes -Ilibft/includes/ -I. -o lem-in $(OBJ) libft/libft.a

main.o:		lemin.h

%.o:		%.c
			$(GCC) -I includes -Ilibft/includes/ -I. -o $@ -c $<

.PHONY:		clean fclean re

clean:
			rm -rf $(OBJ)
			make clean -C libft/

fclean:
			rm -rf $(OBJ)
			rm -rf $(NAME)
			make fclean -C libft/

re:			fclean $(NAME)
