/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** 
*/

#include "lib.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] && s2[i] && i < n) {
        i = i + 1;
    }
    STRNCMP_END
}