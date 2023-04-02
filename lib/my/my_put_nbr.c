/*
** EPITECH PROJECT, 2022
** my put nbr
** File description:
** put number
*/

#include "my.h"

long long int my_put_nbr(long long int n)
{
    long long int nb = n;

    if (nb < 0) {
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    if (nb < 10) {
        my_putchar(nb % 10 + '0');
    }
    return 0;
}

long long int my_put_nbr_base(long long int n, char *base)
{
    int len = my_strlen(base);
    long long int nb = n;

    if (nb < 0) {
        nb = -nb;
    }
    if (nb >= len) {
        my_put_nbr_base(nb / len, base);
        my_putchar(base[nb % len]);
    }
    if (nb < len) {
        my_putchar(base[nb]);
    }
    return 0;
}
