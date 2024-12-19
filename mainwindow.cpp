#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, SIGNAL(counterChanged()), this, SLOT(updateCounterFields()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCount_clicked()
{
    counter++;
    // Text values could be changed here, but I wanted to exercise singals and slots.
    emit counterChanged();
}


void MainWindow::on_btnReset_clicked()
{
    counter = 0;
    // likewise here
    emit counterChanged();
}

// Responsibility of updating counter related fields moved to dedicated function.
void MainWindow::updateCounterFields() {
    ui->labelInfo->setText("Button has been pressed " + QString::number(counter) + " times.");
    ui->txtResult->setText(QString::number(counter));
}
