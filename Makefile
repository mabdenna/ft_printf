# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdenna <mabdenna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 07:04:48 by mabdenna          #+#    #+#              #
#    Updated: 2021/12/09 07:26:33 by mabdenna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_tohex.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_printf.c
OBJS = ${SRC:.c=.o}
NAME = libftprintf.a
CC = gcc 
FLAGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME): $(OBJS)

%.o: %.c 
	$(CC) $(FLAGS) -c $<
	ar rc $(NAME) $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f libftprintf.a
re: fclean all