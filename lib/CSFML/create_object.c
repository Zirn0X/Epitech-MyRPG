/*
** EPITECH PROJECT, 2022
** create_object.c
** File description:
** create_object
*/

#include <stdlib.h>
#include "my_rpg.h"

objects_t *create_object(char *name, int quantity, int durability, int damage)
{
    objects_t *object = malloc(sizeof(objects_t));

    object->name = name;
    object->quantity = quantity;
    object->durability = durability;
    object->damage = damage;
    return (object);
}