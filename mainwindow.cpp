#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stade.h"
MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{
 int id=ui->le_id
    Stade S()
}
