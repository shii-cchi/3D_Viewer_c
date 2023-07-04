#ifndef PARSER_H
#define PARSER_H

#define VERTICES 100
#define POINTS_FOR_SURFACE 3

typedef struct {
  double x;
  double y;
  double z;
} vertices;

typedef struct {
  vertices **surfaces;
} surfaces;

vertices *get_vertices(char *file_name, int *count_vertices);
surfaces *get_surfaces(char *file_name, int *count_surfaces);

void move_x(int shift, vertices *all_vertices);
void move_y(int shift, vertices *all_vertices);
void move_z(int shift, vertices *all_vertices);

void scale(int ratio, vertices *all_vertices);

void rotate(double degree_x, double degree_y, double degree_z, vertices *all_vertices);

#endif  // PARSER_H