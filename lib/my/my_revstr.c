/*
** EPITECH PROJECT, 2021
** my revstr
** File description:
** my_revstr
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    char p;
    int char1 = 0;
    int lastchar = my_strlen(str) - 1;

    while (char1 < lastchar) {
        p = str[char1];
        str[char1] = str[lastchar];
        str[lastchar] = p;
        char1++;
        lastchar--;
    }
    return (str);
}
