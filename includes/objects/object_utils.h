/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** object_utils
*/

#ifndef OBJECT_UTILS_H_
    #define OBJECT_UTILS_H_

typedef struct my_rpg_s my_rpg_t;
typedef struct objects_s objects_t;

void delete_from_inventory(my_rpg_t *rpg, int idx);
void add_to_inventory(my_rpg_t *rpg, objects_t *obj, char *file, int idx);
void init_object(objects_t *object);

#endif /* !OBJECT_UTILS_H_ */
