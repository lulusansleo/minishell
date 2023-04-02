/*
** EPITECH PROJECT, 2022
** my printf
** File description:
** get specifier
*/

#include "my.h"

int get_specifier(int i, char *str, check_flags_t *flags)
{
    if (is_length_modifier(str[i], 1)) {
        flags->conversion = str[i];
        i++;
    }
    if (flags->conversion == 'h' && str[i] == 'h') {
        i++;
        flags->conversion = 'H';
    }
    if (flags->conversion == 'l' && str[i] == 'l') {
        i++;
        flags->conversion = 'y';
    }
    return i;
}
