/*
** EPITECH PROJECT, 2022
** setenv
** File description:
** setenv
*/

#include "minishell1.h"

static int not_alphanumeric(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!IS_LETTER(str[i]) && !IS_NUM(str[i]))
            return 0;
    }
    return 1;
}

static int setenv_errors(char **args)
{
    char **temp_args = args;
    int len_args = 0;

    for (; *temp_args; temp_args++)
        len_args++;
    if (len_args > 3) {
        my_printf("setenv: Too many arguments.\n");
        return 84;
    }
    if (args[1] && !IS_LETTER(args[1][0])) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return 84;
    } else if (!not_alphanumeric(args[1])) {
        my_printf(
            "setenv: Variable name must contain alphanumeric characters.\n");
        return 84;
    }
    return 0;
}

static int modify_env(env_key_value_t **env, char **args)
{
    env_key_value_t *tmp = *env;

    while (tmp) {
        if (!my_strcmp(tmp->env_var, args[1])) {
            tmp->env_value = my_strdup(args[2]);
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

static int in_env(env_key_value_t **env, char **args)
{
    env_key_value_t *tmp = *env;

    while (tmp) {
        if (!my_strcmp(tmp->env_var, args[1])) {
            modify_env(env, args);
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int setenv_cmd(char **args, env_key_value_t **env, char **old_path)
{
    if (!args[1]) {
        env_cmd(args, env, old_path);
        return 0;
    }
    if (setenv_errors(args) == 84)
        return 84;
    else if (!in_env(env, args))
        add_key_value(env, my_strdup(args[1]), my_strdup(args[2]));
    return 0;
}
