/*
** EPITECH PROJECT, 2021
** disp stdargc
** File description:
** display stdarg
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../include/my.h"

int print_varflag3(char flag, va_list list)
{
    int bin;
    char *stringmaj;
    int adress;
    int hexa;

    if (flag == 'b') {
        bin = va_arg(list, int);
        convert_binary(bin);
    } else if (flag == 'S') {
        stringmaj = va_arg(list, char *);
        analyze_octal_str(stringmaj);
    }
    if (flag == 'p') {
        adress = va_arg(list, int);
        my_convert_adress(adress);
    } else if (flag == 'x') {
        hexa = va_arg(list, int);
        convert_low_hexa(hexa);
    }
}

int print_varflag2(char flag, va_list list)
{
    int octal;
    int hex;

    if (flag == 'o') {
        octal = va_arg(list, int);
        my_convert_octal(octal);
    } else if (flag == 'X') {
        hex = va_arg(list, int);
        my_convert_hexadecimal(hex);
    }
    print_varflag3(flag, list);
}

int print_varflag(char flag, va_list list)
{
    char *str;
    int unsigned_nbr;
    int signed_nbr;
    char c;

    if (flag == 's') {
        str = va_arg(list, char *);
        my_putstr(str);
    } else if (flag == 'c') {
        c = va_arg(list, int);
        my_putchar(c);
    }
    if (flag == 'u') {
        unsigned_nbr = va_arg(list, int);
        my_put_nbr(unsigned_nbr);
    } else if (flag == 'd') {
        signed_nbr = va_arg(list, int);
        my_put_nbr(signed_nbr);
    }
    print_varflag2(flag, list);
}

int my_printf(char *str, ...)
{
    char *n;

    va_list list;
    va_start(list, str);
    if (str <= 0) {
        return (84);
    }
    str_analyzing(str, list);
    va_end(list);
    return (0);
}
