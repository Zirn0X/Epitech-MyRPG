/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** player_competencies
*/

#ifndef PLAYER_COMPETENCIES_H_
    #define PLAYER_COMPETENCIES_H_
    #include <SFML/Graphics.h>

typedef struct my_rpg_s my_rpg_t;
typedef struct player_competencies_s player_competencies_t;

// Competencies points
void add_point_health(player_competencies_t *p, int value);
void add_point_defense(player_competencies_t *p, int value);
void add_point_attack(player_competencies_t *p, int value);
void add_point_speed(player_competencies_t *p, int value);

// Competencies boost
void use_health_potion(my_rpg_t *rpg, sfEventType event, int key, int idx);
void use_defense_potion(my_rpg_t *rpg, sfEventType event, int key, int idx);
void use_attack_potion(my_rpg_t *rpg, sfEventType event, int key, int idx);
void use_speed_potion(my_rpg_t *rpg, sfEventType event, int key, int idx);
void use_bandage(my_rpg_t *rpg, sfEventType event, int key, int idx);

#endif /* !PLAYER_COMPETENCIES_H_ */
