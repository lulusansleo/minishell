/*
** EPITECH PROJECT, 2022
** my strncmp
** File description:
** only file
*/

#include <stddef.h>
#include <stdlib.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; s1[i] != '\0' && i < n; i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
    }
    return 0;
}

void free_array(char **array, char *line)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    free(line);
}
