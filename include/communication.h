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
    int user_uuid;
} user_t;

typedef struct send_s
{
    int user_uuid;
    char body[MAX_BODY_LENGTH];
} send_t;

typedef struct message_s
{
    int user_uuid;
} message_t;


typedef struct subscribe_s
{
    int team_uuid;
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
    int team_uuid;
} channel_manipulation_t;

typedef struct thread_manipulation_s
{
    char thread_title[MAX_NAME_LENGTH];
    char thread_message[MAX_BODY_LENGTH];
    int team_uuid;
    int channel_uuid;
} thread_manipulation_t;

typedef struct message_manipulation_s
{
    char body[MAX_BODY_LENGTH];
    int team_uuid;
    int channel_uuid;
    int thread_uuid;
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

typedef struct response_s
{
    int code;
    char response[4096];

} response_t;

#endif /* !COMMUNICATION_H_ */
