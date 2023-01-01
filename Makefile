SRC_CLIENT	= client.c utils.c

SRC_SERVER	= server.c utils.c

OBJS_SERVER	= $(SRC_SERVER:.c=.o)

OBJS_CLIENT	= $(SRC_CLIENT:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

SERVER		= server

CLIENT		= client

all:		$(SERVER) $(CLIENT)

.c.o :
			$(CC) $(CFLAGS) -c $< -o $@

$(SERVER):	${OBJS_SERVER}
			make -C ./ft_printf
			$(CC) $(CFLAGS) ${OBJS_SERVER} -Lft_printf -lftprintf -o $(SERVER)

$(CLIENT):	${OBJS_CLIENT}	
			make -C ./ft_printf
			$(CC) $(CFLAGS) $(OBJS_CLIENT) -Lft_printf -lftprintf -o $(CLIENT)

bonus:	$(SERVER) $(CLIENT)

clean:
			make -C ./ft_printf clean
			rm -rf ${OBJS_CLIENT}
			rm -rf ${OBJS_SERVER}
			
fclean:		clean
			make -C ./ft_printf fclean
			rm -rf $(SERVER) $(CLIENT)

re:			fclean all

.PHONY:		all clean fclean re