/*
** EPITECH PROJECT, 2022
** big_scientific
** File description:
** Flag for scientific notation E.
*/

#include "my.h"

double my_check_big_negative(double nb, int *ret)
{
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
        *ret = *ret + 1;
    }
    return nb;
}

int my_get_exponent_s(double nb)
{
    unsigned long int n = 1;
    int i = 1;

    if ((long int) nb == 0) {
        while ((long int) nb == 0) {
            nb = nb * my_compute_power_rec(10, 1);
            i++;
        }
        n = (long int) nb;
        return my_nb_len(n) - i;
    }
    if (nb < 10)
        return 1;
    while (nb >= 10) {
        i++;
        nb = nb / 10;
    }
    return i;
}

int my_display_big_e_second(long int e, long int e_sign)
{
    int return_value = 0;
    if ((e < 10 && e_sign == 1) || (e - 1 < 10 && e_sign == 0)) {
        if (e_sign == 1) {
            return_value += my_putstr("E-0");
            my_put_nbr(e);
        } else {
            return_value += my_putstr("E+0");
            my_put_nbr(e - 1);
        }
        return return_value + 1;
    } else {
        if (e_sign == 1) {
            return_value += my_putstr("E-");
            my_put_nbr(e);
        } else {
            return_value += my_putstr("E+");
            my_put_nbr(e - 1);
        }
        return return_value + 2;
    }
}

int my_displays_big_e(long int e, double nb, long int e_sign, int pow)
{
    int n = 0;

    n += my_put_float(nb, pow);
    if (e == 1) {
        if (e_sign == 0)
            n += my_putstr("E+00");
        if (e_sign == 1)
            n += my_putstr("E-01");
        return n;
    }
    n += my_display_big_e_second(e, e_sign);
    return n;
}

int scientific_notation_big_e(double nb, int pow)
{
    long int e = 0;
    long int e_sign = 0;
    int return_value = 0;

    nb = my_check_big_negative(nb, &return_value);
    e = my_get_exponent_s(nb);
    if (e < 0) {
        e = e * (-1);
        e_sign++;
        while ((long int) nb == 0)
            nb = nb * my_compute_power_rec(10, 1);
    } else
        while (nb > 10)
            nb = nb / my_compute_power_rec(10, 1);
    return_value = return_value + my_displays_big_e(e, nb, e_sign, pow);
    return return_value;
}
