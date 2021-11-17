# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halhashm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 15:38:59 by halhashm          #+#    #+#              #
#    Updated: 2021/11/16 15:39:02 by halhashm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -c -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = ft_printf.c \
		ft_printf_dt.c \
		ft_strlen.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_putnbr_base.c \
		ft_ullitoa_base.c \

OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
		ar cr $(NAME) $(OBJ)

.c.o:
		$(CC) $(FLAG) -g -c $< -o ${<:.c=.o}

clean:
		${RM} $(OBJ)

fclean: clean
		${RM} $(NAME)

re:		fclean all
