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
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

};

#endif // GLVIEW_H
