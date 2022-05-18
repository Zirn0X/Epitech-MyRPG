/*
** EPITECH PROJECT, 2022
** is_input_valide.c
** File description:
** is_input_valide
*/

#include "my_rpg.h"
#include "my_macro.h"

int is_input_valide(my_rpg_t *rpg, sfKeyCode input_key)
{
    for (int i = 0; i != NB_KEYS; ++i) {
        if (input_key == rpg->manager->input->keys[i]->key)
            return (SUCCESS);
    }
    return (ERROR);
}