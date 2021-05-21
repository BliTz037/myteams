/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** communication
*/

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include "teams.h"
#include "server.h"

typedef enum command
{
    LOGIN,
    LOGOUT,
    USER,
    SEND,
    MESSAGES,
    SUBSCRIBE,
    SUBSCRIBED,
    UNSUBSCRIBE,
    CREATE,
    LIST,
    INFO
} command;

typedef struct login_s
{
    char username[MAX_NAME_LENGTH];
} login_t;

typedef struct user_s
{
    char user_uuid[36];
} user_t;

typedef struct send_s
{
    char user_uuid[36];
    char body[MAX_BODY_LENGTH];
} send_t;

typedef struct message_s
{
    char user_uuid[36];
} message_t;

typedef struct subscribe_s
{
    char team_uuid[36];
} subscribe_t;

typedef struct teams_manipulation_s
{
    char team_name[MAX_NAME_LENGTH];
    char team_description[MAX_DESCRIPTION_LENGTH];
} teams_manipulation_t;

typedef struct channel_manipulation_s
{
    char channel_name[MAX_NAME_LENGTH];
    char channel_description[MAX_DESCRIPTION_LENGTH];
    char team_uuid[36];
} channel_manipulation_t;

typedef struct thread_manipulation_s
{
    char thread_title[MAX_NAME_LENGTH];
    char thread_message[MAX_BODY_LENGTH];
    char team_uuid[36];
    char channel_uuid[36];
} thread_manipulation_t;

typedef struct message_manipulation_s
{
    char body[MAX_BODY_LENGTH];
    char team_uuid[36];
    char channel_uuid[36];
    char thread_uuid[36];
} message_manipulation_t;

typedef enum service_type
{
    TEAMS,
    CHANNEL,
    THREAD,
    MESSAGE,
} service_type;

typedef struct create_s
{
    union
    {
        teams_manipulation_t teams;
        channel_manipulation_t channel;
        thread_manipulation_t thread;
        message_manipulation_t messasge;
    };
    service_type type;
} create_t;

typedef struct list_s
{
    union
    {
        teams_manipulation_t teams;
        channel_manipulation_t channel;
        thread_manipulation_t thread;
        message_manipulation_t messasge;
    };
    service_type type;
} list_t;

typedef struct info_s
{
    union
    {
        teams_manipulation_t teams;
        channel_manipulation_t channel;
        thread_manipulation_t thread;
        message_manipulation_t messasge;
    };
    service_type type;
} info_t;

typedef struct request_s
{
    union
    {
        login_t login;
        user_t user;
        send_t send;
        message_t message;
        subscribe_t subcribe;
        create_t create;
        list_t list;
        info_t info;
    };
    int code;
    command command;
} request_t;

typedef struct user_info_s
{
    char uuid[36];
    char name[MAX_NAME_LENGTH];
} user_info_t;

typedef struct user_response_s
{
    user_info_t users[MAX_CLIENTS];
} user_response_t;

typedef struct messages_response_s
{
    char comments[MAX_COMMENTS][MAX_BODY_LENGTH];
} message_response_t;

typedef struct subscribed_response_s
{
    union{
        teams_t teams[MAX_TEAMS];
        user_info_t users[MAX_CLIENTS];
    };
} subscribed_response_t;

typedef struct infos_response_s
{
    union{
        teams_t teams[MAX_TEAMS];
        channel_t channel[MAX_CHANNEL];
        thread_t thread[MAX_THREADS];
        comment_t comments[MAX_COMMENTS];
    };
} infos_response_t;

typedef struct response_s
{
    union {
        user_response_t user;
        message_response_t message;
        subscribed_response_t subscribed;
        infos_response_t infos;
    };
    int code;
} response_t;

#endif /* !COMMUNICATION_H_ */
