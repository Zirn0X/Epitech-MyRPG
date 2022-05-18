/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Set Competencies
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my_rpg.h"
#include "my_lib.h"

int competencies_scenes(my_rpg_t *rpg);

static void create_alls_content(my_rpg_t *rpg)
{
    for (int i = 0; i < 5; i++)
        rpg->menu_competencies->s_competencies[i].sprite = sfSprite_create();
    for (int i = 0; i < 6; i++)
        rpg->menu_competencies->t_competencies[i].text = sfText_create();
    rpg->menu_competencies->b_competencies[0].button = sfRectangleShape_create();
    rpg->menu_competencies->b_competencies[0].texture =
    sfTexture_createFromFile("assets/skills/add_skills.png", NULL);
}

static void set_params_sprites(my_rpg_t *rpg)
{
    for (int i = 0; i < 5; i++) {
        sfSprite_setTexture(rpg->menu_competencies->s_competencies[i].sprite,
                            rpg->menu_competencies->s_competencies[i].texture,
                            sfFalse);
        if (i >= 1)
            sfSprite_setScale(rpg->menu_competencies->s_competencies[i].sprite,
                              (sfVector2f) {0.2, 0.2});
    }
    sfRectangleShape_setSize(rpg->menu_competencies->b_competencies[0].button,
        (sfVector2f) {50, 50});
    sfRectangleShape_setTexture(rpg->menu_competencies->
    b_competencies[0].button,rpg->menu_competencies->
    b_competencies[0].texture, sfFalse);
}

static void set_all_text(my_rpg_t *rpg)
{
    for (int i = 0; i < 6; i++)
        sfText_setFont(rpg->menu_competencies->t_competencies[i].text,
                       rpg->menu_competencies->t_competencies->font);
    for (int i = 2; i < 6; i++) {
        sfText_setColor(rpg->menu_competencies->t_competencies[i].text,
                        sfBlack);
        sfText_setCharacterSize(rpg->menu_competencies->t_competencies[i].text,
                                46);
    }
    rpg->player->compentencies->id = 0;
}

int set_competencies(my_rpg_t *rpg)
{
    rpg->menu_competencies->s_competencies = malloc(sizeof(my_sprite_t) * 5);
    rpg->menu_competencies->t_competencies = malloc(sizeof(my_text_t) * 6);
    rpg->menu_competencies->b_competencies = malloc(sizeof(button_t) * 4);
    rpg->menu_competencies->t_competencies->font =
            sfFont_createFromFile("assets/breathe.ttf");
    create_alls_content(rpg);
    rpg->menu_competencies->s_competencies[0].texture =
            sfTexture_createFromFile("assets/competencies/back_skills.png",
                                     NULL);
    rpg->menu_competencies->s_competencies[1].texture =
            sfTexture_createFromFile("assets/skills/resistance.png", NULL);
    rpg->menu_competencies->s_competencies[2].texture =
            sfTexture_createFromFile("assets/skills/attack.png", NULL);
    rpg->menu_competencies->s_competencies[3].texture =
            sfTexture_createFromFile("assets/skills/life.png", NULL);
    rpg->menu_competencies->s_competencies[4].texture =
            sfTexture_createFromFile("assets/skills/speed.png", NULL);
    set_params_sprites(rpg);
    set_all_text(rpg);
    return (SUCCESS);
}
