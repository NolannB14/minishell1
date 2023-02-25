/*
** EPITECH PROJECT, 2022
** env
** File description:
** env
*/

#include "minishell1.h"

int env_cmd(char **args, env_key_value_t **env, char **old_path)
{
    env_key_value_t *tmp = *env;

    while (tmp) {
        if (tmp->env_value)
            my_printf("%s=%s\n", tmp->env_var, tmp->env_value);
        else
            my_printf("%s=\n", tmp->env_var);
        tmp = tmp->next;
    }
    return 0;
}
