/*
** EPITECH PROJECT, 2022
** my str to word array
** File description:
** only file
*/

#include "my.h"

static int is_alpha_num(char c);
static int word_count(char const *str);
static char **write_array(char const *str, int count, char **arr);

char **my_str_to_word_array(char const *str)
{
    int count = word_count(str);
    char **arr = malloc(sizeof (char *) * (count + 1));

    arr[count] = NULL;
    arr = write_array(str, count, arr);
    return arr;
}

static int my_wordlen(char const *str)
{
    int i;

    for (i = 0; is_alpha_num(str[i]) != 0; i++);
    return i;
}

static char **write_array(char const *str, int count, char **arr)
{
    int a = 0;
    int len;
    int j = 0;

    for (int i = 0; i < count; i++) {
        while (!is_alpha_num(str[a]))
            a++;
        len = my_wordlen(str + a);
        arr[i] = malloc(sizeof (char) * (len + 1));
        arr[i][len] = '\0';
        for ((j = 0); is_alpha_num(str[a]); a++) {
            arr[i][j] = str[a];
            j++;
        }
    }
    return arr;
}

static int is_alpha_num(char c)
{
    if (my_isalpha(c) || my_isnum(c))
        return 1;
    return 0;
}

static int word_count(char const *str)
{
    int count = 0;
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (is_alpha_num(str[i])) {
            count++;
            i++;
        }
        while (is_alpha_num(str[i]))
            i++;
    }
    return count;
}
