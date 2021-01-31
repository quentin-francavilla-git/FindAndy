/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** 
*/

char *my_revstr(char *str)
{
    int i;
    int	len = 0;
    char c;

    while (str[len] != '\0') {
        len += 1;
    }
    i = 0;
    while (i < len / 2) {
        c = *(str + i);
        *(str + i) = *(str + len - i - 1);
        *(str + len - i - 1) = c;
        i += 1;
    }
    return (str);
}
