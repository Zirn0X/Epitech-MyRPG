/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Action player interact
*/

#include "my_macro.h"
#include "my_rpg.h"

static sfVector2f get_max_pos(sfVector2f pos, sfVector2f size)
{
    sfVector2f max_pos = {0, 0};

    max_pos.x = (pos.x + size.x);
    max_pos.y = pos.y + size.y;
    return (max_pos);
}

static void speak_to_npc(my_rpg_t *rpg, sfVector2f pos)
{
    if (pos.x + 75 >= rpg->npcs->rect_npc->hit_min.x
        && pos.x + 75 <= rpg->npcs->rect_npc->hit_max.x
        && pos.y >= rpg->npcs->rect_npc->hit_min.y
        && pos.y<= rpg->npcs->rect_npc->hit_max.y) {
        if (rpg->game->current_dialog != 4 && rpg->game->is_in_dialog == 0) {
            rpg->game->is_in_dialog = 1;
        }
    }
}

void action_player_interact(my_rpg_t *rpg)
{
    sfVector2f pos = {0, 0};

    if (rpg->manager->input->keys[KEY_INTERACT]->status == true) {
        pos = sfRectangleShape_getPosition(rpg->npcs->rect_npc->rect_shape);
        rpg->npcs->rect_npc->hit_min = pos;
        rpg->npcs->rect_npc->hit_max =
                get_max_pos(pos, sfRectangleShape_getSize(rpg->npcs->
                        rect_npc->rect_shape));
        speak_to_npc(rpg, (sfVector2f) {rpg->player->sprite->position.x,
                                        rpg->player->sprite->position.y});
    } else
        rpg->player->actions[ACTION_INTERACTION_P].activate = false;
}
