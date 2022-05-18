/*
** EPITECH PROJECT, 2022
** my_input.H
** File description:
** my_input
*/

#ifndef MY_INPUT_H_
    #define MY_INPUT_H_
    #include <SFML/Graphics.h>

typedef struct my_rpg_s my_rpg_t;

void get_input(my_rpg_t *rpg);
int is_input_valide(my_rpg_t *rpg, sfKeyCode input_key);
int is_key_correct_type(my_rpg_t *rpg, int key, int debut, int nb_keys_types);

#endif /* !MY_INPUT_H_ */
