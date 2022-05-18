/*
** EPITECH PROJECT, 2022
** room.c
** File description:
** room
*/

#include "my_rpg.h"
#include "my_macro.h"
#include "manager/my_camera.h"
#include "game/game_events.h"

void display_map(my_rpg_t *rpg);
void my_player(my_rpg_t *rpg);
int exterior_scene(my_rpg_t *rpg);
int pause_scene(my_rpg_t *rpg);
int competencies_scene(my_rpg_t *rpg);
void display_quest_mushroom(my_rpg_t *rpg, all_objects_t *all_objects);
void display_quest_paper(my_rpg_t *rpg, all_objects_t *all_objects);
void display_quest_cape(my_rpg_t *rpg, all_objects_t *all_objects);
void display_before_effects(my_rpg_t *rpg);
void life_bar_follow_hud(my_rpg_t *rpg);

void display_hud(my_rpg_t *rpg)
{
    life_bar_follow_hud(rpg);
    sfRenderWindow_drawRectangleShape(rpg->manager->window,
    rpg->player->sprite->bar_life, NULL);
}

void display_quest(my_rpg_t *rpg)
{
    rpg->quests[rpg->game->quests].sprite->position = (sfVector2f)
    {rpg->player->sprite->position.x - 765, rpg->player->sprite->position.y
    - 330};
    rpg->quests[rpg->game->quests].text->position = (sfVector2f)
    {rpg->player->sprite->position.x - 715, rpg->player->sprite->position.y
    - 270};
    sfSprite_setPosition(rpg->quests[rpg->game->quests].sprite->sprite,
    rpg->quests[rpg->game->quests].sprite->position);
    sfText_setPosition(rpg->quests[rpg->game->quests].text->text,
    rpg->quests[rpg->game->quests].text->position);
    sfRenderWindow_drawSprite(rpg->manager->window,
    rpg->quests[rpg->game->quests].sprite->sprite, sfFalse);
    sfRenderWindow_drawText(rpg->manager->window, rpg->quests
    [rpg->game->quests].text->text, sfFalse);
}

int manoir_scenes(my_rpg_t *rpg)
{
    display_map(rpg);
    display_before_effects(rpg);
    camera_follow_player(rpg);
    my_player(rpg);
    display_quest(rpg);
    return (SUCCESS);
}

int cave_scene(my_rpg_t *rpg)
{
    display_map(rpg);
    camera_follow_player(rpg);
    my_player(rpg);
    display_quest(rpg);
}

int scenes_game(my_rpg_t *rpg)
{
    if (rpg->game->scenes == S_MANOIR)
        manoir_scenes(rpg);
    if (rpg->game->scenes == S_EXTERIORS)
        exterior_scene(rpg);
    if (rpg->game->scenes == S_PAUSE)
        pause_scene(rpg);
    if (rpg->game->scenes == S_COMPETENCIES)
        competencies_scene(rpg);
    if (rpg->game->scenes == S_CAVE)
        cave_scene(rpg);
    return (SUCCESS);
}
