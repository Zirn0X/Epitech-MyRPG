/*
** EPITECH PROJECT, 2022
** objects_set.h
** File description:
** objects_set
*/

#ifndef OBJECTS_SET_H_
    #define OBJECTS_SET_H_

typedef struct my_rpg_s my_rpg_t;

int set_lantern(my_rpg_t *rpg);
void set_health_potion(my_rpg_t *rpg);
void set_defense_potion(my_rpg_t *rpg);
void set_attack_potion(my_rpg_t *rpg);
void set_speed_potion(my_rpg_t *rpg);
void set_bandage(my_rpg_t *rpg);
void set_obj_mushroom(my_rpg_t *rpg);
void set_obj_paper(my_rpg_t *rpg);
void set_obj_cape(my_rpg_t *rpg);
int set_quest_object(my_rpg_t *rpg);

#endif /* !OBJECTS_SET_H_ */
