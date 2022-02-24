/*
** EPITECH PROJECT, 2021
** analyze tool
** File description:
** analyze tool for print f
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../include/my.h"

int analyze_octal_str(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            my_convert_octal(str[i]);
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
}

int analyze_flag3(char flag, char *str, int i, va_list list)
{
    if (str[i] == 's') {
        flag = 's';
        print_varflag(flag, list);
        return (i);
    } else if (str[i] == 'p') {
        flag = 'p';
        print_varflag(flag, list);
        return (i);
    }
    if (str[i] == 'u') {
        flag = 'u';
        print_varflag(flag, list);
        return (i);
    }
}

int analyze_flag2(char flag, char *str, int i, va_list list)
{
    if (str[i] == 'd' || str[i] == 'i') {
        flag = 'd';
        print_varflag(flag, list);
        return (i);
    } else if (str[i] == 'b') {
        flag = 'b';
        print_varflag(flag, list);
        return (i);
    }
    if (str[i] == 'S') {
        flag = 'S';
        print_varflag(flag, list);
        return (i);
    } else if (str[i] == 'x') {
        flag = 'x';
        print_varflag(flag, list);
        return (i);
    }
    i = analyze_flag3(flag, str, i, list);
    return (i);
}

int analyze_flag(char flag, char *str, int i, va_list list)
{
    i++;
    if (str[i] == 'o') {
        flag = 'o';
        print_varflag(flag, list);
        return (i);
    } else if (str[i] == 'X') {
        flag = 'X';
        print_varflag(flag, list);
        return (i);
    }
    if (str[i] == 'c') {
        flag = 'c';
        print_varflag(flag, list);
        return (i);
    }
    i = analyze_flag2(flag, str, i, list);
    return (i);
}

int str_analyzing(char *str, va_list list)
{
    int i = 0;
    char flag;

    while (str[i] != '\0') {
        if (str[i] == '%') {
            i = analyze_flag(flag, str, i, list);
            i++;
        } else {
            my_putchar(str[i]);
            i++;
        }
    }
}
