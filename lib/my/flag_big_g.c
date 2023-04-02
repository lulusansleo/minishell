/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** flag_big_g
*/

#include "my.h"

int my_displays_big_g(long int e, double nb, long int e_sign, int pow)
{
    int n = 0;

    n = n + my_put_float_g(nb, pow);
    if (e == 1) {
        if (e_sign == 0)
            n = n + my_putstr("E+00");
        if (e_sign == 1)
            n = n + my_putstr("E-01");
        return n;
    }
    n = n + my_display_big_e_second(e, e_sign);
    return n;
}

int scientific_notation_big_g(double nb, int pow)
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
    return_value = return_value + my_displays_big_g(e, nb, e_sign, pow);
    return return_value;
}
