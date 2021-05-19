/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** communication
*/

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include "teams.h"

typedef enum command
{
    HELP,
    LOGIN,
    LOGOUT,
    USERS,
    USER,
    SEND,
    MESSAGES,
    SUBSCRIBE,
    SUBSCRIBED,
    UNSUBSCRIBE,
    USE,
    CREATE,
    LIST,
    INFO,
} command;

typedef struct request_s
{
    union
    {
        char name[MAX_NAME_LENGTH];
        char body[MAX_BODY_LENGTH];
        char description[MAX_DESCRIPTION_LENGTH];
        int team_uuid;
    };
    int code;
    command command;
    int user_uuid;
    int channel_uuid;
    int thread_uuid;
} request_t;

typedef struct response_s
{
    int code;
    char response[4096];

} response_t;

#endif /* !COMMUNICATION_H_ */
