#include "glview.h"

GlView::GlView(QWidget *parent)
    : QOpenGLWidget{parent}
{

}

void GlView::initializeGL() {
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void GlView::resizeGL(int w, int h) {
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glViewport(0, 0, w, h);
}

void GlView::paintGL() {
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClear(GL_COLOR_BUFFER_BIT);

//    for (int i = 0; i <= count_vertices; i++) {
//        f->glVertexAttrib3fv(0, MainWindow::all_vertices[i].x, MainWindow::all_vertices[i].y, MainWindow::all_vertices[i].z);
//    }
}