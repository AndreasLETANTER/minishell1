/*
** EPITECH PROJECT, 2022
** setenv
** File description:
** setenv
*/

#include <string.h>
#include "my.h"
#include "minishell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void env_content(char **env)
{
    for (int i = 0; env[i]; i++) {
        my_printf("%s\n", env[i]);
    }
}

char *set_value_env(char **env, char **command_array, int i)
{
    char *new = malloc(sizeof(char *) * 2);
    int p = 0;
    int j = 0;

    while (env[i][p] != '\0') {
        new[p] = env[i][p];
        p++;
    }
    while (command_array[2][j] != '\0') {
        new[p] = command_array[2][j];
        j++;
        p++;
    }
    p = 0;
    while (new[p] != '\0') {
        env[i][p] = new[p];
        p++;
    }
    free(new);
    return (env[i]);
}

char *parse_env(char **env, int i)
{
    int p = 0;
    int space_found = 0;
    char *new = duplicate_string(env[i]);

    while (new[p] != '\0') {
        if (new[p] == '=') {
            space_found = 1;
        }
        if (space_found == 1) {
            new[p] = '\0';
        }
        p++;
    }
    return (new);
}

void parse_for_value_env(char **env, char **command_array)
{
    int i = 0;

    for (; env[i]; i++) {
        if (my_strcmp(command_array[1], parse_env(env, i)) == 0) {
            set_equal(env, i);
            set_value_env(env, command_array, i);
            break;
        }
    }
    env[i] = command_array[1];
    concat_strings(env[i], "=");
    concat_strings(env[i], command_array[2]);
    i++;
    env[i] = NULL;
}

void check_env(char **command_array, char **env, global_s *global)
{
    int arg = get_nb_arg(command_array, 0);
    global->exit_code = 0;

    if (my_strcmp(command_array[0], "setenv") == 0 && arg == 0){
        env_content(env);
    } else if (my_strcmp(command_array[0], "setenv") \
    == 0 && arg == 1) {
        delete_params_env(env, command_array);
    }
    if (my_strcmp(command_array[0], "setenv") == 0 && arg == 2) {
        parse_for_value_env(env, command_array);
    }
    if (arg > 2) {
        write(2, "setenv: Too many arguments.\n", 28);
        global->exit_code = 1;
    }
}
