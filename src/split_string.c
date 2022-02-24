/*
** EPITECH PROJECT, 2022
** sf
** File description:
** sdf
*/

#include <stdlib.h>

int check_alphanum(char const *str, int i)
{
    if (str[i] != '\0' && str[i] >= 33 && str[i] <= 126) {
        return (1);
    } else {
        return (0);
    }
}

int words_number(char const *str)
{
    int words = 0;
    int i = 0;
    int check_words = 0;

    while (str[i]) {
        check_words = 0;
        while ((check_alphanum(str, i) == 1) && str[i] != '\0') {
            check_words = 1;
            i++;
        }
        if (check_words == 1) {
            words++;
        }
        i++;
    }
    return (words);
}

int word_len(char const *str, int i)
{
    while (check_alphanum(str, i) == 1) {
        i++;
    }
    return (i);
}

char **split_string(char const *str)
{
    int words = words_number(str);
    int count = 0;
    char **array = malloc(sizeof(char *) * words * 2);
    int i = 0;
    int j = 0;

    for (; count < words; count++) {;
        j = 0;
        array[count] = malloc(sizeof(char) * word_len(str, i) + 1);
        while (str[i] != '\0' && \
        (check_alphanum(str, i) == 1)) {
            array[count][j] = str[i];
            j++;
            i++;
        }
        array[count][j] = '\0';
        while (check_alphanum(str, i) == 0 && str[i] != '\0')
            i++;
    }
    array[count] = NULL;
    return (array);
}
