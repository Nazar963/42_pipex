# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 18:12:50 by naal-jen          #+#    #+#              #
#    Updated: 2022/12/16 17:25:21 by naal-jen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
CFILES = new_pipex.c handle_error.c utils.c
OFILES = new_pipex.o handle_error.o utils.o

all: libft.a pipex.a $(NAME)

libft.a:
	cd libft; \
	make

pipex.a:
	$(CC) -c $(CFILES); \
	ar -rcs pipex.a $(OFILES)

$(NAME): $(OFILES)
	$(CC) $(OFILES) libft/libft.a pipex.a -o $(NAME)

$(OFILES): $(CFILES)
	$(CC) $(CFLAGS) $(CFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm pipex; \
	rm pipex.a; \
	cd libft; \
	make fclean

re: fclean all

.PHONY: all clean fclean re
