#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lib.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//VLAIDATION
void MainWindow::emptyInput() {
    bool excep = false;
    string dateInput1 = ui->inputDate->text().toStdString();
    string dateInput2 = ui->inputDate_3->text().toStdString();

    if(dateInput1.empty()) {
        excep = true;
        ui->inputDate->setStyleSheet("border: 2px solid red;");
    }
    if(dateInput2.empty()) {
        excep = true;
        ui->inputDate_3->setStyleSheet("border: 2px solid red;");
    }

    if(excep) {
        throw QString("Please, fill in all inputs!");
    }
}
void MainWindow::checkFormat() {
    ui->inputDate->setStyleSheet("border: 1px solid black;");
    ui->inputDate_3->setStyleSheet("border: 1px solid black;");
    bool excep = false;
    string dateInput1 = ui->inputDate->text().toStdString();
    string dateInput2 = ui->inputDate_3->text().toStdString();

    if (!isValidFormat(dateInput1)) {
        excep = true;
        ui->inputDate->setStyleSheet("border: 2px solid red;");
    }
    if (!isValidFormat(dateInput2)) {
        excep = true;
        ui->inputDate_3->setStyleSheet("border: 2px solid red;");
    }

    if (excep) {
        throw QString("Please, enter date in the correct format (dd.mm.yyyy)");
    }
}
void MainWindow::checkDate() {
    ui->inputDate->setStyleSheet("border: 1px solid black;");
    ui->inputDate_3->setStyleSheet("border: 1px solid black;");
    bool excep = false;
    string dateInput1 = ui->inputDate->text().toStdString();
    string dateInput2 = ui->inputDate_3->text().toStdString();

    if (!isDateCorrect(dateInput1)) {
        excep = true;
        ui->inputDate->setStyleSheet("border: 2px solid red;");
    }
    if (!isDateCorrect(dateInput2)) {
        excep = true;
        ui->inputDate_3->setStyleSheet("border: 2px solid red;");
    }

    if (excep) {
        throw QString("The date you entered does not exist.");
    }
}


void MainWindow::on_pushButton_clicked()
{
    try {
        emptyInput();
        checkFormat();
        checkDate();
        string dateInput1 = ui->inputDate->text().toStdString();
        string dateInput2 = ui->inputDate_3->text().toStdString();
        string result1 = convert(dateInput1);
        string result2 = convert(dateInput2);

        if (compare(result1, result2)) {
            ui->inputDate_5->setText(QString::fromStdString("Same days of week!"));
        } else {
            ui->inputDate_5->setText(QString::fromStdString("Days of week are different!"));
        }

        ui->inputDate_2->setText(QString::fromStdString(result1));
        ui->inputDate_4->setText(QString::fromStdString(result2));
    } catch (const QString& exception) {
        QMessageBox::critical(nullptr, "Error", exception);
    }
}

