/*
** EPITECH PROJECT, 2022
** tool
** File description:
** tool
*/

#include <string.h>
#include "my.h"
#include "minishell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *set_equal(char **env, int i)
{
    char *new = malloc(sizeof(char *) + 1);
    int p = 0;

    while (env[i][p] != '\0') {
        new[p] = env[i][p];
        if (env[i][p] == '=')
            break;
        p++;
    }
    env[i] = new;
    free(new);
    return (env[i]);
}

void delete_params_env(char **env, char **command_array)
{
    int i = 0;

    for (; env[i]; i++) {
        if (my_strcmp(command_array[1], parse_env(env, i)) == 0) {
            set_equal(env, i);
            return;
        }
    }
    env[i] = command_array[1];
    env[i + 1] = NULL;
    concat_strings(env[i], "=");
}
