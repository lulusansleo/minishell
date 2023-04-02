/*
** EPITECH PROJECT, 2022
** my printf
** File description:
** precision str
*/

#include "my.h"

int precision_str(char *str, char *cpy, int count, check_flags_t *flags)
{
    if (flags->max < my_strlen(str) && flags->precison) {
        count = flags->max;
        cpy[flags->max] = '\0';
    } else
        count += my_strlen(str);
    return count;
}
