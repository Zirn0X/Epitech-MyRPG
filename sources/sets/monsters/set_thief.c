/*
** EPITECH PROJECT, 2022
** set_gobelin.c
** File description:
** set_gobelin
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void set_bar_life(my_sprite_t *sprite, sfVector2f size, sfVector2f position,
sfColor color);
void monsters_deplacement(my_rpg_t *rpg, my_sprite_t *ennemy);
void set_a_action(action_t *action, float *value, void (*function),
bool *bool_action);
sfVector2f set_pos_random_in_spawner(my_rpg_t *rpg, spawner_t *spawner);

void set_thief(my_rpg_t *rpg, monster_type_t *monsters)
{
    float movement[] = {2.5, 6.0, 0.0};
    bool status[] = {false, false};
    my_sprite_t *monster = rpg->monsters->monsters[M_THIEF].monster;

    monsters->life = 100;
    monsters->damage = 10;
    monster = malloc(sizeof(my_sprite_t) * (M_THIEF_NB));
    for (int i = 0; i != M_THIEF_NB; ++i) {
        monster[i].action = malloc(sizeof(action_t));
        monster[i].spawner = set_pos_random_in_spawner(rpg,
        &rpg->monsters->spawner[SP_THIEF]);
        monster[i].position = monster[i].spawner;
        create_sprite(&monster[i].sprite, &monster[i].texture,
        monster[i].spawner, "assets/monsters/thief/Tief.png");
        monster[i].rect = set_rect(32, 0, 32, 32);
        sfSprite_setScale(monster[i].sprite, (sfVector2f) {2, 2});
        sfSprite_setTextureRect(monster[i].sprite, monster[i].rect);
        set_a_action(monster[i].action, movement, &(monsters_deplacement),
        status);
        monster[i].action->speed_max_anim = 0.5;
        monster[i].activate = false;
        monster[i].offset = 32;
        monster[i].off_set_max = 96;
        monster[i].life = 100;
        monster[i].damage = 15;
        monster[i].speed_sdc_attack = 3.0;
        monster[i].sdc_attack_max = 3.0;
        set_bar_life(&monster[i], (sfVector2f) {monster[i].life, 10}, (sfVector2f)
        {monster[i].position.x - 20, monster[i].position.y - 30}, sfRed);
    }
    rpg->monsters->monsters[M_THIEF].monster = monster;
    rpg->monsters->monsters[M_THIEF].scd_spawn = 0;
    rpg->monsters->monsters[M_THIEF].sp_acce = 3.0;
    rpg->monsters->monsters[M_THIEF].nb_monster = M_FLYING_EYE_NB;
}