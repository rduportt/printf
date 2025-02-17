NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
HFILE = printf.h
CC = cc

SRCS =  ft_print_charac.c ft_print_decimal.c ft_print_hex.c ft_print_pointer.c ft_printf.c ft_utils.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) -I $(HFILE) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
