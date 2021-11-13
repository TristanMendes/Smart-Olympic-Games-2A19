#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "etudiant.h"
#include <QMainWindow>
#include <QMessageBox>

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
    void on_pushButtonAjouter_clicked();

    void on_pushButton_supprimer_clicked();

private:
    Ui::MainWindow *ui;
    Etudiant E;
};
#endif // MAINWINDOW_H