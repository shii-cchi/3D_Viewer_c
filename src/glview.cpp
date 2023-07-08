#include "glview.h"

GlView::GlView(QWidget *parent)
    : QOpenGLWidget{parent}
{

}

void GlView::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    initialize_vertices_buffer();
    initialize_surfaces_buffer();

    create_shaders();
}

void GlView::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void GlView::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader_program.bind();

    // Установка атрибутов вершин
    vertices_buffer.bind();
    shader_program.setAttributeBuffer("position", GL_DOUBLE, 0, 3, sizeof(vertices));
    shader_program.enableAttributeArray("position");

    // Отрисовка модели
    surfaces_buffer.bind();
    glDrawElements(GL_TRIANGLES, count_surfaces * 3, GL_UNSIGNED_INT, nullptr);

    // Отключение атрибутов вершин и шейдеров
    vertices_buffer.release();
    surfaces_buffer.release();
    shader_program.disableAttributeArray("position");
    shader_program.release();
}

void GlView::initialize_vertices_buffer() {
    vertices_buffer.create();
    vertices_buffer.bind();
    vertices_buffer.allocate(all_vertices, sizeof(vertices) * count_vertices);
    vertices_buffer.release();
}

void GlView::initialize_surfaces_buffer() {
    surfaces_buffer.create();
    surfaces_buffer.bind();
    surfaces_buffer.allocate(all_surfaces, sizeof(GLuint) * 3 * count_surfaces);
    surfaces_buffer.release();
}

void GlView::create_shaders() {
    const char *vertices_shader_source =
        "#version 330\n"
        "in vec3 position;\n"
        "void main()\n"
        "{\n"
        "    gl_Position = vec4(position, 1.0);\n"
        "}\n";

    shader_program.create();
    shader_program.addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    shader_program.bindAttributeLocation("position", 0);
    shader_program.link();
}