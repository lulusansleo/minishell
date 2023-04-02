/*
** EPITECH PROJECT, 2022
** my str isnum
** File description:
** only file
*/

#include <stddef.h>

int my_isnum(char c)
{
    if (c <= 57 && c >= 48)
        return 1;
    return 0;
}

int my_str_isnum(char *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i++)
        if (!my_isnum(str[i]))
            return 0;
    return 1;
}
