/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
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

int main(int argc, char **argv, char **env)
{
    global_s global;
    global.exit_code = 1;
    char **env_tcsh = 0;
    signal(SIGINT, sig_handler);
    if (env[0] != 0) {
        env_tcsh = new_env(env);
    } else {
        env_tcsh = create_env();
    }
    minishell(env_tcsh, &global);
    free(env_tcsh);
    return (0);
}
