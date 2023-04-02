/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** add len with flag modifiers
*/

#include "my.h"

int do_hex_len(long long int nb, check_flags_t *flags)
{
    if (flags->flag == 'p' && nb > 0)
        if (flags->plus || flags->plus)
            return 3;
    if (nb != 0 && flags->hash)
        return 2;
    return 0;
}

int do_oct_len(long long int nb, check_flags_t *flags)
{
    if (nb != 0 && flags->hash &&
    my_nb_len_base(nb, "012345678") > flags->max)
        return 1;
    return 0;
}

int do_empty_len(long long int nb, check_flags_t *flags)
{
    if (nb > 0) {
        if (flags->plus)
            return 1;
        if (flags->empty)
            return 1;
    }
    return 0;
}

int count_with_precision(check_flags_t *flags,
long long int nb, char *base, int count)
{
    if (flags->max > my_nb_len_base(nb, base)) {
        count += flags->max;
        if (flags->flag == 'o')
            flags->hash = 0;
    } else
        count += my_nb_len_base(nb, base);
    return count;
}

int count_with_precision_decimal(check_flags_t *flags,
long long int nb, int count)
{
    if (flags->max > my_nb_len(nb)) {
        count += flags->max;
        if (flags->flag == 'o')
            flags->hash = 0;
    } else
        count += my_nb_len(nb);
    return count;
}
