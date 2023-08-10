
	# Library name #

NAME = minitalk
CLIENT = client
SERVER = server
BONUS_CLIENT = client_bonus
BONUS_SERVER = server_bonus
PRINTF = libftprintf.a
#HEADER = minitalk.h

	# Mandatory variables #

SRCC_FILES = client.c
SRCS_FILES = server.c
SRCC_BONUS_FILES = client_bonus.c
SRCS_BONUS_FILES = server_bonus.c

SRC_DIR = src/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
SRCC_BONUS = $(addprefix $(SRC_DIR), $(SRCC_BONUS_FILES))
SRCS_BONUS = $(addprefix $(SRC_DIR), $(SRCS_BONUS_FILES))

	# Compiling variables #

OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
OBJBC = ${SRCC_BONUS:.c=.o}
OBJBS = ${SRCS_BONUS:.c=.o}
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

bonus :	$(BONUS_CLIENT) $(BONUS_SERVER)

$(BONUS_CLIENT) : $(OBJBC)
					@make -C ft_printf
					$(CC) $(CFLAGS) $(OBJBC) $(INCLUDE) ft_printf/$(PRINTF) -o $(BONUS_CLIENT)

$(BONUS_SERVER) : $(OBJBS)
					@make -C ft_printf
					$(CC) $(CFLAGS) $(OBJBS) $(INCLUDE) ft_printf/$(PRINTF) -o $(BONUS_SERVER)

clean:
					@make clean -C ft_printf
					${RM} $(OBJC)
					${RM} $(OBJS)
					${RM} $(OBJBC)
					${RM} $(OBJBS)


fclean:	clean

					@make fclean -C ft_printf
					${RM} $(CLIENT)
					${RM} $(SERVER)
					${RM} $(BONUS_SERVER)
					${RM} $(BONUS_CLIENT)
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

