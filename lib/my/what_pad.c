/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** what_pad
*/

#include "my.h"

char what_pad(check_flags_t *flags)
{
    if (flags->zero && !flags->minus && !flags->max && !flags->precison)
        return '0';
    return ' ';
}

void print_pads(char c, int diff)
{
    for (int i = 0; i < diff; i++) {
        write(1, &c, 1);
    }
}

void pad_number(check_flags_t *flags, int count)
{
    for (int i = 0; i < flags->max - count; i++)
            write(1, "0", 1);
}
