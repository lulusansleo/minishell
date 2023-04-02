/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** get_flags
*/

#include "my.h"

void flags_reset(check_flags_t *flags)
{
    flags->empty = 0;
    flags->hash = 0;
    flags->max = 0;
    flags->min = 0;
    flags->minus = 0;
    flags->zero = 0;
    flags->plus = 0;
    flags->precison = 0;
    flags->flag = '\0';
    flags->max_star = 0;
    flags->min_star = 0;
    flags->conversion = '0';
}

int is_format_flag(char c)
{
    char *str = "dscixXfeEgG%oupnbS";

    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == c)
            return 1;
    return 0;
}

int get_width(int i, char *str, check_flags_t *flags)
{
    if (my_isnum(str[i])) {
        while (my_isnum(str[i])) {
            flags->min = flags->min * 10;
            flags->min += str[i] - '0';
            i++;
        }
    } else if (str[i] == '*') {
        flags->min_star = 1;
        i++;
    }
    return i;
}

int get_precision(int i, char *str, check_flags_t *flags)
{
    if (str[i] == '.') {
        flags->precison = 1;
        i++;
        while (my_isnum(str[i])) {
            flags->max = flags->max * 10;
            flags->max += str[i] - '0';
            i++;
        }
        if (str[i] == '*')  {
            flags->max_star = 1;
            i++;
        }
        if (flags->zero)
            flags->zero = 0;
    }
    return i;
}

int what_flags(check_flags_t *flags, char *str, int i, int count)
{
    while (is_flag(str[i])) {
        if (str[i] == '-')
            flags->minus = 1;
        if (str[i] == '+')
            flags->plus = 1;
        if (str[i] == '0')
            flags->zero = 1;
        if (str[i] == '#')
            flags->hash = 1;
        if (str[i] == ' ')
            flags->empty = 1;
        i++;
    }
    i = get_width(i, str, flags);
    i = get_precision(i, str, flags);
    i = get_specifier(i, str, flags);
    flags->flag = str[i];
    flags->count = count;
    return i;
}
