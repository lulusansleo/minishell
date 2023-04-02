/*
** EPITECH PROJECT, 2022
** wrapper
** File description:
** second file
*/

#include "my.h"

int wrapper_my_put_nbr_hexa_m(va_list ap, check_flags_t *flags)
{
    long int nb = va_arg(ap, long int);
    char *base = "0123456789ABCDEF";
    int count = do_hex_len(nb, flags);
    int diff;
    char pad = what_pad(flags);

    count = count_with_precision(flags, nb, base, count);
    diff = flags->min - count;
    if (diff > 0 && !flags->minus) {
        print_pads(pad, diff);
        count = flags->min;
    }
    do_hex_hash_maj(nb, flags);
    pad_number(flags, my_nb_len_base(nb, base));
    my_put_nbr_base(nb, base);
    if (diff > 0 && flags->minus) {
        print_pads(pad, diff);
        count = flags->min;
    }
    return count;
}

int wrapper_my_put_nbr_hexa(va_list ap, check_flags_t *flags)
{
    long int nb = va_arg(ap, long int);
    char *base = "0123456789abcdef";
    int count = do_hex_len(nb, flags);
    int diff;
    char pad = what_pad(flags);

    count = count_with_precision(flags, nb, base, count);
    diff = flags->min - count;
    if (diff > 0 && !flags->minus) {
        print_pads(pad, diff);
        count = flags->min;
    }
    do_hex_hash(nb, flags);
    pad_number(flags, my_nb_len_base(nb, base));
    my_put_nbr_base(nb, base);
    if (diff > 0 && flags->minus) {
        print_pads(pad, diff);
        count = flags->min;
    }
    return count;
}

int wrapper_my_put_nbr_octal(va_list ap, check_flags_t *flags)
{
    long int nb = va_arg(ap, long int);
    char *base = "01234567";
    int count = do_oct_len(nb, flags);
    int diff = count;
    char pad = what_pad(flags);

    count = count_with_precision(flags, nb, base, count);
    diff = flags->min - count;
    if (diff > 0 && !flags->minus) {
        print_pads(pad, diff);
        count = flags->min;
    }
    do_oct_hash(nb, flags);
    pad_number(flags, my_nb_len_base(nb, base));
    my_put_nbr_base(nb, base);
    if (diff > 0 && flags->minus) {
        print_pads(pad, diff);
        count = flags->min;
    }
    return count;
}

int wrapper_my_put_nbr_unsigned_int(va_list ap, check_flags_t *flags)
{
    unsigned int nb = va_arg(ap, unsigned int);
    char *base = "0123456789";
    int count = do_empty_len(nb, flags);
    int diff;
    char pad = what_pad(flags);

    if (flags->max > my_nb_len(nb))
        count += flags->max;
    else
        count += my_nb_len(nb);
    diff = flags->min - count;
    if (diff > 0 && !flags->minus)
        print_pads(pad, diff);
    do_empty_int(nb, flags);
    my_put_nbr_base(nb, base);
    if (diff > 0 && flags->minus) {
        print_pads(pad, diff);
        count = flags->min;
    }
    return count;
}

int wrapper_my_put_b(va_list ap, check_flags_t *flags)
{
    unsigned int nb = va_arg(ap, unsigned int);
    char *base = "01";
    int count = do_empty_len(nb, flags);
    int diff;
    char pad = what_pad(flags);

    count = count_with_precision(flags, nb, base, count);
        count += my_nb_len(nb);
    diff = flags->min - count;
    if (diff > 0 && !flags->minus)
        print_pads(pad, diff);
    do_empty_int(nb, flags);
    my_put_nbr_base(nb, base);
    if (diff > 0 && flags->minus) {
        print_pads(pad, diff);
        count = flags->min;
    }
    return my_nb_len_base(nb, base);
}
