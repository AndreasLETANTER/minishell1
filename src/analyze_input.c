/*
** EPITECH PROJECT, 2022
** analyze
** File description:
** analyze
*/

#include <string.h>
#include "my.h"
#include "minishell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int parse_my_command(char *buffer, char **env, global_s *global)
{
    char **command_array = split_string(buffer);
    char *user = get_user(env);
    int i = 0;

    if (my_strcmp(command_array[0], "cd") == 0) {
        if (check_cd(command_array, user, global) == 0) {
            return (0);
        }
    }
    if (my_strcmp(command_array[0], "setenv") == 0) {
        check_env(command_array, env, global);
    } else if (my_strcmp(command_array[0], "unsetenv") == 0) {
        check_unsetenv(command_array, env, global);
    } else {
        free(user);
        return (1);
    }
    free(user);
    return (0);
}

int analyze_input(char *buffer, char **env, global_s *global)
{
    char *exit_command = "exit";

    if (buffer[0] == '\0')
        return (global->exit_code);
    if (parse_my_command(buffer, env, global) == 0) {
        return (global->exit_code);
    } else if (my_strcmp(buffer, exit_command) == 0) {
        my_printf("exit\n");
        free(env);
        exit(global->exit_code);
    }
    if (parse_command(buffer, env, global) == 0) {
        return (global->exit_code);
    }
    return (global->exit_code);
}

int delete_backspace(char *buffer)
{
    int i = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            return (i);
        }
        i++;
    }
    return (i);
}
