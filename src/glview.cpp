#include "glview.h"

GlView::GlView(QWidget *parent)
    : QOpenGLWidget{parent}
{
    data_initialized = false;
}

void GlView::send_data(obj_data file_data) {
    clear_data();
    data = file_data;
    data_initialized = true;
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

    buffers_initialized = false;

    create_shaders();
}

void GlView::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void GlView::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor4f(1.0f, 0.0f, 1.0f, 1.0f);

    if (data_initialized) {
        shader_program.bind();

        if (!buffers_initialized) {
            initialize_surfaces_buffer();
            initialize_vertices_buffer();
            buffers_initialized = true;
        } else {
            update_buffers();
        }

        vertices_buffer.bind();
        shader_program.setAttributeBuffer("position", GL_DOUBLE, 0, 3, sizeof(vertices));
        shader_program.enableAttributeArray("position");

        surfaces_buffer.bind();

        for (int i = 0; i < data.count_surfaces; ++i) {
            glDrawElements(GL_LINE_STRIP, data.all_surfaces[i].amount_of_vertices, GL_UNSIGNED_INT, &data.all_surfaces[i]);
        }

        vertices_buffer.release();
        surfaces_buffer.release();
        shader_program.disableAttributeArray("position");
        shader_program.release();
    }
}

void GlView::initialize_vertices_buffer() {
    vertices_buffer.create();
    vertices_buffer.bind();
    vertices_buffer.allocate(data.all_vertices, sizeof(vertices) * data.count_vertices);
    vertices_buffer.release();
}

void GlView::initialize_surfaces_buffer() {
    surfaces_buffer.create();
    surfaces_buffer.bind();

    int count_indices = 0;
    for (int i = 0; i < data.count_surfaces; ++i) {
        count_indices += data.all_surfaces[i].amount_of_vertices;
    }
    
    surfaces_buffer.allocate(nullptr, sizeof(unsigned int) * count_indices);
    
    int offset = 0;
    for (int i = 0; i < data.count_surfaces; ++i) {
        surfaces_buffer.write(offset * sizeof(unsigned int), data.all_surfaces[i].indices, sizeof(unsigned int) * data.all_surfaces[i].amount_of_vertices);
        offset += data.all_surfaces[i].amount_of_vertices;
    }
    
    surfaces_buffer.release();
}

void GlView::update_buffers() {
    vertices_buffer.bind();
    vertices_buffer.write(0, data.all_vertices, sizeof(vertices) * data.count_vertices);
    vertices_buffer.release();
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
    shader_program.addShaderFromSourceCode(QOpenGLShader::Vertex, vertices_shader_source);
    shader_program.bindAttributeLocation("position", 0);
    shader_program.link();
}
