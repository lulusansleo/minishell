/*
** EPITECH PROJECT, 2022
** Luan BOURBIEr
** File description:
** my compute power rec
*/

int my_compute_power_rec(long int nb , int p)
{
    if (p == 0) {
        return 1;
    } else if (p < 0) {
        return 0;
    } else {
        return my_compute_power_rec(nb, p - 1) * nb;
    }
}
