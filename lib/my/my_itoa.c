/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** sokoban
*/

#include "../../include/lib.h"

char *my_itoa(int num)
{
    int i = 0;
    char* str = malloc(sizeof(char) * 5000);
    int negative = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    while (num != 0) {
        int rem = num % 10;
        str[i++] = (rem > 9)? (rem - 10) + 'a' : rem + '0';
        num = num/10;
    }
    if (negative)
        str[i++] = '-';
    str[i] = '\0';
    my_revstr(str);
    return (str);
}