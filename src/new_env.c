/*
** EPITECH PROJECT, 2022
** B-PSU-101-NAN-1-1-minishell1-andreas.le-tanter
** File description:
** new_env
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

char *add_path(char **env)
{
    char *dest = malloc(sizeof(char) * 100);
    char cwd[4096];

    dest[0] = 'P';
    dest[1] = 'A';
    dest[2] = 'T';
    dest[3] = 'H';
    dest[4] = '=';

    env[0] = concat_strings(dest, getcwd(cwd, 4096));
    return (env[0]);
}

char *add_user(char **env, char *last)
{
    char *dest_2 = malloc(sizeof(char) * 100);

    dest_2[0] = 'U';
    dest_2[1] = 'S';
    dest_2[2] = 'E';
    dest_2[3] = 'R';
    dest_2[4] = '=';

    env[2] = concat_strings(dest_2, last);
    return (env[2]);
}

char *add_logname(char **env, char *last)
{
    char *dest_1 = malloc(sizeof(char) * 100);

    dest_1[0] = 'L';
    dest_1[1] = 'O';
    dest_1[2] = 'G';
    dest_1[3] = 'N';
    dest_1[4] = 'A';
    dest_1[5] = 'M';
    dest_1[6] = 'E';
    dest_1[7] = '=';

    env[1] = concat_strings(dest_1, last);
    return (env[1]);
}

char *add_group(char **env, char *last)
{
    char *dest_3 = malloc(sizeof(char) * 100);

    dest_3[0] = 'G';
    dest_3[1] = 'R';
    dest_3[2] = 'O';
    dest_3[3] = 'U';
    dest_3[4] = 'P';
    dest_3[5] = '=';

    env[3] = concat_strings(dest_3, last);
    return (env[3]);
}

char **create_env(void)
{
    char **new_env = malloc(sizeof(char *) * 50);
    char *last;
    char *new_cwd;
    char cwd[4096];

    getcwd(cwd, 4096);
    last = strtok(cwd, "/");
    last = strtok(NULL, "/");
    new_env[0] = add_path(new_env);
    new_env[1] = add_logname(new_env, last);
    new_env[2] = add_user(new_env, last);
    new_env[3] = add_group(new_env, last);
    new_env[4] == NULL;
    return (new_env);
}
