/*
** EPITECH PROJECT, 2022
** my_exec
** File description:
** my_exec
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

void prompt(void)
{
    char cwd[4096];
    char **path;
    char *new_cwd;
    char *last;

    getcwd(cwd, 4096);
    last = new_cwd = strtok(cwd, "/");
    for (;(new_cwd = strtok(NULL, "/")) != NULL; last = new_cwd);

    my_printf("[\e[1;34m%s\e[0m]", last);
    my_putstr("\e[1;33m$> \e[0m");
}

char *delete_first_space(char *buffer)
{
    int first_space = 0;
    int p = 0;
    char *new_str = malloc(sizeof(char) * my_strlen(buffer));

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] != ' ') {
            first_space = 1;
        }
        if (first_space == 1) {
            new_str[p] = buffer[i];
            p++;
        }
    }
    new_str[p] = '\0';
    free(buffer);
    return (new_str);
}

void get_input(char **env, global_s *global)
{
    size_t bufsize = 50;
    char *buffer = 0;

    if (getline(&buffer, &bufsize, stdin) == -1) {
        if (isatty(0) == 1)
            my_putstr("exit\n");
        free(env);
        exit(global->exit_code);
    }
    if (buffer[0] == ' ') {
        buffer = delete_first_space(buffer);
    }
    buffer[delete_backspace(buffer)] = '\0';
    analyze_input(buffer, env, global);
    free(buffer);
}

void minishell(char **env, global_s *global)
{
    if (isatty(0) == 1)
        prompt();
    get_input(env, global);
    minishell(env, global);
}
