/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** minishell1
*/

#ifndef MINISHELL1_H_
    #define MINISHELL1_H_

    #include "lib.h"

typedef struct env_key_value_s {
    char *env_var;
    char *env_value;
    struct env_key_value_s *next;
} env_key_value_t;

typedef struct builtins_s {
    char *command;
    int (*b_ins)(char **, env_key_value_t **, char **);
} builtins_t;

    char **get_args(char *str);

    int next_path(char *str);

    void reset_all(size_t *len, ssize_t *linesize, char *line);
    void free_args(char **args);

    env_key_value_t *list_env(char **env);
    char *find_in_env(env_key_value_t **env, char *to_find);
    char **env_transformation(env_key_value_t **env);

    int search_binary(char **command, env_key_value_t **env);
    void check_command(char **command, env_key_value_t **env, char **old_path);

    int cd_cmd(char **args, env_key_value_t **env, char **old_path);
    int env_cmd(char **args, env_key_value_t **env, char **old_path);
    int setenv_cmd(char **args, env_key_value_t **env, char **old_path);
    int unsetenv_cmd(char **args, env_key_value_t **env, char **old_path);
    int exit_cmd(char **args, env_key_value_t **env, char **old_path);

    int add_key_value(env_key_value_t **env, char *env_var, char *env_value);

    int minishell1(int ac, char **av, char **env);

#endif /* !MINISHELL1_H_ */
