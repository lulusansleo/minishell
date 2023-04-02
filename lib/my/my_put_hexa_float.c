/*
** EPITECH PROJECT, 2022
** my_put_hexa_float
** File description:
** my_put_hexa_float file
*/

#include "my.h"

int my_display_hexa_float_nbr(long long int n)
{
    if (n >= 10) {
        my_putchar((n % 10) + 'a');
    } else if (n >= 0) {
        my_putchar(n + 48);
    }
    return 1;
}

int my_display_hexa_exponent(int e)
{
    my_putchar('p');
    if (e < 0) {
        my_putchar('-');
        my_put_nbr(e);
        return 2 + my_nb_len(e);
    } else {
        my_putchar('+');
        my_put_nbr(e);
        return 2 + my_nb_len(e);
    }
}

double my_get_two_with_nbr(double nb, int e)
{
    int i = 0;
    int e_sign = 0;

    if (e < 0) {
        e = e * (-1);
        e_sign = 1;
    }
    while (i < e) {
        if (e_sign == 1) {
            nb = nb * 2;
        } else {
            nb = nb / 2;
        }
        i++;
    }
    return nb;
}

int my_get_exponent_two(double nb)
{
    double n = 1;
    int pow = 0;

    if (nb >= 1) {
        while (nb >= n) {
            n = n * 2;
            pow++;
        }
        return pow - 1;
    } else {
        while (nb <= n) {
            n = n / 2;
            pow--;
        }
        return pow + 1;
    }
}

int my_put_hexa_float(long double nb)
{
    int e = my_get_exponent_two(nb);
    int return_value = 0;
    long long int n = 0;
    int i = 0;

    nb = my_get_two_with_nbr(nb, e);
    return_value += my_put_point(nb);
    while (nb > 0 && i < 14) {
        nb = nb * 16;
        n = ((long long int) nb % 16);
        return_value += my_display_hexa_float_nbr(n);
        nb = nb - ((long long int) nb);
        i++;
    }
    return_value += my_display_hexa_exponent(e);
    return return_value;
}
