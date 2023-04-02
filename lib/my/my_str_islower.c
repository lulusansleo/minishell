/*
** EPITECH PROJECT, 2022
** my str islower
** File description:
** only file
*/

#include "my.h"

int my_islower(char c)
{
    if (c >= 97 && c <= 122)
        return 1;
    return 0;
}

int my_str_islower(char const *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i++)
        if (!my_isalpha(str[i]))
            return 0;
    return 1;
}
