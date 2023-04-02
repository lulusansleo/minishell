/*
** EPITECH PROJECT, 2022
** Luan BOURBIER
** File description:
** my is prime
*/

int my_is_prime(int nb)
{
    int n = 2;

    if (nb < n)
        return 0;
    while (n <= nb / 2) {
        if (nb % n == 0)
            return 0;
        n++;
    }
    return 1;
}
