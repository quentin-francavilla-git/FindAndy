/*
** EPITECH PROJECT, 2018
** my_convert
** File description:
** 
*/

int my_convert_char_int(char *str)
{
    int res = 0;
    int i = 0;

    while (str[i] != '\0') {
        res = res * 10 + str[i] - '0';
        i += 1;
    }
    return (res);
}
