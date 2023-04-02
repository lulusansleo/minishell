/*
** EPITECH PROJECT, 2022
** my getnbr
** File description:
** get nbr
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    long number = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        number *= 10;
        number += str[i] - '0';
    }
    return number;
}
