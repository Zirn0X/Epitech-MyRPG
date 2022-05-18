/*
** EPITECH PROJECT, 2021
** my_atoi
** File description:
** my_atoi
*/

int my_atoi(char const *str)
{
    int res = 0;
    int neg = 0;

    if (str[0] == '-') {
        str += 1;
        neg = 1;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        res = res * 10;
        res = res + (str[i] - '0');
    }
    if (neg == 1)
        res = res * -1;
    return (res);
}
