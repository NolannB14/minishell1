/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** minishell1
*/

#include "minishell1.h"

static const builtins_t shell_buildints[] = {
    {.command = "cd", .b_ins = &cd_cmd},
    {.command = "env", .b_ins = &env_cmd},
    {.command = "setenv", .b_ins = &setenv_cmd},
    {.command = "unsetenv", .b_ins = &unsetenv_cmd},
    {.command = "exit", .b_ins = &exit_cmd},
    {.command = NULL, .b_ins = NULL}
};

static const builtins_t *exec_command(char **command, env_key_value_t **env)
{
    for (int i = 0; shell_buildints[i].command != NULL; i++) {
        if (!my_strcmp(shell_buildints[i].command, command[0]))
            return &shell_buildints[i];
    }
    return NULL;
}

static void search_command(char **args, env_key_value_t **env, char **old_path)
{
    const builtins_t *command = NULL;

    if (args) {
        command = exec_command(args, env);
        if (command)
            command->b_ins(args, env, old_path);
        else
            check_command(args, env, old_path);
    }
}

static int launch_shell(env_key_value_t **env)
{
    char **args = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t linesize = 0;
    char *old_path = NULL;

    while (1) {
        if (isatty(0))
            my_printf("$> ");
        linesize = getline(&line, &len, stdin);
        if (linesize == -1)
            return 0;
        line[linesize - 1] = '\0';
        args = get_args(line);
        search_command(args, env, &old_path);
        reset_all(&len, &linesize, line);
        free_args(args);
    }
}

int minishell1(int ac, char **av, char **env)
{
    int return_value = 0;
    env_key_value_t *env_list = list_env(env);

    return_value = launch_shell(&env_list);
    my_printf("exit\n");
    return return_value;
}
