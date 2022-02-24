/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** function that displays
*/

int my_putchar(char);

int my_isneg(int n)
{
    char print;

    if (n >= 0) {
        print = 'P';
        my_putchar(print);
        my_putchar('\n');
    }

    if (n < 0) {
        print = 'N';
        my_putchar(print);
        my_putchar('\n');
    }
}
