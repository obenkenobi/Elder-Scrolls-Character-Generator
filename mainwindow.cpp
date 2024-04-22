#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "character_generator.h"

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
    const type_aliases::string_t text = char_gen::generate_character_text();
    ui->characterSheetTextBrowser->setText(text);
}

