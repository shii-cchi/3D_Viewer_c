#include "transform.h"

void rotate(double degree_x, double degree_y, double degree_z, obj_data *data) {
    rotate_x(data, degree_x);
    rotate_y(data, degree_y);
    rotate_z(data, degree_z);   
}

void rotate_x(obj_data *data, double degree_x) {
    degree_x = convert_to_rad(degree_x);
    for(int i = 0; i < data->count_vertices; i++) {
        data->all_vertices[i].y = data->all_vertices[i].y*cos(degree_x) 
        - data->all_vertices[i].z*sin(degree_x);
        data->all_vertices[i].z = data->all_vertices[i].y*sin(degree_x) 
        + data->all_vertices[i].z*cos(degree_x);
    }
 }

void rotate_y(obj_data *data, double degree_y) {
    degree_y = convert_to_rad(degree_y);
    for(int i = 0; i < data->count_vertices; i++) {
        data->all_vertices[i].x = data->all_vertices[i].x*cos(degree_y) 
        + data->all_vertices[i].z*sin(degree_y);
        data->all_vertices[i].z = -data->all_vertices[i].x*sin(degree_y) 
        + data->all_vertices[i].z*cos(degree_y);
    }
 }

void rotate_z(obj_data *data, double degree_z) {
    degree_z = convert_to_rad(degree_z);
    for(int i = 0; i < data->count_vertices; i++) {
        data->all_vertices[i].x = data->all_vertices[i].x*cos(degree_z) 
        - data->all_vertices[i].y*sin(degree_z);
        data->all_vertices[i].y = data->all_vertices[i].x*sin(degree_z) 
        + data->all_vertices[i].y*cos(degree_z);
    }
 }

double convert_to_rad(double degree) {
    return (degree/360)*M_PI;
}

void scale(double ratio, obj_data *data) {
    for(int i = 0; i < data->count_vertices; i++) {
        data->all_vertices[i].x *= ratio;
        data->all_vertices[i].y *= ratio;
        data->all_vertices[i].z *= ratio;
    }
}

void move_coord(double shift_x, double shift_y, double shift_z, obj_data *data) {
    for(int i = 0; i < data->count_vertices; i++) {
        data->all_vertices[i].x += shift_x;
        data->all_vertices[i].y += shift_y;
        data->all_vertices[i].z += shift_z;
    }
}
