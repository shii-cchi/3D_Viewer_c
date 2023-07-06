#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

extern "C" {
#include "parser.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_move_clicked();

    void on_pushButton_rotate_clicked();

    void on_pushButton_scale_clicked();

private:
    Ui::MainWindow *ui;
    vertices *all_vertices;
    vertices **all_surfaces;
    int count_vertices;
    int count_surfaces;
    void clear_data();
};
#endif // MAINWINDOW_H
