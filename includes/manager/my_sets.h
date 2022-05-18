/*
** EPITECH PROJECT, 2022
** my_sets.h
** File description:
** my_sets
*/

#ifndef MY_SETS_H_
    #define MY_SETS_H_

typedef struct my_rpg_s my_rpg_t;
typedef struct manager_s manager_t;
typedef struct interface_s interface_t;

int set_camera(my_rpg_t *rpg);
int set_home_camera(my_rpg_t *rpg);
int set_window(manager_t *manager);
void set_cursor(my_rpg_t *rpg);
void set_delta_time(my_rpg_t *rpg);
void set_keys(my_rpg_t *rpg);

#endif /* !MY_SETS_H_ */
