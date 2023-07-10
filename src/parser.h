#ifndef PARSER_H
#define PARSER_H

#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define VERTICES 100

void get_file_data(char *file_name, obj_data *data);

void move_x(double shift, obj_data *data);
void move_y(double shift, obj_data *data);
void move_z(double shift, obj_data *data);

void scale(double ratio, obj_data *data);

void rotate(double degree_x, double degree_y, double degree_z, obj_data *data);

void filling_ver_and_faces(obj_data* data, char *file_name);
void filling_v(char *str_in_file, vertices *vert, int i);
void filling_f(char *str_in_file, surfaces *surf, int i, int len);
void filling_str(char *str_in_file, char *array_of_numbers, int *i_number, int *j_str, int* j_arr);
void check_space(char ch, int *space_flag);
int count_amount_of_vert(char *str_in_file);
int countPoint(char *number);
double convertValue(char *number);
void count_ver_and_faces(FILE *obj_file, obj_data *data);
FILE *open_file_func(char *file_name);
vertices *allocate_memory_vert(int amount_ver);
surfaces *allocate_memory_surf(int amount_surf);

#endif  // PARSER_H
