/*
** EPITECH PROJECT, 2022
** tests_get_args
** File description:
** tests_get_args
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell1.h"

Test(get_args, basic_get_args_test)
{
    char *arg = "ls -l -a /home";
    char **args = get_args(arg);
    char *tests_args[5] = {"ls", "-l", "-a", "/home", NULL};
    size_t totalsize = 2;

    cr_assert_str_eq(args[0], tests_args[0]);
    cr_assert_str_eq(args[1], tests_args[1]);
    cr_assert_str_eq(args[2], tests_args[2]);
    cr_assert_str_eq(args[3], tests_args[3]);
    cr_assert_null(args[4]);
}

Test(get_args, get_args_test_with_diff_format)
{
    char *arg = "\t     ls -l\t\t -a /home   ";
    char **args = get_args(arg);
    char *tests_args[5] = {"ls", "-l", "-a", "/home", NULL};

    cr_assert_str_eq(args[0], tests_args[0]);
    cr_assert_str_eq(args[1], tests_args[1]);
    cr_assert_str_eq(args[2], tests_args[2]);
    cr_assert_str_eq(args[3], tests_args[3]);
    cr_assert_null(args[4]);
}

Test(get_args, get_args_test_with_diff_format2)
{
    char *arg = "\t     ls -l\t\t -a\t/home\t\t  \t";
    char **args = get_args(arg);
    char *tests_args[5] = {"ls", "-l", "-a", "/home", NULL};

    cr_assert_str_eq(args[0], tests_args[0]);
    cr_assert_str_eq(args[1], tests_args[1]);
    cr_assert_str_eq(args[2], tests_args[2]);
    cr_assert_str_eq(args[3], tests_args[3]);
    cr_assert_null(args[4]);
}

Test(get_args, error_handling_test)
{
    char *arg = "";
    char **args = get_args(arg);

    cr_assert_null(args);
}

Test(get_args, error_handling_test2)
{
    char *arg = NULL;
    char **args = get_args(arg);

    cr_assert_null(args);
}

Test(get_args, error_handling_test3)
{
    char *arg = "                    ";
    char **args = get_args(arg);

    cr_assert_null(args);
}
