/*
** EPITECH PROJECT, 2022
** binary
** File description:
** binary
*/

#include "minishell1.h"

static int error_handling(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 11) {
            my_printf("Segmentation fault%s\n", WCOREDUMP(status) ? \
            " (core dumped)" : "");
        } else if (WTERMSIG(status) == 8) {
            my_printf("Floating exception%s\n", WCOREDUMP(status) ? \
            " (core dumped)" : "");
        }
    }
    return 0;
}

static int execute_binary(char **command, env_key_value_t **env, char *path)
{
    char **char_env = env_transformation(env);
    int status = 0;
    pid_t child = fork();

    if (child == -1 || !char_env)
        return 84;
    if (child > 0) {
        waitpid(child, &status, 0);
        error_handling(status);
    } else {
        execve(path, command, char_env);
        my_printf("%s: %s\n", path, strerror(errno));
        for (int i = 0; char_env[i]; i++)
            free(char_env[i]);
        free(char_env);
    }
    return 0;
}

static int exec_binary(char **command, env_key_value_t **env, char *path)
{
    DIR *folder;
    struct dirent *entry;
    char new_path[my_strlen(path) + my_strlen(command[0]) + 1];
    my_strcpy(new_path, path);
    my_strcpy(new_path + my_strlen(path), "/");
    my_strcpy(new_path + my_strlen(path) + 1, command[0]);

    folder = opendir(path);
    if (folder == NULL) {
        free(path);
        return 0;
    }
    while ((entry = readdir(folder))) {
        if (!my_strcmp(entry->d_name, command[0])) {
            execute_binary(command, env, new_path);
            closedir(folder);
            free(path);
            return 1;
        }
    }
    closedir(folder);
    free(path);
    return 0;
}

int search_binary(char **command, env_key_value_t **env)
{
    env_key_value_t *tmp = *env;

    while (my_strcmp(tmp->env_var, "PATH"))
        tmp = tmp->next;
    if (command[0] && !access(command[0], F_OK) && !access(command[0], X_OK)) {
        execute_binary(command, env, command[0]);
        return 0;
    }
    for (int i = 0; i < my_strlen(tmp->env_value);
        i += next_path(tmp->env_value + i) + 1) {
        if (exec_binary(command, env,
                my_strndup(tmp->env_value + i, next_path(tmp->env_value + i))))
            return 0;
    }
    return 1;
}

void check_command(char **command, env_key_value_t **env, char **old_path)
{
    if (search_binary(command, env))
        my_printf("%s: Command not found.\n", command[0]);
}
