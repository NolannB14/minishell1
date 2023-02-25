/*
** EPITECH PROJECT, 2022
** get_env_from_file
** File description:
** get_env_from_file
*/

#include "minishell1.h"

static int go_next_line(char *str)
{
    int i = 0;

    if (str == NULL || !my_strcmp(str, " "))
        return -1;
    for (; str[i] != '\n' && str[i] != '\0'; i++);
    return i + 1;
}

char **get_env_from_file(void)
{
    int fd = open("tests/env", O_RDONLY);
    char *buf = NULL;
    struct stat st;
    char **env = NULL;
    int lines = 0;
    int k = 0;

    if (fd < 0)
        return NULL;
    stat("tests/env", &st);
    buf = malloc(sizeof(char) * st.st_size);
    if (buf == NULL)
        return NULL;
    read(fd, buf, st.st_size);
    for (int i = 0; i < st.st_size; i++) {
        if (buf[i] == '\n')
            ++lines;
    }
    env = malloc(sizeof(char *) * (lines + 1));
    for (int i = 0; i < st.st_size; i += go_next_line(buf + i)) {
        env[k] = my_strndup(buf + i, go_next_line(buf + i) - 1);
        k++;
    }
    env[k] = NULL;
    return env;
}