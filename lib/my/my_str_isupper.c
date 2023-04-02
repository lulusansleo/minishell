/*
** EPITECH PROJECT, 2022
** my str isalpha
** File description:
** only file
*/

#include "my.h"

int my_isupper(char c)
{
    if (c <= 90 && c >= 65)
        return 1;
    return 0;
}

int my_str_isupper(char const *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i++)
        if (!my_isalpha(str[i]))
            return 0;
    return 1;
}
