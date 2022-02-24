/*
** EPITECH PROJECT, 2022
** handler
** File description:
** signal handler
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

void sig_handler(int sig)
{
    my_printf("\n");
    prompt();
}
