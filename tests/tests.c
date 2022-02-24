/*
** EPITECH PROJECT, 2022
** B-PSU-101-NAN-1-1-minishell1-andreas.le-tanter
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"
#include "../include/my.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

char **mem_alloc_2d_array(int nb_args)
{
    char **two_d_array = malloc(sizeof(char *) * nb_args);
    int i = 0;

    for (; i < nb_args; i++) {
        two_d_array[i] = malloc(sizeof(char) * nb_args);
    }
    return (two_d_array);
}

Test(delete_backspace_1, exit_code, .init=redirect_all_stdout)
{
    char *str = "coucou\n";

    cr_assert_eq(delete_backspace(str), 6);
}

Test(delete_backspace_2, exit_code, .init=redirect_all_stdout)
{
    char *str = "coucou";

    cr_assert_eq(delete_backspace(str), 6);
}

Test(error_code, exit_code, .init=redirect_all_stdout)
{
    char *str = malloc(sizeof(char *) + 1);
    char **env_tcsh = create_env();
    global_s global;
    error_code_handle(5, "test", &global);
 
    cr_assert_stdout_eq_str("Permission denied.\n");
    free(str);
    free(env_tcsh);
}

Test(error_code_1, exit_code, .init=redirect_all_stdout)
{
    char *str = malloc(sizeof(char *) + 1);
    char **env_tcsh = create_env();
    global_s global;
    error_code_handle(139, "test", &global);
 
    cr_assert_stdout_eq_str("Segmentation fault (core dumped)\n");
    free(str);
    free(env_tcsh);
}

Test(error_code_2, exit_code, .init=redirect_all_stdout)
{
    char *str = malloc(sizeof(char *) + 1);
    char **env_tcsh = create_env();
    global_s global;
    error_code_handle(136, "test", &global);
 
    cr_assert_stdout_eq_str("Floating point exception (core dumped)\n");
    free(str);
    free(env_tcsh);
}

Test(prompt, exit_code, .init=redirect_all_stdout)
{
    prompt();
    cr_assert_stdout_eq_str("[\e[1;34mB-PSU-101-NAN-1-1-minishell1-andreas.le-tanter\e[0m]\e[1;33m$> \e[0m");
}

Test(create_env, exit_code, .init=redirect_all_stdout)
{
    char **env = create_env();
    cr_assert_str_eq(env[1], "LOGNAME=atanter");
}

Test(create_env_2, exit_code, .init=redirect_all_stdout)
{
    char **env = create_env();
    cr_assert_str_eq(env[2], "USER=atanter");
}

Test(create_env_3, exit_code, .init=redirect_all_stdout)
{
    char **env = create_env();
    cr_assert_str_eq(env[3], "GROUP=atanter");
}
