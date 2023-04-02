/*
** EPITECH PROJECT, 2022
** my_put_float
** File description:
** Display a float.
*/

#include "my.h"

double my_round_float(double *d_part, long long int *w_part)
{
    double d_copy = *d_part;
    int len_d_part_before = my_nb_len((long long int) *d_part);
    int len_d_part_after = 0;

    d_copy = d_copy * 10;
    if ((long long int) d_copy % 10 >= 5) {
        *d_part = *d_part + 1.0;
    }
    len_d_part_after = my_nb_len((long long int) *d_part);
    if (len_d_part_after > len_d_part_before) {
        *d_part = 0.0;
        *w_part = *w_part + 1.0;
    }
    return 0;
}

static int display_float(int pow, long int w,
double d)
{
    int i = 0;
    int n = my_nb_len((long long int) d);
    int m = my_nb_len(w);

    my_put_nbr(w);
    my_putchar('.');
    while (i < pow - n) {
        my_putchar(48);
        i++;
    }
    my_put_nbr((long long int) d);
    return n + m + i + 1;
}

int display_float_g(int pow, long int w,
double d)
{
    int i = 0;
    int n = my_nb_len((long long int) d);
    int m = my_nb_len(w);
    long long int nb = (long long int) d;

    my_put_nbr(w);
    my_putchar('.');
    while (i < pow - n) {
        my_putchar(48);
        i++;
    }
    while (nb % 10 == 0)
        nb = nb / 10;
    my_put_nbr(nb);
    return n + m + i + 1;
}

int my_put_float(double nb, int pow)
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
    nb_len_return = display_float(pow_2, w_part_display, d_part);
    return nb_len_return + (data.a >> 31);
}
