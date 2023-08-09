
	# Library name #

NAME = minitalk
CLIENT = client
SERVER = server
HEADER = minitalk.h

	# Mandatory variables #

SRC = client.c server.c \

	# Compiling variables #

OBJ = ${SRC: .c = .o}
CC = cc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -f

	# ft_printf variables #

PRINTF_DIR = ./ft_printf
PRINTF = libftprintf.a


all: $(SERVER) $(CLIENT)

$(SERVER) : $(OBJ)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) $(HEADER) ft_printf/$(PRINTF) -o ($SERVER)

$(CLIENT) : $(OBJ)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) $(HEADER) ft_printf/$(PRINTF) -o ($CLIENT)

clean:
			@make clean -C ft_printf
			${RM} $(OBJ)


fclean: clean

			@make clean -C ft_printf
			${RM} $(CLIENT)
			${RM} $(SERVER)
			${RM} $(PRINTF)

re: fclean all

.PHONY: all clean fclean re


 
#include
#
#INCL_DIRS = -I -I$(PRINTF_DIRECTORY)
#.c.o:
#	${CC} ${CCFLAGS} $(INCL_DIRS) -c $< -o ${<:.c=.o}

#$(OBJ): $(SRC) minitalk.h

#$(NAME):
#	make -C $(PRINTF_DIRECTORY)
#	$(CC) $(CCFLAGS) $(INCL_DIRS) -I. -c $(SRC)
#	ar rcs $(NAME) $(OBJ)
#	ranlib $(NAME)


#printf:
#		make -C printf
#clean:
#	@ $(RM) $(CLIENT) $(SERVER)
# 	@printf "$(_INFO) client removed.\n"
# 	@printf "$(_INFO) server removed.\n"
#
#fclean: clean
#	@ $(MAKE) fclean -C $(PRINTF_DIR)
#	@ $(RM) $(CLIENT) $(SERVER)
#     @printf "$(_INFO) client removed.\n"
#     @printf "$(_INFO) server removed.\n"

