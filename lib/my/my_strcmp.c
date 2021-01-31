/*
** EPITECH PROJECT, 2018
** strcmp
** File description:
** oui
*/

#include "lib.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    while (s1[i] == s2[i] && s1[i] != '\0' || s1[i] == s2[i] && s2[i] != '\0')
        ++i;
    if (i == my_strlen(s1) && i == my_strlen(s2))
        return (0);
    END_STR_CMP
    return (84);
}
