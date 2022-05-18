/*
** EPITECH PROJECT, 2022
** set_mushroom.c
** File description:
** set_mushroom
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

void monsters_deplacement(my_rpg_t *rpg, my_sprite_t *ennemy);
void set_a_action(action_t *action, float *value, void (*function),
bool *bool_action);
sfVector2f set_pos_random_in_spawner(my_rpg_t *rpg, spawner_t *spawner);
void set_bar_life(my_sprite_t *sprite, sfVector2f size, sfVector2f position,
sfColor color);

void set_cyclope(my_rpg_t *rpg, monster_type_t *monsters)
{
    float movement[] = {2.5, 6.0, 0.0};
    bool status[] = {false, false};
    my_sprite_t *monster = rpg->monsters->monsters[M_CYCLOPE].monster;

    monsters->life = 100;
    monsters->damage = 35;
    monster = malloc(sizeof(my_sprite_t) * (M_CYCLOPE_NB));
    for (int i = 0; i != M_CYCLOPE_NB; ++i) {
        monster[i].action = malloc(sizeof(action_t));
        monster[i].spawner = set_pos_random_in_spawner(rpg,
        &rpg->monsters->spawner[SP_CYCLOPE]);
        monster[i].position = monster[i].spawner;
        create_sprite(&monster[i].sprite, &monster[i].texture,
        monster[i].spawner, "assets/monsters/Cyclops.png");
        monster[i].rect = set_rect(64, 0, 67, 67);
        sfSprite_setScale(monster[i].sprite, (sfVector2f) {3, 3});
        sfSprite_setTextureRect(monster[i].sprite, monster[i].rect);
        set_a_action(monster[i].action, movement, &(monsters_deplacement),
        status);
        monster[i].action->speed_max_anim = 0.5;
        monster[i].activate = false;
        monster[i].offset = 64;
        monster[i].off_set_max = 64 * 11;
        monster[i].life = 100;
        monster[i].damage = 35;
        monster[i].scd_attack = 0;
        monster[i].sdc_attack_max = 2.5;
        set_bar_life(&monster[i], (sfVector2f) {monster[i].life, 10}, (sfVector2f)
        {monster[i].position.x - 20, monster[i].position.y - 30}, sfRed);
    }
    rpg->monsters->monsters[M_CYCLOPE].monster = monster;
    rpg->monsters->monsters[M_CYCLOPE].scd_spawn = 0;
    rpg->monsters->monsters[M_CYCLOPE].sp_acce = 3.0;
    rpg->monsters->monsters[M_CYCLOPE].nb_monster = M_CYCLOPE_NB;
}