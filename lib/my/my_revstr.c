/*
** EPITECH PROJECT, 2022
** Luan BOURBIER
** File description:
** my rev str
*/

#include "my.h"

char *my_revstr(char *str)
{
    int j = my_strlen(str);
    int k = j;
    char rev;

    for (int i = 0; i < k / 2; i++) {
        rev = str[j - 1];
        str[j - 1] = str[i];
        str[i] = rev;
        j--;
    }
    return str;
}
