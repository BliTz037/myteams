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
#include "server_client.h"

typedef enum command
{
    LOGIN,
    LOGOUT,
    USER,
    USERS,
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
    char user_uuid[UUID_SIZE];
} user_t;

typedef struct send_s
{
    char body[MAX_BODY_LENGTH];
    char user_uuid[UUID_SIZE];
} send_t;

typedef struct message_s
{
    char user_uuid[UUID_SIZE];
} message_t;

typedef struct subscribe_s
{
    char team_uuid[UUID_SIZE];
} subscribe_t;

typedef struct teams_manipulation_s
{
    char team_description[MAX_DESCRIPTION_LENGTH];
    char team_uuid[UUID_SIZE];
    char team_name[MAX_NAME_LENGTH];
} teams_manipulation_t;

typedef struct channel_manipulation_s
{
    char channel_description[MAX_DESCRIPTION_LENGTH];
    char team_uuid[UUID_SIZE];
    char channel_name[MAX_NAME_LENGTH];
} channel_manipulation_t;

typedef struct thread_manipulation_s
{
    char thread_title[MAX_NAME_LENGTH];
    char thread_message[MAX_BODY_LENGTH];
    char team_uuid[UUID_SIZE];
    char channel_uuid[UUID_SIZE];
    time_t timestamp;
} thread_manipulation_t;

typedef struct message_manipulation_s
{
    char body[MAX_BODY_LENGTH];
    char team_uuid[UUID_SIZE];
    char channel_uuid[UUID_SIZE];
    char thread_uuid[UUID_SIZE];
} message_manipulation_t;

typedef enum service_type
{
    TEAMS,
    CHANNEL,
    THREAD,
    USER_INFO,
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
        info_t info;
    };
    command command;
} request_t;

typedef struct user_response_s
{
    user_info_t users[MAX_CLIENTS];
} user_response_t;

typedef struct subscribe_response_s
{
    char user_uuid[UUID_SIZE];
    char team_uuid[UUID_SIZE];
} subscribe_response_t;

typedef struct subscribed_response_s
{
    union {
        teams_manipulation_t teams[MAX_TEAMS];
        user_info_t users[MAX_TEAMS];
    };
} subscribed_response_t;

typedef struct thread_response_s
{
    char thread_uuid[UUID_SIZE];
    char thread_title[MAX_NAME_LENGTH];
    char thread_message[MAX_BODY_LENGTH];
    char user_uuid[UUID_SIZE];
    time_t timestamp;
} thread_response_t;

typedef struct comment_response_s
{
    char body[MAX_BODY_LENGTH];
    char team_uuid[UUID_SIZE];
    char thread_uuid[UUID_SIZE];
    char user_uuid[UUID_SIZE];
    time_t timestamp;
} comment_response_t;

typedef struct infos_response_s
{
    union{
        teams_manipulation_t teams[MAX_TEAMS];
        channel_manipulation_t channel[MAX_CHANNEL];
        thread_response_t thread[MAX_THREADS];
        comment_response_t comments[MAX_COMMENTS];
    };
    service_type type;
    int nb;
} infos_response_t;

typedef struct create_response_s
{
    union {
        teams_manipulation_t teams[MAX_TEAMS];
        channel_manipulation_t channel[MAX_CHANNEL];
        thread_response_t thread[MAX_THREADS];
        comment_response_t comments[MAX_COMMENTS];
    };
    int is_global_ping;
    service_type type;
} create_response_t;


typedef struct error_404_response_s
{
    char uuid[UUID_SIZE];
    service_type type;
} error_404_response_t;

typedef struct response_s
{
    union {
        user_response_t user;
        private_message_t message;
        subscribe_response_t subscribe;
        subscribed_response_t subscribed;
        infos_response_t infos;
        create_response_t create;
        error_404_response_t error_404;
    };
    int code;
    command command;
} response_t;

#endif /* !COMMUNICATION_H_ */
