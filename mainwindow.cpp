#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "character_gen.h"

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

void MainWindow::on_generateCharacterButton_clicked()
{
    const Aliases::String text = CharGen::generateCharacterText();
    ui->characterSheetTextBrowser->setText(text);
}

