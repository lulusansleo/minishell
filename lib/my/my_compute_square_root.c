/*
** EPITECH PROJECT, 2022
** Luan BOURBIER
** File description:
** my compute square root
*/

int my_compute_square_root(int nb)
{
    int i = 1;

    if (nb <= 0)
        return 0;
    while (i * i != nb) {
        if ((i * i) > nb)
            return 0;
        i++;
    }
    return i;
}
