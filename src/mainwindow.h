#ifndef SRC_MAINWINDOW_H
#define SRC_MAINWINDOW_H

#include <QCloseEvent>
#include <QFileDialog>
#include <QMainWindow>

extern "C" {
#include "parser.h"
#include "transform.h"
}

#include "structs.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_file_clicked();

  void on_pushButton_move_clicked();

  void on_pushButton_rotate_clicked();

  void on_pushButton_scale_clicked();

 private:
  Ui::MainWindow *ui;
  obj_data data;

  void set_default_settings();
  void clear_data();
  void closeEvent(QCloseEvent *event) override;
  QString get_file_name(QString file_name);
  bool check_file();
  bool is_angles(double degree_x, double degree_y, double degree_z);
};
#endif  // SRC_MAINWINDOW_H
