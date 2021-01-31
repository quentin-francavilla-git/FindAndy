/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** 
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int y = 0;
    int result;
    int a = 0;

    while (!(str[i] >= '0' && str[i] <= '9')) {
        i += 1;
        a = a + 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        y = y * 10;
        y = y + str[i] - '0';
        i += 1;
        if (y < 0)
            return (0);
        if (str[a-1] == '-')
            result = (-y);
        if (str[a-1] != '-')
            result = y;
    }
    return (result);
}
