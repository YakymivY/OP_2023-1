#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <math.h>
#include <sstream>
#include <QApplication>
#include <QMessageBox>
#include <QtWidgets>
#include <QtCore>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    // VALIDATION
    void emptyInput();
    void checkFormat();
    void checkDate();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
