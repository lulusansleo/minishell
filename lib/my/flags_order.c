/*
** EPITECH PROJECT, 2022
** flag_order
** File description:
** flag_order
*/

#include <stdarg.h>
#include "my.h"

int is_flag(char c)
{
    int i = 0;
    char *s = "-0+ #";

    while (s[i] != '\0') {
        if (s[i] == c) {
            return 1;
        }
        i++;
    }
    return 0;
}

int is_width(char c)
{
    if (is_flag(c == 1)) {
        return 0;
    }
    if (my_isnum(c) || c == '*') {
        return 1;
    } else {
        return 0;
    }
}

int is_argtype(char c)
{
    char *t = "scid%xXoupfeEgGnbSaA";
    int k = 0;

    if (is_flag(c) == 1 || is_width(c) == 1 ||
    is_length_modifier(c, 1))
        return 0;
    while (t[k] != '\0') {
        if (c == t[k]) {
            return 1;
        }
        k++;
    }
    return 0;
}

int is_length_modifier(char c, int order)
{
    char *first_length = "hljztL";
    char *second_length = "hl";
    int i = 0;

    for (i = 0; first_length[i] != '\0' && order == 1; i++) {
        if (c == first_length[i]) {
            return 1;
        }
    }
    for (i = 0; second_length[i] != '\0' && order == 2; i++) {
        if (c == second_length[i])
            return 1;
    }
    return 0;
}

int check_flags_order(char *format, int i)
{
    int l = 1;

    while (format[i] != '\0' && is_flag(format[i]) != 0)
        i++;
    while (format[i] != '\0' && is_width(format[i]) != 0)
        i++;
    if (format[i] == '.') {
        i++;
        while (format[i] != '\0' && is_width(format[i]) != 0)
            i++;
    }
    if (is_length_modifier(format[i], 1)) {
        while (format[i] != '\0' && is_length_modifier(format[i], l) != 0) {
            i++;
            l++;
        }
    }
    if (is_argtype(format[i]) != 0)
        return 1;
    return 0;
}
