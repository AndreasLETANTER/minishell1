/*
** EPITECH PROJECT, 2022
** execute
** File description:
** execute
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
#include <errno.h>

int execute_command(char **command_array, char **env)
{
    char command[50] = "/bin/";
    if (my_strcmp(command_array[0], "cd") == 0 || command_array[0] == 0)
        return (0);
    char *new_command = command_array[0];
    concat_strings(command, command_array[0]);
    execve(command, command_array, env);
    if (errno == ENOENT) {
        execve(new_command, command_array, env);
        write(2, command_array[0], my_strlen(command_array[0]));
        write(2, ": Command not found.\n", 21);
        return (1);
    }
    free_array(command_array);
    return (0);
}

int error_code_handle(int child_status, char *buffer, global_s *global)
{
    switch (child_status) {
    case 139:
        my_printf("Segmentation fault (core dumped)\n");
        break;
    case 136:
        my_printf("Floating point exception (core dumped)\n");
        break;
    case 5:
        my_printf("Permission denied.\n");
        global->exit_code = 1;
        break;
    default:
        break;
    }
}

int parse_command(char *buffer, char **env, global_s *global)
{
    char **command_array = split_string(buffer);
    int child_pid = fork();
    int child_status;
    int i = 0;

    if (child_pid > 0) {
        waitpid(child_pid, &child_status, 0);
        error_code_handle(child_status, buffer, global);
        free_array(command_array);
        if (WIFEXITED(child_status))
            global->exit_code = WEXITSTATUS(child_status);
    } else {
        global->exit_code = execute_command(command_array, env);
        exit(global->exit_code);
    }
    return (global->exit_code);
}
