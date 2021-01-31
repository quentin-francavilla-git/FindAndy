/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** base
*/

#include "lib.h"

int my_getnbr_base(char *str, char *base)
{
    int i = my_strlen(str) - 1;
    int b;
    int nbr = 0;
    int multi = 1;

    while (i >= 0) {
        b = 0;
        while (str [i] != base [b])
            b = b + 1;
        nbr = nbr + b * multi;
        multi = multi * my_strlen(base);
        i--;
    }
    return (nbr);
}
