/*
** EPITECH PROJECT, 2021
** B-NWP-400-PAR-4-1-myteams-tom.rives
** File description:
** communication
*/

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

typedef enum command
{
    USE,
} command;

typedef struct request_s
{
    int code;
    command command;
    char parameters[4096];

} request_t;

typedef struct response_s
{
    int code;
    char response[4096];

} response_t;

#endif /* !COMMUNICATION_H_ */
