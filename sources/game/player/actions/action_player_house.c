/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Action player house
*/

#include "my_rpg.h"
#include "my_macro.h"

void actualise_map(my_rpg_t *rpg, int map, int layer, int csv);

static sfVector2f get_max_pos(sfVector2f pos, sfVector2f size)
{
    sfVector2f max_pos = {0, 0};

    max_pos.x = (pos.x + size.x);
    max_pos.y = pos.y + size.y;
    return (max_pos);
}

static void leave_house(my_rpg_t *rpg, sfVector2f pos)
{
    if (pos.x + 80 >= rpg->game->zone_h_leave->hit_min.x
        && pos.x + 80 <= rpg->game->zone_h_leave->hit_max.x
        && pos.y + 80 >= rpg->game->zone_h_leave->hit_min.y
        && pos.y + 80 <= rpg->game->zone_h_leave->hit_max.y) {
        rpg->game->scenes = S_EXTERIORS;
        actualise_map(rpg, S_EXTERIORS, EXTERIORS_LAYER, CSV_EXTERIORS);
        rpg->player->sprite->position.x = 800;
        rpg->player->sprite->position.y = 1364;
        rpg->game->quests += 1;
    }
/*    rpg->game->scenes = S_CAVE;
    actualise_map(rpg, S_CAVE, CAVE_LAYER, CSV_CAVE);
    rpg->player->pos_x = 528;
    rpg->player->pos_y = 17;
    rpg->game->quests += 1;*/
}

void action_player_house(my_rpg_t *rpg)
{
    sfVector2f pos;

    if (rpg->manager->input->keys[KEY_LEAVE_HOUSE]->status == true &&
    rpg->game->scenes == S_MANOIR) {
        pos = sfRectangleShape_getPosition(rpg->game->zone_h_leave->rect_shape);
        rpg->game->zone_h_leave->hit_min = pos;
        rpg->game->zone_h_leave->hit_max =
                get_max_pos(pos,sfRectangleShape_getSize(
                        rpg->game->zone_h_leave->rect_shape));
        leave_house(rpg, (sfVector2f) {rpg->player->sprite->position.x,
                                        rpg->player->sprite->position.y});
    } else
        rpg->player->actions[KEY_LEAVE_HOUSE].activate = false;
}
