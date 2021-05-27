##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## The supreme makefile
##

## MAIN
MAIN_SERVER =	server/main.c
MAIN_CLI = 	cli/main.c	\

## SRC
SRC_SERVER	= 	server/server_handling/server.c	\
				server/server_handling/server_init.c	\
				server/server_handling/server_user_connection.c	\
				server/teams/add_teams.c	\
				server/teams/teams_list.c	\
				server/teams/teams_info.c	\
				server/channels/add_channel.c	\
				server/channels/channels_info.c	\
				server/channels/channels_list.c	\
				server/threads/add_thread.c	\
				server/threads/threads_list.c	\
				server/threads/threads_info.c	\
				server/messages/add_message.c	\
				server/messages/add_message_ping.c	\
				server/messages/messages_list.c	\
				server/requests/login.c	\
				server/requests/request.c	\
				server/requests/create.c	\
				server/requests/info_list.c	\
				server/requests/subscribe.c	\
				server/requests/subscribed.c	\
				server/requests/subscribed_users.c	\
				server/requests/user.c	\
				server/requests/send.c	\
				server/requests/messages.c	\
				server/save.c	\
				server/uuid.c	\

SRC_CLI	 =		cli/command/create.c	\
				cli/command/info.c	\
				cli/command/list.c	\
				cli/command/login.c	\
				cli/command/logout.c	\
				cli/command/messages.c	\
				cli/command/send.c	\
				cli/command/subscribe.c	\
				cli/command/subscribed.c	\
				cli/command/unsubscribed.c	\
				cli/command/user.c	\
				cli/command/use.c	\
				cli/command/help.c \
				cli/response/create.c \
				cli/response/info.c \
				cli/response/list.c \
				cli/response/login.c \
				cli/response/logout.c \
				cli/response/messages.c \
				cli/response/send.c \
				cli/response/subscribe.c \
				cli/response/subscribed.c \
				cli/response/unsubscribed.c \
				cli/response/user.c \
				cli/response/error.c \
				cli/socket.c \
				cli/server.c \
				cli/str_to_word_array.c \
				cli/parser.c

## NAME
NAME_SERVER	=	myteams_server
NAME_CLI = myteams_cli

## OBJ
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)
OBJ_CLI	=	$(SRC_CLI:.c=.o)
OBJ_MAIN_SERVER	=	$(MAIN_SERVER:.c=.o)
OBJ_MAIN_CLI = 	$(MAIN_CLI:.c=.o)


CC		=	gcc

CPPFLAGS		+=	-L./libs/myteams -Wall -Wextra -I include -I libs/myteams -lmyteams -luuid -g3

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