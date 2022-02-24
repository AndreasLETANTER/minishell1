/*
** EPITECH PROJECT, 2022
** tool
** File description:
** tool
*/

#include <stdlib.h>
#include "my.h"

int get_nb_arg(char **path, int i)
{
    while (path[i]) {
        i++;
    }
    i--;
    return (i);
}

char *duplicate_string(char const *src)
{
    char *new_str = malloc(sizeof(char) + my_strlen(src) + 1);
    new_str[0] = '\0';
    int i = 0;
    for (; src[i] != '\0';) {
        new_str[i] = src[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}

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

void free_array(char **array)
{
    int i = 0;

    for (; array[i]; i++) {
        free(array[i]);
    }
}