#ifndef SRC_GLVIEW_H
#define SRC_GLVIEW_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "structs.h"

class GlView : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit GlView(QWidget *parent = nullptr);

    void send_data(obj_data file_data);
    void clear_window();

private:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    
    obj_data data;
    bool data_initialized;
};

#endif // SRC_GLVIEW_H
