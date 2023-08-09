NAME = libftprintf.a
CC= cc
CFLAGS= -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
SRC = printf_utils.c printf_hex_utils.c printf.c printf_ptr_hex.c \


.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

HEADER = printf.h

all: $(NAME)

$(OBJ): $(SRC) printf.h

$(NAME):
	$(CC) $(CFLAGS) -I. -c $(SRC)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re