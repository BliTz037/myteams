##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## The supreme makefile
##

## MAIN
MAIN_SERVER =	server/main.c
MAIN_CLI = cli/main.c

## SRC
SRC_SERVER	= 	server/server.c	\
				server/server_init.c	\
				server/server_command_buffer.c	\
				server/server_commands.c	\
				server/server_user_connection.c	\
				server/teams.c	\
				server/channel.c	\
				server/thread.c	\
				server/message.c	\

SRC_CLI	 =

## NAME
NAME_SERVER	=	myteams_server
NAME_CLI = myteams_cli

## OBJ
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)
OBJ_CLI	=	$(SRC_CLI:.c=.o)
OBJ_MAIN_SERVER	=	$(MAIN_SERVER:.c=.o)
OBJ_MAIN_CLI = 	$(MAIN_CLI:.c=.o)


CC		=	gcc

CPPFLAGS		+=	-Wall -Wextra -I include -I libs/myteams -g3

all: server cli

server:	$(NAME_SERVER)

$(NAME_SERVER): $(OBJ_MAIN_SERVER) $(OBJ_SERVER)
			$(CC) -o $(NAME_SERVER) $(OBJ_MAIN_SERVER) $(OBJ_SERVER) $(CPPFLAGS)

cli:	$(NAME_CLI)
$(NAME_CLI): 	$(OBJ_CLI) $(OBJ_MAIN_CLI)
					$(CC) -o $(NAME_CLI) $(OBJ_MAIN_CLI) $(OBJ_CLI) $(CPPFLAGS)

clean:
	rm -f $(OBJ_MAIN_SERVER)
	rm -f $(OBJ_MAIN_CLI)
	rm -f $(OBJ_SERVER)
	rm -f $(OBJ_CLI)

fclean:	clean
	rm -f $(NAME_SERVER)
	rm -f $(NAME_CLI)

re:	fclean	all

.PHONY: clean fclean re