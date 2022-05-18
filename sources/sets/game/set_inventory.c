/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_inventory
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my_rpg.h"
#include "my_lib.h"
#include "objects/object_utils.h"

int competencies_scenes(my_rpg_t *rpg);
void init_object(objects_t *object);

static void create_alls_content(my_rpg_t *rpg)
{
    for (int i = 0; i < NB_INVENTORY_GUI; i++)
        rpg->player->inventory->sprite[i].sprite = sfSprite_create();
    for (int i = 0; i < NB_PLAYER_OBJECTS; i++) {
        rpg->player->inventory->rectangle[i].rect_shape =
        sfRectangleShape_create();
        rpg->player->inventory->rectangle[i].texture =
        sfTexture_createFromFile("assets/object/nothing.png", NULL);
    }
}

void set_rectangle_pos(my_rpg_t *rpg, int add_x, int add_y, int idx)
{
    int x = rpg->player->sprite->position.x + add_x;
    int y = rpg->player->sprite->position.y + add_y;

    rpg->player->inventory->rectangle[idx].position = (sfVector2f) {x, y};
    sfRectangleShape_setPosition
    (rpg->player->inventory->rectangle[idx].rect_shape,
    rpg->player->inventory->rectangle[idx].position);
}

static void first_init_inventory(my_rpg_t *rpg)
{
    char *string[] = {"assets/object/lantern.png",
        "assets/object/potion_health.png", "assets/object/potion_defense.png",
        "assets/object/potion_attack.png", "assets/object/potion_speed.png"};

    add_to_inventory(rpg, rpg->all_objects->lantern, string[0], 0);
    add_to_inventory(rpg, rpg->all_objects->health_potion, string[1], 1);
    add_to_inventory(rpg, rpg->all_objects->defense_potion, string[2], 2);
    add_to_inventory(rpg, rpg->all_objects->attack_potion, string[3], 3);
    add_to_inventory(rpg, rpg->all_objects->speed_potion, string[4], 4);
}

static void set_rectangle_sprites(my_rpg_t *rpg)
{
    for (int i = 0; i < NB_INVENTORY_GUI; i++)
        sfSprite_setTexture(rpg->player->inventory->sprite[i].sprite,
        rpg->player->inventory->sprite[i].texture, sfFalse);
    for (int i = 0; i < NB_PLAYER_OBJECTS; i++) {
        rpg->player->inventory->rectangle[i].obj = malloc(sizeof(objects_t));
        sfRectangleShape_setSize(rpg->player->inventory->rectangle[i].rect_shape,
        (sfVector2f) {50, 50});
        sfRectangleShape_setTexture
        (rpg->player->inventory->rectangle[i].rect_shape,
        rpg->player->inventory->rectangle[i].texture, sfFalse);
        sfRectangleShape_setScale
        (rpg->player->inventory->rectangle[i].rect_shape,
        (sfVector2f) {1.1, 1.1});
        init_object(rpg->player->inventory->rectangle[i].obj);
    }
    first_init_inventory(rpg);
}

int set_inventory(my_rpg_t *rpg)
{
    rpg->player->inventory = malloc(sizeof(player_inventory_t));
    rpg->player->inventory->rectangle =
    malloc(sizeof(my_rectshape_t) * NB_PLAYER_OBJECTS);
    rpg->player->inventory->sprite =
    malloc(sizeof(my_sprite_t) * NB_INVENTORY_GUI);
    create_alls_content(rpg);
    for (int i = 0; i != NB_INVENTORY_GUI; i++)
        rpg->player->inventory->sprite[i].texture =
        sfTexture_createFromFile("assets/inventory/inventory_bar.png", NULL);
    set_rectangle_sprites(rpg);
    sfSprite_setPosition(rpg->player->inventory->sprite[0].sprite,
    (sfVector2f) {rpg->player->sprite->position.x - 350,
    rpg->player->sprite->position.y + 200});
    return (SUCCESS);
}
