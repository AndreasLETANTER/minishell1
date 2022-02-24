/*
** EPITECH PROJECT, 2021
** my_functions
** File description:
** my_functions
*/

typedef struct global_t {
    int exit_code;
} global_s;


#ifndef MY_FUNCTIONS_H
    #define MY_FUNCTIONS_H
    #define _GNU_SOURCE

int analyze_input(char *buffer, char **env, global_s *global);

int delete_backspace(char *buffer);

int parse_command(char *buffer, char **env, global_s *global);

char *duplicate_string(char const *src);

char **split_string_cwd(char const *str);

char *concat_strings(char *dest, char const *src);

char **new_env(char **env);

void sig_handler(int sig);

void prompt(void);

char *get_user(char **env);

char *set_root(char *root);

void env_content(char **env);

void check_env(char **command_array, char **env, global_s *global);

void delete_params_env(char **env, char **command_array);

char *set_equal(char **env, int i);

char *parse_env(char **env, int i);

void check_unsetenv(char **command_array, char **env, global_s *global);

void parse_for_value_env(char **env, char **command_array);

void minishell(char **env, global_s *global);

int check_cd(char **command_array, char *user, global_s *global);

char **create_env(void);

char *add_group(char **env, char *last);

char *add_logname(char **env, char *last);

char *add_user(char **env, char *last);

char *add_path(char **env);

void free_array(char **array);

#endif
