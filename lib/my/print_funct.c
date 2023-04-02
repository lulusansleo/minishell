/*
** EPITECH PROJECT, 2022
** my printf
** File description:
** non printable print
*/

#include "my.h"

static void print_zeros(char c)
{
    if (my_nb_len_base(c, "01234567") < 3)
        write(1, "00", 3 - my_nb_len_base(c, "01234567"));
}

int my_print_non_printable(char *str)
{
    int i;
    int count = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32)
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            print_zeros(str[i]);
            my_put_nbr_base(str[i], "01234567");
            count += 3;
        }
    }
    return i + count;
}
