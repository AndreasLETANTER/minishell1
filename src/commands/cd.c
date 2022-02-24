/*
** EPITECH PROJECT, 2022
** env
** File description:
** env
*/

#include <string.h>
#include "my.h"
#include "minishell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int check_cd(char **command_array, char *user, global_s *global)
{
    global->exit_code = 0;
    if (my_strcmp(command_array[0], "cd") == 0 && command_array[1] == 0) {
        chdir(user);
        return (0);
    } else if (my_strcmp(command_array[0], "cd") == 0) {
        if (chdir(command_array[1]) == -1) {
            write(2, command_array[1], my_strlen(command_array[1]));
            write(2, ": No such file or directory.\n", 29);
            global->exit_code = 1;
        }
    }
    return (0);
}