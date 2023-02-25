/*
** EPITECH PROJECT, 2022
** exit
** File description:
** exit
*/

#include "minishell1.h"

int exit_cmd(char **args, env_key_value_t **env, char **old_path)
{
    int exit_value = 0;

    if (args[1] == NULL) {
        my_printf("exit\n");
        exit(exit_value);
        return 0;
    }
    if (args[1] != NULL && args[2] == NULL) {
        if (my_str_isnum(args[1]) == 1) {
            exit_value = my_atoi(args[1]);
            my_printf("exit\n");
            exit(exit_value);
            return 0;
        }
    }
    my_printf("exit: Expression Syntax.\n");
    return 1;
}
