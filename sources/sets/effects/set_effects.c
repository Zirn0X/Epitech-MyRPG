/*
** EPITECH PROJECT, 2022
** set_effects.c
** File description:
** set_effects
*/

#include "my_macro.h"
#include "my_rpg.h"
#include "effects/effects_set.h"

int set_effects(my_rpg_t *rpg)
{
    if (set_shadow_effect(rpg) == ERROR)
        return (ERROR);
    if (set_lanthern_effect(rpg) == ERROR)
        return (ERROR);
    return (SUCCESS);
}