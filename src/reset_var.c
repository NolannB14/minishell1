/*
** EPITECH PROJECT, 2022
** reset_var
** File description:
** reset_var
*/

#include "minishell1.h"

void reset_all(size_t *len, ssize_t *linesize, char *line)
{
    *len = 0;
    *linesize = 0;
    free(line);
}

void free_args(char **args)
{
    char *current = NULL;

    if (args != NULL) {
        while (*args) {
            current = *args;
            free(current);
            args++;
        }
    }
}
