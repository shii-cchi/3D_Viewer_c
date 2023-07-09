#ifndef PARSER_H
#define PARSER_H

#include "structs.h"

#define VERTICES 100

void get_file_data(char *file_name, obj_data *data);

void move_x(double shift, obj_data *data);
void move_y(double shift, obj_data *data);
void move_z(double shift, obj_data *data);

void scale(double ratio, obj_data *data);

void rotate(double degree_x, double degree_y, double degree_z, obj_data *data);

#endif  // PARSER_H
