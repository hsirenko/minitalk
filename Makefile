
	# Library name #

NAME = minitalk
CLIENT = client
SERVER = server
PRINTF = libftprintf.a
#HEADER = minitalk.h

	# Mandatory variables #

SRCC_FILES = client.c
SRCS_FILES = server.c

SRC_DIR = src/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))

	# Compiling variables #

OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I include
RM = rm -rf


	# ft_printf variables #

#PRINTF_DIR = ft_printf
#PRINTF = libftprintf.a


all:	$(CLIENT) $(SERVER)

#$(NAME): all

$(CLIENT)	:	$(OBJC)
					@make -C ft_printf
					$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) ft_printf/$(PRINTF) -o $(CLIENT)

$(SERVER)	:	$(OBJS)
					@make -C ft_printf
					$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) ft_printf/$(PRINTF) -o $(SERVER)

 #%.o: %.c
	#$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@

clean:
					@make clean -C ft_printf
					${RM} $(OBJC)
					${RM} $(OBJS)


fclean:	clean

					@make fclean -C ft_printf
					${RM} $(CLIENT)
					${RM} $(SERVER)
					${RM} $(PRINTF)
			#${RM} $(CLIENT)
			#${RM} $(SERVER)


re :	fclean all

.PHONY:		all clean fclean re


 
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

