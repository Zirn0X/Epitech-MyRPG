/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** quest_function
*/

#ifndef QUEST_FUNCTION_H_
    #define QUEST_FUNCTION_H_

typedef struct my_rpg_s my_rpg_t;

void initialize_obj_paper(my_rpg_t *rpg, int i);
void initialize_obj_mushroom(my_rpg_t *rpg, int i);
void initialize_obj_cape(my_rpg_t *rpg, int i);
void set_pos_obj_paper(all_objects_t *all_objects);
void set_pos_obj_mushroom(all_objects_t *all_objects);
void set_pos_obj_cape(all_objects_t *all_objects);
#endif /* !QUEST_FUNCTION_H_ */
