# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguenel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 20:08:38 by aguenel           #+#    #+#              #
#    Updated: 2020/01/20 20:08:50 by aguenel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc -Wall -Wextra -Werror $(PRINTF_H)

PRINTF_H = -I includes/libftprintf.h

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

SRC= init.c\
printf_utils.c\
printf_utils_1.c\
printf.c\
printf_1.c\
ft_checkerror.c \
print_str.c \
print_char.c \
print_nbr.c \
print_x.c \
print_xx.c \
print_u.c \
print_p.c \
print_percent.c \
print_u1.c \
print_nbr1.c \


OBJ=$(SRC:.c=.o)

$(NAME): 
	$(CC) -c $(SRC)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY: clean, fclean










