/*
** EPITECH PROJECT, 2022
** tests_env
** File description:
** tests_env
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include "minishell1.h"
#include "my_tests.h"

int go_next_line(char *str);

Test(exit_cmd, basic_exit_test, .init = cr_redirect_stdout)
{
    char **env = get_env_from_file();
    env_key_value_t *ll_env = NULL;
    char *args[2] = {"exit", NULL};

    if (env == NULL)
        cr_skip_test();
    ll_env = list_env(env);
    printf("%d\n", exit_cmd(args, &ll_env, NULL));
}

Test(exit_cmd, exit_error_handling_test, .init = cr_redirect_stdout)
{
    char **env = get_env_from_file();
    env_key_value_t *ll_env = NULL;
    char *args[3] = {"exit", "something", NULL};

    if (env == NULL)
        cr_skip_test();
    ll_env = list_env(env);
    cr_assert_eq(exit_cmd(args, &ll_env, NULL), 1);
}

Test(exit_cmd, exit_error_handling_test2, .init = cr_redirect_stdout)
{
    char **env = get_env_from_file();
    env_key_value_t *ll_env = NULL;
    char *args[4] = {"exit", "14", "14", NULL};

    if (env == NULL)
        cr_skip_test();
    ll_env = list_env(env);
    cr_assert_eq(exit_cmd(args, &ll_env, NULL), 1);
}
