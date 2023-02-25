/*
** EPITECH PROJECT, 2022
** env_transformation
** File description:
** env_transformation
*/

#include "minishell1.h"

static int get_len(env_key_value_t *env)
{
    env_key_value_t *tmp = env;
    int count = 0;

    while (tmp != NULL) {
        ++count;
        tmp = tmp->next;
    }
    return count;
}

char **env_transformation(env_key_value_t **env)
{
    env_key_value_t *tmp = *env;
    int length = get_len(tmp);
    char **new_env = malloc(sizeof(char *) * (length + 1));
    int k = 0;
    char *env_var_dup = NULL;

    while (tmp != NULL) {
        env_var_dup = malloc(sizeof(char) * (my_strlen(tmp->env_var) + \
        my_strlen(tmp->env_value) + 2));
        my_strcpy(env_var_dup, tmp->env_var);
        my_strcpy(env_var_dup + my_strlen(tmp->env_var), "=");
        my_strcpy(env_var_dup + my_strlen(tmp->env_var) + 1, tmp->env_value);
        new_env[k] = env_var_dup;
        ++k;
        tmp = tmp->next;
    }
    new_env[k] = NULL;
    return new_env;
}
