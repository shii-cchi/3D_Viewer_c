#include "glview.h"

GlView::GlView(QWidget *parent)
    : QOpenGLWidget{parent}
{
    data_initialized = false;
}

void GlView::send_data(obj_data file_data) {
    clear_data();
    data = file_data;
}

void GlView::clear_data() {
    data.all_vertices = nullptr;
    data.all_surfaces = nullptr;
    data.count_vertices = 0;
    data.count_surfaces  = 0;
}

void GlView::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

}

void GlView::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void GlView::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor4f(1.0f, 0.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 1, 99999);
    glTranslatef(0, 0, -2.8);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for (int i = 0; i < data.count_surfaces; ++i) {
        for (int j = 0; j < data.all_surfaces[i].amount_of_vertices; ++j) {
            glBegin(GL_LINE_LOOP);
            glVertex3d(all_surfaces[i].indices[j]->x,
                       all_surfaces[i].indices[j]->y,
                       all_surfaces[i].indices[j]->z);
        }
        glEnd();
    }
}