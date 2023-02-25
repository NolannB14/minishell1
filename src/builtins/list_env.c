/*
** EPITECH PROJECT, 2022
** list_env
** File description:
** list_env
*/

#include "minishell1.h"

static int get_length_key(char *env_line)
{
    int i = 0;

    for (; env_line[i] != '=' && env_line[i] != '\0'; i++);
    return i;
}

int add_key_value(env_key_value_t **env, char *env_var, char *env_value)
{
    env_key_value_t *node = malloc(sizeof(env_key_value_t));
    env_key_value_t *lnode;

    if (node == NULL)
        return 84;
    node->env_var = env_var;
    node->env_value = env_value;
    node->next = NULL;
    if (*env == NULL) {
        *env = node;
    } else {
        lnode = *env;
        while (lnode->next != NULL)
            lnode = lnode->next;
        lnode->next = node;
    }
    return 0;
}

env_key_value_t *list_env(char **env)
{
    env_key_value_t *env_list = NULL;
    int length_key = 0;

    while (*env) {
        length_key = get_length_key(*env);
        add_key_value(&env_list, my_strndup(*env, length_key),
            my_strdup(*env + length_key + 1));
        env++;
    }
    return env_list;
}
