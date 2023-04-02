/*
** EPITECH PROJECT, 2022
** Luan BOURBIER
** File description:
** my putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return my_strlen(str);
}
