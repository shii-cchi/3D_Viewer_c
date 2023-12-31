#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowTitle("3D_Viewer");

  data.all_vertices = nullptr;
  data.all_surfaces = nullptr;
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_file_clicked() {
  set_default_settings();

  QString file_name = QFileDialog::getOpenFileName(
      this, tr("Open File"), "/home/", tr("Files (*.obj)"));

  if (file_name != "") {
    char *file_name_char = file_name.toLocal8Bit().data();

    clear_data();
    get_file_data(file_name_char, &data);

    ui->file_name->setText(get_file_name(file_name));

    ui->count_vertices->setText(QString::number(data.count_vertices));
    ui->count_surfaces->setText(QString::number(data.count_surfaces));

    if (data.count_vertices != 0 && data.count_surfaces != 0) {
      ui->view_window->send_data(data);
      ui->view_window->update();
    } else if (data.count_vertices == 0 && data.count_surfaces == 0) {
      ui->error_file->setText("Файл пустой");
    } else {
      ui->error_file->setText("Недостаточно данных");
    }
  } else {
    ui->error_file->setText("Откройте файл");
  }
}

void MainWindow::set_default_settings() {
  ui->error_file->setText("");
  ui->error_xyz_scale->setText("");
  ui->file_name->setText("");
  ui->count_vertices->setText("");
  ui->count_surfaces->setText("");
  ui->x->setText("0");
  ui->y->setText("0");
  ui->z->setText("0");
  ui->scale->setText("1");

  ui->view_window->clear_window();
}

void MainWindow::clear_data() {
  if (data.all_vertices != nullptr) {
    free(data.all_vertices);
    data.all_vertices = nullptr;
  }

  if (data.all_surfaces != nullptr) {
    for (int i = 0; i < data.count_surfaces; i++) {
      free(data.all_surfaces[i].indices);
    }
    free(data.all_surfaces);
    data.all_surfaces = nullptr;
  }

  data.count_vertices = 0;
  data.count_surfaces = 0;
}

void MainWindow::closeEvent(QCloseEvent *event) {
  clear_data();
  event->accept();
}

QString MainWindow::get_file_name(QString file_name) {
  QStringList splited_str = file_name.split("/");
  file_name = splited_str.last();
  return file_name;
}

void MainWindow::on_pushButton_move_clicked() {
  ui->error_xyz_scale->setText("");

  if (check_file()) {
    bool x_err, y_err, z_err;
    double shift_x = ui->x->text().toDouble(&x_err);
    double shift_y = ui->y->text().toDouble(&y_err);
    double shift_z = ui->z->text().toDouble(&z_err);

    if (x_err && y_err && z_err) {
      move_coord(shift_x, shift_y, shift_z, &data);
    } else {
      ui->error_xyz_scale->setText("Неверно введенные данные");
    }
    ui->view_window->update();
  }
}

void MainWindow::on_pushButton_rotate_clicked() {
  ui->error_xyz_scale->setText("");

  if (check_file()) {
    bool x_err, y_err, z_err;
    double degree_x = ui->x->text().toDouble(&x_err);
    double degree_y = ui->y->text().toDouble(&y_err);
    double degree_z = ui->z->text().toDouble(&z_err);

    if (x_err && y_err && z_err && is_angles(degree_x, degree_y, degree_z)) {
      rotate(degree_x, degree_y, degree_z, &data);
    } else {
      ui->error_xyz_scale->setText("Неверно введенные данные");
    }
    ui->view_window->update();
  }
}

void MainWindow::on_pushButton_scale_clicked() {
  ui->error_xyz_scale->setText("");

  if (check_file()) {
    bool ratio_err;
    double ratio = ui->scale->text().toDouble(&ratio_err);

    if (ratio_err && ratio > 0) {
      scale(ratio, &data);
    } else {
      ui->error_xyz_scale->setText("Неверно введенные данные");
    }
    ui->view_window->update();
  }
}

bool MainWindow::check_file() {
  bool status = false;

  if (ui->file_name->text() != "" && data.count_vertices != 0 &&
      data.count_surfaces != 0 && ui->error_file->text() == "") {
    status = true;
  }

  return status;
}

bool MainWindow::is_angles(double degree_x, double degree_y, double degree_z) {
  bool status = false;

  if (fabs(degree_x) >= 0 && fabs(degree_x) <= 360 && fabs(degree_y) >= 0 &&
      fabs(degree_y) <= 360 && fabs(degree_z) >= 0 && fabs(degree_z) <= 360) {
    status = true;
  }

  return status;
}
