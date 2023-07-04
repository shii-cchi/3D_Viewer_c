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
        int count_vertices = 0, count_surfaces = 0;

        vertices *all_vertices = get_vertices(file_name_char, &count_vertices);
        surfaces *all_surfaces = get_surfaces(file_name_char, &count_surfaces);

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

