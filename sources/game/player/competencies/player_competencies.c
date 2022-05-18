/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Player competencies
*/

#include "my_rpg.h"

void add_points_competencies(player_competencies_t *p, int value)
{
    p->points += value;
}

void add_point_attack(player_competencies_t *p, int value)
{
    p->attack += value;
}

void add_point_health(player_competencies_t *p, int value)
{
    p->life += value;
}

void add_point_defense(player_competencies_t *p, int value)
{
    p->resistance += value;
}

void add_point_speed(player_competencies_t *p, int value)
{
    p->speed += value;
}
