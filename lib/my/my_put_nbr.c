/*
** EPITECH PROJECT, 2018
** put nbr
** File description:
** a
*/

#include "lib.h"

int my_put_nbr(int nb)
{
    int	i = 0;

    if (nb < 0) {
        my_putchar('-');
        if (nb <= -2147483648) {
            i = 1;
            nb = nb + 1;
        }
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    if (i == 1) {
        my_putchar(nb % 10 + '1');
    }
    else {
        my_putchar(nb % 10 + '0');
    }
    return (0);
}