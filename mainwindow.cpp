#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "character_gen.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Elder Scrolls Character Generator");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateCharacterButton_clicked()
{
    const Aliases::String text = CharGen::generateCharacterSheet().toText();
    ui->characterSheetTextBrowser->setText(text);
}

