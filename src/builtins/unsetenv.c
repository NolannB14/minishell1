/*
** EPITECH PROJECT, 2022
** unsetenv
** File description:
** unsetenv
*/

#include "minishell1.h"

static void remove_node(env_key_value_t **env, char *env_var)
{
    env_key_value_t *tmp = *env;
    env_key_value_t *next_node = NULL;

    while (my_strcmp(tmp->next->env_var, env_var) != 0)
        tmp = tmp->next;
    next_node = tmp->next->next;
    free(tmp->next->env_var);
    free(tmp->next->env_value);
    free(tmp->next);
    tmp->next = next_node;
}

static void browse_list(env_key_value_t **env, char *args_i)
{
    env_key_value_t *tmp = *env;

    while (tmp) {
        if (!my_strcmp(tmp->env_var, args_i))
            remove_node(env, args_i);
        tmp = tmp->next;
    }
}

int unsetenv_cmd(char **args, env_key_value_t **env, char **old_path)
{
    if (!args[1]) {
        my_printf("unsetenv: Too few arguments.\n");
        return 1;
    }
    for (int i = 1; args[i]; i++)
        browse_list(env, args[i]);
    return 0;
}
