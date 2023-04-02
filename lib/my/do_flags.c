/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** do_flags
*/

#include "my.h"

void do_hex_hash(long long int nb, check_flags_t *flags)
{
    if (flags->flag == 'p' && nb > 0) {
        if (flags->plus)
            write(1, "+", 1);
        if (flags->empty && !flags->plus)
            write(1, " ", 1);
    }
    if (nb != 0 && flags->hash)
        write(1, "0x", 2);
}

void do_hex_hash_maj(long long int nb, check_flags_t *flags)
{
    if (nb != 0 && flags->hash)
        write(1, "0X", 2);
}

void do_oct_hash(long long int nb, check_flags_t *flags)
{
    if (nb != 0 && flags->hash)
        write(1, "0", 1);
}

void do_empty_int(long long int nb, check_flags_t *flags)
{
    if (nb > 0) {
        if (flags->plus) {
            write(1, "+", 1);
            return;
        }
        if (flags->empty)
            write(1, " ", 1);
    } else if (nb < 0)
        write(1, "-", 1);
}
