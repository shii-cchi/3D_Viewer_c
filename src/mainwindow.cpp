#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("3D_Viewer");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"), "/home/", tr("Files (*.obj)"));

    if (file_name != "") {
        char *file_name_char = file_name.toLocal8Bit().data();

        clear_data();
        get_file_data(file_name_char, &data);

        ui->info_file_name->setText(get_file_name(file_name));

        ui->info_vertices->setText(QString::number(data.count_vertices));
        ui->info_surfaces->setText(QString::number(data.count_surfaces));

        if (data.all_vertices && data.all_surfaces) {
            ui->view_window->send_data(data);
            ui->view_window->update();
        } else {
            ui->error->setText("Файл пустой или недостаточно данных");
        }
    } else {
        ui->error->setText("Откройте файл");
    }
}

void MainWindow::clear_data() {
    data.all_vertices = nullptr;
    data.all_surfaces = nullptr;
    data.amount_of_vertices_in_surfaces = 0;
    data.count_vertices = 0;
    data.count_surfaces = 0;
}

QString MainWindow::get_file_name(QString file_name) {
    QStringList splited_str = file_name.split("/");
    file_name = splited_str.last();
    return file_name;
}

void MainWindow::on_pushButton_move_clicked()
{
//    bool x_err, y_err, z_err;
//    double shift_x = ui->x_move->text().toDouble(&x_err);
//    double shift_y = ui->y_move->text().toDouble(&y_err);
//    double shift_z = ui->z_move->text().toDouble(&z_err);

//    if (x_err && y_err && z_err) {
//        move_x(shift_x, data.all_vertices, data.count_vertices);
//        move_y(shift_y, data.all_vertices, data.count_vertices);
//        move_z(shift_z, data.all_vertices, data.count_vertices);
//    } else {
//        // error
//    }
    ui->view_window->update();
}

void MainWindow::on_pushButton_rotate_clicked()
{
//    bool x_err, y_err, z_err;
//    double degree_x = ui->x_rotate->text().toDouble(&x_err);
//    double degree_y = ui->y_rotate->text().toDouble(&y_err);
//    double degree_z = ui->z_rotate->text().toDouble(&z_err);

//    if (x_err && y_err && z_err) {
//        rotate(degree_x, degree_y, degree_z, data.all_vertices, data.count_vertices);
//    } else {
//        // error
//    }
    ui->view_window->update();
}

void MainWindow::on_pushButton_scale_clicked()
{
//    bool ratio_err;
//    double ratio = ui->scale->text().toDouble(&ratio_err);

//    if (ratio_err) {
//        scale(ratio, data.all_vertices, data.count_vertices);
//    } else {
//        // error
//    }
    ui->view_window->update();
}

