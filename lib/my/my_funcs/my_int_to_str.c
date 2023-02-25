/*
** EPITECH PROJECT, 2022
** my_int_to_str
** File description:
** my_int_to_str
*/

#include "lib.h"

char *my_int_to_str(int nb)
{
    int length = nblen(nb);
    int digits = 0;
    char *dest = malloc(sizeof(char) * length + 1);
    int k = 0;

    for (int i = length - 1; i >= 0; i--) {
        digits = nb / my_compute_power_rec(10, i);
        dest[k] = digits + '0';
        nb %= my_compute_power_rec(10, i);
        ++k;
    }
    dest[k] = '\0';
    return dest;
}
