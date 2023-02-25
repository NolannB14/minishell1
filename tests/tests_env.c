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

Test(env_cmd, basic_env_test, .init = cr_redirect_stdout)
{
    char **env = get_env_from_file();
    env_key_value_t *ll_env = NULL;
    char *args[2] = {"env", NULL};
    int fd = open("tests/env", O_RDONLY);
    char *buf = NULL;
    struct stat st;

    if (env == NULL)
        cr_skip_test();
    if (fd < 0)
        cr_skip_test();
    stat("tests/env", &st);
    buf = malloc(sizeof(char) * st.st_size);
    if (buf == NULL)
        cr_skip_test();
    read(fd, buf, st.st_size);
    ll_env = list_env(env);
    env_cmd(args, &ll_env, NULL);
    cr_assert_stdout_eq_str(buf);
}
