/*
** EPITECH PROJECT, 2022
** my_main.c
** File description:
** my_main
*/

#include "my_macro.h"

int my_rpg(void);

int main(const int ac, const char **av)
{
    if (my_rpg() == ERROR)
        return (ERROR);
    return (0);
}