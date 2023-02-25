/*
** EPITECH PROJECT, 2022
** get_args
** File description:
** get_args
*/

#include "lib.h"

static int remove_space(char *str)
{
    int i = 0;

    for (; str[i] == ' ' || str[i] == '\t'; i++);
    return i;
}

static int count_between_space(char *str, int count_space)
{
    int i = 0;

    for (; str[i] != ' ' && str[i] != '\t' && str[i] != '\0'; i++);
    if (count_space)
        for (; (str[i] == ' ' || str[i] == '\t') && str[i] != '\0'; i++);
    return i;
}

static int count_words(char *str)
{
    int count = 0;

    for (int i = remove_space(str); i < my_strlen(str);
        i += count_between_space(str + i, 1))
        ++count;
    return count;
}

char **get_args(char *str)
{
    int k = 0;
    char **array = NULL;
    int words = 0;

    if (str == NULL || !my_strcmp(str, "")
        || remove_space(str) == my_strlen(str))
        return NULL;
    words = count_words(str);
    array = malloc(sizeof(char *) * (words + 1));
    for (int i = remove_space(str); i < my_strlen(str);
        i += count_between_space(str + i, 1)) {
        array[k] = my_strndup(str + i, count_between_space(str + i, 0));
        ++k;
    }
    array[words] = NULL;
    return array;
}
