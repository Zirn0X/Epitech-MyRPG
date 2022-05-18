/*
** EPITECH PROJECT, 2022
** set_csv.h
** File description:
** set_csv
*/

#ifndef SET_CSV_H_
    #define SET_CSV_H_

typedef struct csv_s csv_t;

void set_csv_manoir(csv_t *csv, int len_csv, int len_csv_lines);
void set_csv_exteriors(csv_t *csv, int len_csv, int len_csv_lines);
void set_csv_cave(csv_t *csv, int len_csv, int len_csv_lines);

#endif /* !SET_CSV_H_ */
