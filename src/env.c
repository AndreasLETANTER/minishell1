/*
** EPITECH PROJECT, 2022
** env
** File description:
** env
*/

#include "minishell.h"
#include "my.h"
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **new_env(char **env)
{
    char **new_env;
    int i = 0;
    new_env = malloc(sizeof(char *) * (get_nb_arg(env, i) * 2));

    for (;env[i];) {
        new_env[i] = env[i];
        i++;
    }
    new_env[i] = NULL;
    return (new_env);
}

char *set_root(char *root)
{
    root[0] = '/';
    root[1] = 'h';
    root[2] = 'o';
    root[3] = 'm';
    root[4] = 'e';
    root[5] = '\0';
    return (root);
}

int seek_user_in_env(char **env, int i)
{
    for (int p = 0; env[i][p]; p++) {
        if (env[i][p] == 'U' && env[i][p + 1] == 'S' && env[i][p + 2] \
        == 'E' && env[i][p + 3] == 'R' && p <= 4) {
            return (i);
        }
    }
    return (-84);
}

int get_user_from_env(char **env)
{
    for (int i = 0; env[i]; i++) {
        if (seek_user_in_env(env, i) != -84) {
            return (i);
        }
    }
}

char *get_user(char **env)
{
    char *user = malloc(sizeof(char *) + 1);
    char *root = malloc(sizeof(char *) * 2);
    root = set_root(root);
    int detect = 0;

    user[0] = '/';
    for (int i = 0; env[get_user_from_env(env)][i]; i++) {
        if (env[get_user_from_env(env)][i - 1] == '=') {
            detect = 1;
        }
        if (detect >= 1) {
            user[detect] = env[get_user_from_env(env)][i];
            detect++;
        }
    }
    user[detect] = '\0';
    concat_strings(root, user);
    free(user);
    return (root);
}
