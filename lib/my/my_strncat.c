/*
** EPITECH PROJECT, 2022
** strncat
** File description:
** only file
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int a = my_strlen(dest);
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[a + i] = src[i];
    dest[a + i] = '\0';
    return dest;
}
