/*
** EPITECH PROJECT, 2022
** my printf
** File description:
** wrapper fourth file
*/

#include "my.h"

int wrapper_notation_big(va_list ap, check_flags_t *flags)
{
    double nb = va_arg(ap, double);
    int ret = 0;

    if (flags->precison)
        ret = scientific_notation_big_e(nb, flags->max);
    else
        ret = scientific_notation_big_e(nb, 6);
    return ret;
}

int wrapper_put_g(va_list ap, check_flags_t *flags)
{
    double nb = va_arg(ap, double);

    (void) flags;
    return my_put_g(nb);
}

int wrapper_put_big_g(va_list ap, check_flags_t *flags)
{
    double nb = va_arg(ap, double);

    (void) flags;
    return my_put_big_g(nb);
}

int wrapper_put_hexa_float(va_list ap, check_flags_t *flags)
{
    double nb = va_arg(ap, double);
    int ret = 0;

    (void) flags;
    ret = my_put_hexa_float(nb);
    return ret;
}
