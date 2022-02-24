/*
** EPITECH PROJECT, 2021
** convert tool
** File description:
** convert tool for printf
*/

#include "../../include/my.h"

int my_convert_octal(int nbr)
{
    int octal_number[100];
    int i = 1;
    int j;

    while (nbr != 0) {
        octal_number[i] = nbr % 8;
        nbr = nbr / 8;
        i++;
    }
    for (j = i - 1; j > 0; j--) {
        my_put_nbr(octal_number[j]);
    }
}

int my_convert_hexadecimal(int nbr)
{
    char hexadecimal_number[100];
    int hex;
    int j = 0;
    int i;

    while (nbr != 0) {
        hex = nbr % 16;
        if (hex < 10) {
            hexadecimal_number[j++] = hex + 48;
        } else {
            hexadecimal_number[j++] = hex + 55;
        }
        nbr = nbr / 16;
    }
    for (i = j; i >= 0; i--) {
        my_putchar(hexadecimal_number[i]);
    }
    return (0);
}

int convert_low_hexa(int nbr)
{
    char hexadecimal_number[100];
    int hex;
    int j = 0;
    int i;

    while (nbr != 0) {
        hex = nbr % 16;
        if (hex < 10) {
            hexadecimal_number[j++] = hex + 48;
        } else {
            hexadecimal_number[j++] = hex + 87;
        }
        nbr = nbr / 16;
    }
    for (i = j; i >= 0; i--) {
        my_putchar(hexadecimal_number[i]);
    }
    return (0);
}

int my_convert_adress(int nbr)
{
    char hexadecimal_number[100];
    int hex;
    int j = 0;
    int i;

    my_putstr("0x");
    while (nbr != 0) {
        hex = nbr % 16;
        if (hex < 10) {
            hexadecimal_number[j++] = hex + 48;
        } else {
            hexadecimal_number[j++] = hex + 87;
        }
        nbr = nbr / 16;
    }
    for (i = j; i >= 0; i--) {
        my_putchar(hexadecimal_number[i]);
    }
    return (0);
}

int convert_binary(int nbr)
{
    int binary_number[100];
    int i;

    for (i = 0; nbr > 0; i++) {
        binary_number[i] = nbr % 2;
        nbr = nbr / 2;
    }
    for (i = i - 1; i >= 0; i--) {
        my_put_nbr(binary_number[i]);
    }
}
