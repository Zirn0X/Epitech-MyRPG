/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Exteroior scene
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "manager/my_camera.h"
#include "game/game_events.h"

void display_map(my_rpg_t *rpg);
void my_player(my_rpg_t *rpg);
void display_quest(my_rpg_t *rpg);
void display_chatbox(my_rpg_t *rpg, chatbox_t *chat);
void change_chatbox(my_rpg_t *rpg);
void display_quest_mushroom(my_rpg_t *rpg, all_objects_t *all_objects);
void display_quest_paper(my_rpg_t *rpg, all_objects_t *all_objects);
void display_quest_cape(my_rpg_t *rpg, all_objects_t *all_objects);;
void display_hud(my_rpg_t *rpg);

static void get_inventory(my_rpg_t *rpg)
{
    int num_mushrooms = 0;
    int num_papers = 0;
    int num_capes = 0;

    for (int i = 0; i != NB_PLAYER_OBJECTS; i++)
        if (rpg->player->inventory->rectangle[i].obj->flag == 'M')
            num_mushrooms = rpg->player->inventory->rectangle[i].obj->quantity;
    if (num_mushrooms == 10 && rpg->game->current_dialog == CHATBOX_1) {
        rpg->game->quests += 1;
        rpg->game->current_dialog += 1;
    }
    for (int i = 0; i != NB_PLAYER_OBJECTS; i++)
        if (rpg->player->inventory->rectangle[i].obj->flag == 'P')
            num_papers = rpg->player->inventory->rectangle[i].obj->quantity;
    if (num_papers == 3 && rpg->game->current_dialog == CHATBOX_2) {
        rpg->game->quests += 1;
        rpg->game->current_dialog += 1;
    }
    for (int i = 0; i != NB_PLAYER_OBJECTS; i++)
        if (rpg->player->inventory->rectangle[i].obj->flag == 'C')
            num_capes = rpg->player->inventory->rectangle[i].obj->quantity;
    if (num_capes == 5 && rpg->game->current_dialog == CHATBOX_3) {
        rpg->game->quests += 1;
        rpg->game->current_dialog += 1;
    }
}

int get_pos_player(my_rpg_t *rpg, sfVector2f pos)
{
    if (pos.x + 75 >= rpg->npcs->rect_npc->hit_min.x
        && pos.x + 75 <= rpg->npcs->rect_npc->hit_max.x
        && pos.y >= rpg->npcs->rect_npc->hit_min.y
        && pos.y<= rpg->npcs->rect_npc->hit_max.y) {
        return 1;
    }
    return 0;
}

int exterior_scene(my_rpg_t *rpg)
{
    sfSprite *t = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile("assets/speak.png", NULL);
    sfSprite_setTexture(t, text, sfFalse);
    display_map(rpg);
    camera_follow_player(rpg);
    sfRenderWindow_drawRectangleShape(rpg->manager->window,
    rpg->npcs->rect_npc->rect_shape, sfFalse);
    display_quest_mushroom(rpg, rpg->all_objects);
    display_quest_paper(rpg, rpg->all_objects);
    display_quest_cape(rpg, rpg->all_objects);
    my_player(rpg);
    display_quest(rpg);
    get_inventory(rpg);
    if (rpg->game->is_in_dialog == 1)
        change_chatbox(rpg);
    display_hud(rpg);
    return (SUCCESS);
}
