/*
** EPITECH PROJECT, 2022
** my strcapitalize
** File description:
** only file
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    if (my_islower(str[0]))
        str[0] -= 32;
    for (int i = 1; str[i] != '\0'; i++) {
        if ((str[i - 1] <= 57 || str[i - 1] == 59) &&
        (my_islower(str[i]))) {
            str[i] -= 32;
            i++;
        }
        while (my_isupper(str[i])) {
            str[i] += 32;
            i++;
        }
    }
    return str;
}
