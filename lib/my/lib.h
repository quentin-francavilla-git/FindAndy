/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef LIB_H_
#define LIB_H_

#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void    my_putchar(char c);
int     my_isneg(int nb);
int     my_put_nbr(int nb);
void    my_swap(int *a, int *b);
void     my_putstr(char const *str);
int     my_strlen(char const *str);
int     my_getnbr( char const *str);
void    my_sort_int_array(int *tab, int size);
int     my_compute_power_rec(int nb, int power);
int     my_compute_square_root(int nb);
int     my_is_prime(int nb);
int     my_find_prime_sup(int nb);
char    *my_strcpy(char *dest, char const *src);
char    *my_strncpy(char *dest, char const *src, int n);
char    *my_revstr(char*str);
int     my_strcmp(char const *s1, char const *s2);
int     my_strncmp(char const *s1, char const *s2, int n);
char    *my_strupcase(char *str);
char    *my_strlowcase(char *str);
char    *my_strcapitalize(char *str);
int     my_str_isalpha(char const *str);
int     my_str_isnum(char const *str);
int     my_str_islower(char const *str);
int     my_str_isupper(char const *str);
int     my_str_isprintable(char const *str);
int     my_showstr(char const *str);
int     my_showmem(char const *str, int size);
char    *my_strcat(char *dest, char const *src);
char    *my_strncat(char *dest, char const *src, int nb);
int     my_strlennbr(int n);
int     my_convert_char_int(char *str);
void    my_put_nbr_base(int nbr, char const *base);
void    my_memset(char *str, char c, int size);
char    **my_str_to_wordtab(char *str);
char    *my_itoa(int num);
int     my_getnbr_base(char *str, char *base);

#define COMPTEUR_STRSTR while (y != i) {y = y + 1;}

#define END_STR_CMP else if (len1 < len2) \
return (-1); \
else if (len1 > len2) \
return (1); \

#define STRNCMP_END if ((s1[i] == '\0' && s2[i] == '\0') || i == n) { \
return (0); \
} \
else if (s1[i] > s2[i]) { \
return (1); \
} \
else { \
return (-1); \
} \

#endif
