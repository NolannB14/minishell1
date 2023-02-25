/*
** EPITECH PROJECT, 2022
** features
** File description:
** features
*/

#include "minishell1.h"

int next_path(char *str)
{
    int i = 0;

    for (; str[i] != ':' && str[i] != '\0'; i++);
    return i;
}
