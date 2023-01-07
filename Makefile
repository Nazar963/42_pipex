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
NAME_BONUS = pipex_bonus
CFILES = pipex.c handle_error.c utils.c
OFILES = pipex.o handle_error.o utils.o

BONUS_CFILES = pipex_bonus.c handle_error_bonus.c utils_bonus.c
BONUS_OFILES = pipex_bonus.o handle_error_bonus.o utils_bonus.o

all: libft.a pipex.a $(NAME)

bonus: get_next_line.a libft.a pipex_bonus.a $(NAME_BONUS)

libft.a:
	cd libft; \
	make

get_next_line.a:
	cd 42_get_next_line; \
	gcc -c get_next_line.c get_next_line_utils.c; \
	ar -rcs get_next_line.a get_next_line.o get_next_line_utils.o; \

pipex.a:
	$(CC) -c $(CFILES); \
	ar -rcs pipex.a $(OFILES)

pipex_bonus.a:
	$(CC) -c $(BONUS_CFILES); \
	ar -rcs pipex_bonus.a $(BONUS_OFILES)

$(NAME): $(OFILES)
	$(CC) $(OFILES) libft/libft.a pipex.a -o $(NAME)

$(OFILES): $(CFILES)
	$(CC) $(CFLAGS) $(CFILES)

$(NAME_BONUS): $(BONUS_OFILES)
	$(CC) $(BONUS_OFILES) 42_get_next_line/get_next_line.a libft/libft.a pipex_bonus.a -o $(NAME_BONUS)

$(BONUS_OFILES): $(BONUS_CFILES)
	$(CC) $(CFLAGS) $(BONUS_CFILES)

clean:
	rm -f $(OFILES) && rm -f $(BONUS_OFILES)

fclean: clean
	rm pipex; \
	rm pipex_bonus; \
	rm pipex.a; \
	rm pipex_bonus.a; \
	cd libft; \
	make fclean

re: fclean all


.PHONY: all clean fclean re
