# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 22:37:44 by yonamog2          #+#    #+#              #
#    Updated: 2022/12/24 19:18:49 by yonamog2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

.SILENT:

FILES = main.c added.c

OBJ = $(FILES:.c=.o)

CC = gcc -g

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)
	tput setaf 3
	printf "RUN PIPEX\n"
	tput setaf 7
%.o : %.c
	$(CC) -c $(CFLAGS) $?
	
$(NAME): $(OBJ)
	tput setaf 3
	printf "COMPILING!\n"
	tput setaf 7
	cd ft_printf && make
	$(CC) $(OBJ) $(CFLAGS) ./ft_printf/libft.a -o $(NAME)
	tput setaf 3
	printf "done compiling!\n"
	tput setaf 7

clean: 
	tput setaf 1
	printf "Cleaning!\n"
	tput setaf 7
	cd ft_printf && make clean
	rm -f $(OBJ)

fclean: clean
	cd ft_printf && make fclean
	rm -f $(NAME)
	tput setaf 3
	printf "done cleaning!\n"
	tput setaf 7

re: fclean all

.PHONY: all clean fclean re