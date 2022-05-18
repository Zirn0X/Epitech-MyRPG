/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Set NPC
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_macro.h"
#include "my_lib.h"

int set_npcs(my_rpg_t *rpg)
{
    rpg->npcs->rect_npc = malloc(sizeof(my_rectshape_t)* NPCS_NB);

    if (rpg->npcs->rect_npc == NULL)
        return (ERROR);
    rpg->npcs->rect_npc->position = (sfVector2f) {2560.0, 846.0};
    rpg->npcs->rect_npc->rect_shape = sfRectangleShape_create();
    rpg->npcs->rect_npc->texture = sfTexture_createFromFile("assets/npc.png", NULL);
    sfRectangleShape_setTexture(rpg->npcs->rect_npc->rect_shape, rpg->npcs->rect_npc->texture, sfFalse);
    sfRectangleShape_setPosition(rpg->npcs->rect_npc->rect_shape, rpg->npcs->rect_npc->position);
    sfRectangleShape_setSize(rpg->npcs->rect_npc->rect_shape, (sfVector2f) {50, 70});
    return (SUCCESS);
}
