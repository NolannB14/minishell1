/*
** EPITECH PROJECT, 2022
** cd
** File description:
** cd
*/

#include "minishell1.h"

static char *get_env_value(char *env_var, env_key_value_t **env)
{
    env_key_value_t *tmp = *env;

    while (my_strcmp(tmp->env_var, env_var) && tmp != NULL)
        tmp = tmp->next;
    return tmp->env_value;
}

static char *get_current_dir(char *cwd)
{
    getcwd(cwd, PATH_MAX);
    if (cwd != NULL) {
        return cwd;
    } else {
        return NULL;
    }
}

static int change_dir(char *direction)
{
    if (chdir(direction) == -1) {
        if (errno == ENOTDIR)
            my_printf("%s: %s\n", direction, strerror(errno));
        else
            my_printf("cd: %s\n", strerror(errno));
        return 1;
    }
    return 0;
}

static int check_errors_cd(char **args)
{
    int len = 0;
    char **temp = args;

    for (; *temp; ++temp)
        ++len;
    if (len > 2) {
        my_printf("cd: Too many arguments.\n");
        return 84;
    }
    return 0;
}

int cd_cmd(char **args, env_key_value_t **env, char **old_path)
{
    char *cwd = malloc(sizeof(char) * PATH_MAX);
    char *temp_old_path = NULL;

    temp_old_path = my_strdup(get_current_dir(cwd));
    if (check_errors_cd(args) == 84 || !cwd)
        return 84;
    if (old_path && args[1] && args[1][0] == '-'
        && ((args[1][1] == '-' && args[1][2] == '\0') || args[1][1] == '\0')) {
        chdir(*old_path);
    } else if (!args[1]
        || (args[1] && args[1][0] == '~' && args[1][1] == '\0')) {
        chdir(get_env_value("HOME", env));
    } else {
        *old_path = my_strdup(temp_old_path);
        return change_dir(args[1]);
    }
    *old_path = my_strdup(temp_old_path);
    return 0;
}
