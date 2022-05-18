/*
** EPITECH PROJECT, 2022
** player_objects.h
** File description:
** player_objects
*/

#ifndef PLAYER_OBJECTS_H_
    #define PLAYER_OBJECTS_H_

typedef struct my_rpg_s my_rpg_t;
typedef struct objects_s objects_t;

void add_object_player(my_rpg_t *rpg, objects_t *object_add, int emplacement);
int is_object_owned(my_rpg_t *rpg, objects_t *object_src);

#endif /* !PLAYER_OBJECTS_H_ */
