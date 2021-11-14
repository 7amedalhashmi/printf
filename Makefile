FLAG = -Wall -Werror -Wextra

NAME = printf.a

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
		ar rcsv $(NAME) $(OBJ)

.c.o:
		$(CC) $(FLAG) -g -c $< -o ${<:.c=.o}

clean:
		${RM} $(OBJ)

fclean: clean
		${RM} $(NAME)

re:		fclean all