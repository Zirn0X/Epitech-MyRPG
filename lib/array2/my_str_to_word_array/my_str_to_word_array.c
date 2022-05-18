/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my_str_to_word_array.h"

char **get_array(char *str, char p_break, str_word_t *word);

char **my_str_to_word_array(char *str, char p_break)
{
    str_word_t *word = malloc(sizeof(*word));
    char **ret = get_array(str, p_break, word);

    free(word);
    return (ret);
}
