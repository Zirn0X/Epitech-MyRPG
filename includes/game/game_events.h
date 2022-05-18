/*
** EPITECH PROJECT, 2022
** game_events.h
** File description:
** game_events
*/

#ifndef GAME_EVENTS_H_
    #define GAME_EVENTS_H_

typedef struct my_rpg_s my_rpg_t;

void room_events(my_rpg_t *rpg);
void competencies_event(my_rpg_t *rpg);
void pause_events(my_rpg_t *rpg);
void exterior_events(my_rpg_t *rpg);

#endif /* !GAME_EVENTS_H_ */
