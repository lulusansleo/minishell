/*
** EPITECH PROJECT, 2022
** my str isalpha
** File description:
** only file
*/

#include <stddef.h>

int my_isalpha(char c)
{
    if ((c <= 90 && c >= 65) || (c >= 97 && c <= 122))
        return 1;
    return 0;
}

int my_str_isalpha(char const *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i++)
        if (!my_isalpha(str[i]))
            return 0;
    return 1;
}
