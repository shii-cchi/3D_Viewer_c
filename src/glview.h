#ifndef GLVIEW_H
#define GLVIEW_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>


class GlView : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit GlView(QWidget *parent = nullptr);

private:
    QOpenGLBuffer vertices_buffer;
    QOpenGLBuffer surfaces_buffer;
    QOpenGLShaderProgram shader_program;
    bool buffers_initialized;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void initialize_vertices_buffer();
    void initialize_surfaces_buffer();
    void create_shaders();
    void update_buffers();
};

#endif // GLVIEW_H
