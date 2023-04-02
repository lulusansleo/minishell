/*
** EPITECH PROJECT, 2022
** flag_g
** File description:
** flag_g file
*/

#include "my.h"

static int my_detect_decimal(double nb, long int e)
{
    double n = nb;

    n = nb - (long long int) nb;
    if (n > 0) {
        return my_put_float_g(nb, 6 - 6 + e);
    } else {
        my_put_nbr((long long int) nb);
        return my_nb_len((long long int) nb);
    }
}

static int my_displays_g(long int e, double nb, long int e_sign, int pow)
{
    int n = 0;

    n = n + my_put_float_g(nb, pow);
    if (e == 1) {
        if (e_sign == 0)
            n = n + my_putstr("e+00");
        if (e_sign == 1)
            n = n + my_putstr("e-01");
        return n;
    }
    n = n + my_display_e_second(e, e_sign);
    return n;
}

int scientific_notation_g(double nb, int pow)
{
    long int e = 0;
    long int e_sign = 0;
    int return_value = 0;

    nb = my_check_negative(nb, &return_value);
    e = my_get_exponent(nb);
    if (e < 0) {
        e = e * (-1);
        e_sign++;
        while ((long int) nb == 0)
            nb = nb * my_compute_power_rec(10, 1);
    } else
        while (nb > 10)
            nb = nb / my_compute_power_rec(10, 1);
    return_value = return_value + my_displays_g(e, nb, e_sign, pow);
    return return_value;
}

int my_put_g(double nb)
{
    long int e = my_get_exponent(nb);
    int nbr_len = 0;

    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * -1;
        nbr_len++;
    }
    if (e < -4 || e > 6) {
        nbr_len += scientific_notation_g(nb, 6 - 1);
    } else {
        nbr_len += my_detect_decimal(nb, 6 - e);
    }
    return nbr_len;
}

int my_put_big_g(double nb)
{
    long int e = my_get_exponent(nb);
    int nbr_len = 0;

    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * -1;
        nbr_len++;
    }
    if (e < -4 || e > 6) {
        nbr_len += scientific_notation_big_g(nb, 6 - 1);
    } else {
        nbr_len += my_detect_decimal(nb, 6 - e);
    }
    return nbr_len;
}
