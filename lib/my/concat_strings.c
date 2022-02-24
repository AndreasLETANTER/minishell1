/*
** EPITECH PROJECT, 2021
** concat_strings.c
** File description:
** concat_strings.c
*/

#include "../..//include/my.h"

char *concat_strings(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[len_dest + i] = src[i];
        i++;
    }
    dest[len_dest + i] = '\0';
    return (dest);
}
