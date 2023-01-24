# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 18:12:50 by naal-jen          #+#    #+#              #
#    Updated: 2023/01/24 18:18:22 by naal-jen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

CFILES = pipex.c handle_error.c utils.c
OFILES = $(CFILES:.c=.o)

all: libft.a pipex.a $(NAME)

libft.a:
	$(MAKE) -C libft

pipex.a:
	$(CC) -c $(CFILES); \
	ar -rcs pipex.a $(OFILES)

$(NAME): $(OFILES)
	$(CC) $(OFILES) libft/libft.a pipex.a -o $(NAME)

%.o: %.c
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm pipex; \
	rm pipex.a; \
	cd libft; \
	make fclean

re: fclean all


.PHONY: all clean fclean re
