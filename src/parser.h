#ifndef PARSER_H
#define PARSER_H

#define VERTICES 100
#define POINTS_FOR_SURFACE 3

typedef struct {
  double x;
  double y;
  double z;
} vertices;

vertices *get_vertices(char *file_name, int *count_vertices);
vertices **get_surfaces(char *file_name, int *count_surfaces);

void move_x(double shift, vertices *all_vertices, int count_vertices);
void move_y(double shift, vertices *all_vertices, int count_vertices);
void move_z(double shift, vertices *all_vertices, int count_vertices);

void scale(double ratio, vertices *all_vertices, int count_vertices);

void rotate(double degree_x, double degree_y, double degree_z, vertices *all_vertices, int count_vertices);

#endif  // PARSER_H
