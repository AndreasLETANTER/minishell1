/*
** EPITECH PROJECT, 2022
** unset
** File description:
** env
*/

#include <string.h>
#include "my.h"
#include "minishell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int command_array_len(char **command_array)
{
    int i = 0;

    while (command_array[i]) {
        i++;
    }
    return (i);
}

void delete_from_list(char **env, int i)
{
    while (env[i]) {
        if (env[i + 1] != 0) {
            env[i] = env[i + 1];
        } else {
            env[i] = 0;
        }
        i++;
    }
}

void parse_for_value_unsetenv(char **env, char **command_array)
{
    int command_len = command_array_len(command_array);
    int j = 1;

    for (int i = 0; env[i]; i++) {
        if (j == command_len) {
            break;
        }
        if (my_strcmp(command_array[j], parse_env(env, i)) \
        == 0 && j != command_len) {
            delete_from_list(env, i);
            i = 0;
            j++;
        }
    }
}

void check_unsetenv(char **command_array, char **env, global_s *global)
{
    global->exit_code = 0;
    if (my_strcmp(command_array[0], "unsetenv") == 0 && command_array[1] == 0){
        write(2, "unsetenv: Too few arguments.\n", 29);
        global->exit_code = 1;
    } else if (my_strcmp(command_array[0], "unsetenv") == 0) {
        parse_for_value_unsetenv(env, command_array);
    }
}
