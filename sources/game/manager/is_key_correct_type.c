/*
** EPITECH PROJECT, 2022
** is_key_correct_type.c
** File description:
** is_key_correct
*/

#include "my_rpg.h"
#include "my_macro.h"

int is_key_correct_type(my_rpg_t *rpg, int key, int debut, int nb_keys_types)
{
    for (int i = debut; i != nb_keys_types; ++i)
        if (key == i)
            return (SUCCESS);
    return (ERROR);
}
