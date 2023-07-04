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
        ui->info_file_name->setText(file_name);

        char *file_name_char = file_name.toLocal8Bit().data();

        clear_data();

        all_vertices = get_vertices(file_name_char, &count_vertices);
        all_surfaces = get_surfaces(file_name_char, &count_surfaces);

        ui->info_vertices->setText(QString::number(count_vertices));
        ui->info_surfaces->setText(QString::number(count_surfaces));

        if (all_vertices && all_surfaces) {
            //draw model
        } else {
            ui->error->setText("Файл пустой или недостаточно данных?");
        }
    } else {
        ui->error->setText("Откройте файл");
    }
}

void MainWindow::clear_data() {
    all_vertices = nullptr;
    all_surfaces = nullptr;
    count_vertices = 0;
    count_surfaces  = 0;
}

void MainWindow::on_pushButton_move_clicked()
{
    bool x_err, y_err, z_err;
    double shift_x = ui->x_move->text().toDouble(&x_err);
    double shift_y = ui->y_move->text().toDouble(&y_err);
    double shift_z = ui->z_move->text().toDouble(&z_err);

    if (x_err && y_err && z_err) {
        move_x(shift_x, all_vertices);
        move_y(shift_y, all_vertices);
        move_z(shift_z, all_vertices);
    } else {
        // error
    }
}

void MainWindow::on_pushButton_rotate_clicked()
{
    bool x_err, y_err, z_err;
    double degree_x = ui->x_rotate->text().toDouble(&x_err);
    double degree_y = ui->y_rotate->text().toDouble(&y_err);
    double degree_z = ui->z_rotate->text().toDouble(&z_err);

    if (x_err && y_err && z_err) {
        rotate(degree_x, degree_y, degree_z, all_vertices);
    } else {
        // error
    }
}

void MainWindow::on_pushButton_scale_clicked()
{
    bool ratio_err;
    double ratio = ui->scale->text().toDouble(&ratio_err);

    if (ratio_err) {
        scale(ratio, all_vertices);
    } else {
        // error
    }
}

