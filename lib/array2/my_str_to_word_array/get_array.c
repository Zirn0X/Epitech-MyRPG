/*
** EPITECH PROJECT, 2022
** get_array.c
** File description:
** get_array
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_str_to_word_array.h"

static int skip_same_p_break(char *str, char p_break, int *i)
{
    if (str[*i] == p_break || str[*i] == '\t') {
        while (str[*i] == p_break || str[*i] == '\t')
            *i += 1;
        if (str[*i] == '\0')
            return (-1);
        return (1);
    }
    return (0);
}

static int count_word(char * const str, char const p_break)
{
    int skip = 0;
    int len_ret = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        skip = skip_same_p_break(str, p_break, &i);
        if (skip == 1)
            len_ret++;
        if (skip == -1)
            break;
    }
    return (len_ret);
}

static char **malloc_str(char *str, char p_break)
{
    char **ret = NULL;
    int ret_x = 0;
    int ret_y = 0;
    int skip = 0;
    int word = count_word(str, p_break);

    ret = malloc(sizeof(char *) * ((word + 1) + 1));
    for (int i = 0; str[i] != '\0'; ++i, ret_x++) {
        skip = skip_same_p_break(str, p_break, &i);
        if (skip == 1) {
            ret[ret_y] = malloc(sizeof(char) * (ret_x + 1));
            ret_x = 0;
            ret_y += 1;
        }
        if (skip == -1)
            break;
    }
    ret[ret_y] = malloc(sizeof(char) * (ret_x + 1));
    return (ret);
}

static int condition(str_word_t *word, char p_break)
{
    if (word->str[word->i] == p_break || word->str[word->i] == '\t') {
        word->ret[word->ret_y][word->ret_x] = '\0';
        while (word->str[word->i] == p_break || word->str[word->i] == '\t')
            word->i += 1;
        if (word->str[word->i] == '\0')
            return (42);
        word->ret[word->ret_y][word->ret_x] = '\0';
        word->ret_y += 1;
        word->ret_x = 0;
    }
    return (0);
}

char **get_array(char *str, char p_break, str_word_t *word)
{
    int skip = 0;

    word->str = str;
    word->ret = malloc_str(str, p_break);
    word->ret_x = 0;
    word->ret_y = 0;
    for (; word->str[skip] == p_break || word->str[skip] == '\t'; skip++);
    word->str += skip;
    for (word->i = 0; word->str[word->i] != '\0'; word->i++, word->ret_x++) {
        if (condition(word, p_break) == 42)
            break;
        word->ret[word->ret_y][word->ret_x] = word->str[word->i];
    }
    word->ret[word->ret_y][word->ret_x] = '\0';
    word->ret[word->ret_y + 1] = NULL;
    return (word->ret);
}
