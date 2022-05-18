/*
** EPITECH PROJECT, 2022
** set_flying_eye.c
** File description:
** set_flying_eye
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

void set_flying_eye(my_rpg_t *rpg, monster_type_t *monsters)
{
    float movement[] = {2.5, 6.0, 0.0};
    bool status[] = {false, false};
    my_sprite_t *monster = rpg->monsters->monsters[M_FLYING_EYE].monster;

    monsters->life = 100;
    monsters->damage = 5;
    monster = malloc(sizeof(my_sprite_t) * (M_FLYING_EYE_NB));
    for (int i = 0; i != M_FLYING_EYE_NB; ++i) {
        monster[i].action = malloc(sizeof(action_t));
        monster[i].spawner = set_pos_random_in_spawner(rpg,
        &rpg->monsters->spawner[SP_FLYING_EYE]);
        monster[i].position = monster[i].spawner;
        create_sprite(&monster[i].sprite, &monster[i].texture,
        monster[i].spawner, "assets/monsters/Flying_eye/Flying_eye.png");
        monster[i].rect = set_rect(150, 0, 0, 150);
        sfSprite_setScale(monster[i].sprite, (sfVector2f) {2, 2});
        sfSprite_setTextureRect(monster[i].sprite, monster[i].rect);
        set_a_action(monster[i].action, movement, &(monsters_deplacement),
        status);
        monster[i].action->speed_max_anim = 0.5;
        monster[i].activate = false;
        monster[i].offset = 150;
        monster[i].off_set_max = 750;
        monster[i].life = 100;
        set_bar_life(&monster[i], (sfVector2f) {monster[i].life, 10}, (sfVector2f)
        {monster[i].position.x - 20, monster[i].position.y - 30}, sfRed);
    }
    rpg->monsters->monsters[M_FLYING_EYE].monster = monster;
    rpg->monsters->monsters[M_FLYING_EYE].scd_spawn = 0;
    rpg->monsters->monsters[M_FLYING_EYE].sp_acce = 3.0;
    rpg->monsters->monsters[M_FLYING_EYE].nb_monster = M_FLYING_EYE_NB;
}
