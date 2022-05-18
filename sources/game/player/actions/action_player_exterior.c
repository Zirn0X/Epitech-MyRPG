/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Action player exterior
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

static void leave_exterior(my_rpg_t *rpg, sfVector2f pos)
{
    if (pos.x + 80 >= rpg->game->zone_ext_leave->hit_min.x
        && pos.x + 80 <= rpg->game->zone_ext_leave->hit_max.x
        && pos.y + 80 >= rpg->game->zone_ext_leave->hit_min.y
        && pos.y + 80 <= rpg->game->zone_ext_leave->hit_max.y) {
        rpg->game->scenes = S_CAVE;
        actualise_map(rpg, S_CAVE, CAVE_LAYER, CSV_CAVE);
        rpg->player->sprite->position.x = 528;
        rpg->player->sprite->position.y = 17;
    }
}

void action_player_exterior(my_rpg_t *rpg)
{
    sfVector2f pos;

    if (rpg->manager->input->keys[KEY_LEAVE_EXETERIOR]->status == true &&
        rpg->game->scenes == S_EXTERIORS) {
        pos = sfRectangleShape_getPosition(rpg->game->zone_ext_leave->rect_shape);
        rpg->game->zone_ext_leave->hit_min = pos;
        rpg->game->zone_ext_leave->hit_max =
                get_max_pos(pos,sfRectangleShape_getSize(
                        rpg->game->zone_ext_leave->rect_shape));
        leave_exterior(rpg, rpg->player->sprite->position);
    } else
        rpg->player->actions[KEY_LEAVE_EXETERIOR].activate = false;
}
