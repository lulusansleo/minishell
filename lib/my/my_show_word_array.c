/*
** EPITECH PROJECT, 2022
** show word array
** File description:
** only file
*/

#include "my.h"

int my_show_word_array(char * const *tab)
{
    if (tab == NULL)
        return 84;
    for (int i = 0; tab[i] != NULL; i++) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
    }
    return 0;
}
