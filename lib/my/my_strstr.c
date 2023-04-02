/*
** EPITECH PROJECT, 2022
** my strstr
** File description:
** only file
*/

#include "my.h"

int my_strcmp2(char const *s1, char const *s2)
{
    for (int i = 0; s2[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int test = -1;

    for (i = 0; str[i] != '\0'; i++) {
        test = my_strcmp2(str + i, to_find);
        if (test == 0)
            return str + i;
    }
    return NULL;
}
