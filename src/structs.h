#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
  double x;
  double y;
  double z;
} vertices;

typedef struct {
  vertices *all_vertices;
  unsigned int **all_surfaces;
  int count_vertices;
  int count_surfaces;
} obj_data;

#endif  // STRUCTS_H
