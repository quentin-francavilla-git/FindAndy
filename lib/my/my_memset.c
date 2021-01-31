/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** 
*/

#include "lib.h"

void my_memset(char *str, char c, int size)
{
    int i = 0;

    while (i != size)
        str[i++] = c;
}