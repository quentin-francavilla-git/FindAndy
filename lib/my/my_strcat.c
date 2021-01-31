/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** 
*/

char *my_strcat(char *dest, char const *src)
{
    int i;
    int a;

    a = 0;
    i = 0;
    while (dest[i] != '\0') {
        i = i + 1;
    }
    while (src[a] != '\0') {
        dest[i] = src[a];
        a = a + 1;
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
