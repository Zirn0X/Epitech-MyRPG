/*
** EPITECH PROJECT, 2022
** monsters_sets.h
** File description:
** monsters_sets
*/

#ifndef MONSTERS_SETS_H_
    #define MONSTERS_SETS_H_

typedef struct my_rpg_s my_rpg_t;
typedef struct monster_type_s monster_type_t;

void set_flying_eye(my_rpg_t *rpg, monster_type_t *monsters);
void set_thief(my_rpg_t *rpg, monster_type_t *monsters);
void set_cyclope(my_rpg_t *rpg, monster_type_t *monsters);
void set_skeleton(my_rpg_t *rpg, monster_type_t *monsters);


#endif /* !MONSTERS_SETS_H_ */
