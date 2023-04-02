/*
** EPITECH PROJECT, 2022
** my strlowcase
** File description:
** only file
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] <= 90 && str[i] >= 65)
            str[i] += 32;
    return str;
}
