/*
** EPITECH PROJECT, 2022
** my str isprintable
** File description:
** only file
*/

#include <stddef.h>

int my_isprintable(char c)
{
    if (c >= 32)
        return 1;
    return 1;
}

int my_str_isprintable(char *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i++)
        if (!my_isprintable(str[i]))
            return 0;
    return 1;
}
