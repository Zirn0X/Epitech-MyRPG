/*
** EPITECH PROJECT, 2022
** My RPG
** File description:
** Header lib
*/

#ifndef MY_H
    #define MY_H
    #include <SFML/Window/Mouse.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector3.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdbool.h>

typedef struct objects_s objects_t;

// TOOLS LIB
char *my_strcat(char *str1, char *str2);
int my_getnbr(char const *str);
void my_strcpy(char *dest, char const *src);
int my_strcmp(char const *str1, char const *str2);
int my_strlen(char const *len);
int **create_array_int(int len_array, int len_lines);
char **create_tab(int nb_str, ...);
int *create_str_int(int nb_int, ...);
int my_atoi(char const *str);
bool is_point_in_circle(float *pos_point, float pos_y_circle,
float pos_x_circle, float range);
int f_get_rand(int min, int max);
float f_get_rand_float(float min, float max);
char *my_itoa(int nb);

// Files LIB
char *read_file_w_stat(char * const pathfile);
char *read_file_wo_stat(char * const pathfile, int *lines);

// ARRAY LIB
int my_array_len(char **array);
char **my_str_to_word_array(char *str, char p_break);

// CSFML LIB
void set_texture_sprite(sfSprite **sprite, sfTexture *texture,
char *file_texture, sfIntRect rect);
sfIntRect set_rect(int width, int left, int top, int height);
void move_rect(sfIntRect *rect, int offset, int max_value, int min);
void create_sprite(sfSprite **sprite, sfTexture **texture, sfVector2f position,
char * const path_file);
objects_t *create_object(char *name, int quantity, int durability, int damage);
int find_player_pos(float pos, int tuile_max, float size_tuile);

#endif /* !MY_H */
