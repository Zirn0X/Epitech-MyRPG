/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Set Player Competencies
*/

#include "my_rpg.h"

void set_player_competencies(my_rpg_t *rpg)
{
    rpg->player->compentencies->attack = 1;
    rpg->player->compentencies->life = 1;
    rpg->player->compentencies->resistance = 1;
    rpg->player->compentencies->speed = 1;
    rpg->player->compentencies->points = 10;
}
