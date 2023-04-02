/*
** EPITECH PROJECT, 2022
** display point for hexa float
** File description:
** Second part of my_put_hexa_float
*/

#include "my.h"

int my_put_point(long double nb)
{
    nb = nb - 1.0;
    if (nb > 0) {
        my_putstr("0x1.");
        return 4;
    } else {
        my_putstr("0x1");
        return 3;
    }
}
