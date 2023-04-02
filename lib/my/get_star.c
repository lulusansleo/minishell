/*
** EPITECH PROJECT, 2022
** my printf
** File description:
** printf function get star
*/

#include "my.h"

void get_star(check_flags_t *flags, va_list ap)
{
    if (flags->min_star)
        flags->min = va_arg(ap, int);
    if (flags->max_star)
        flags->max = va_arg(ap, int);
}
