/*
** EPITECH PROJECT, 2022
** printf
** File description:
** my_put_float_g
*/

#include "my.h"

int my_put_float_g(double nb, int pow)
{
    long long int w_part_display = 0;
    double d_part = 0;
    int nb_len_return = 0;
    int pow_2 = pow;
    union bit_float data;

    data.f = nb;
    if ((data.a >> 31) == 1) {
        nb = nb * (-1);
        my_putchar('-');
    }
    w_part_display = (long long int) nb;
    d_part = nb - w_part_display;
    while (pow > 0) {
        d_part = d_part * 10.0;
        pow--;
    }
    my_round_float(&d_part, &w_part_display);
    nb_len_return = display_float_g(pow_2, w_part_display, d_part);
    return nb_len_return + (data.a >> 31);
}
