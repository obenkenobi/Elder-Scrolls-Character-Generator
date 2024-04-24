#include "mainwindow.h"
#include <QClipboard>
#include "./ui_mainwindow.h"
#include "character_gen.h"
// #include "logging.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Elder Scrolls Character Generator");

    auto characterTable = ui->characterTable;
    characterTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    characterTable->setColumnCount(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

namespace MainWindowHelpers {
QFont buildFont(bool isBold, int pixelSize)
{
    auto font = QFont();
    font.setBold(isBold);
    font.setPixelSize(pixelSize);
    return font;
}
} // namespace MainWindowHelpers

void MainWindow::on_generateCharacterButton_clicked()
{
    CharGen::CharacterSheet sheet = CharGen::generateCharacterSheet();

    auto characterTable = ui->characterTable;

    characterTable->clear();

    characterTable->setRowCount(sheet.attributeCount());

    static const QFont labelFont = MainWindowHelpers::buildFont(true, 20);
    static const QFont displayFont = MainWindowHelpers::buildFont(false, 15);

    Types::Size rowNumber = 0;
    for (auto attrPtr = sheet.begin(); attrPtr != sheet.end(); attrPtr++) {
        auto *labelItem = new QTableWidgetItem(attrPtr->getLabel());
        labelItem->setFont(labelFont);

        auto *displayItem = new QTableWidgetItem(attrPtr->getDisplayName());
        displayItem->setFont(displayFont);

        characterTable->setItem(rowNumber, 0, labelItem);
        characterTable->setItem(rowNumber, 1, displayItem);
        rowNumber++;
    }
}

void MainWindow::on_copyButton_clicked()
{
    auto characterTable = ui->characterTable;
    int rowCount = characterTable->rowCount();

    Types::String tableText = "";
    for (int rowNum = 0; rowNum < rowCount; rowNum++) {
        auto labelItem = characterTable->item(rowNum, 0);
        auto displayItem = characterTable->item(rowNum, 1);
        tableText += labelItem->text();
        tableText += " : ";
        tableText += displayItem->text();
        tableText += "\n";
    }
    QClipboard *clipboard = QApplication::clipboard();

    clipboard->setText(tableText, QClipboard::Clipboard);

    if (clipboard->supportsSelection()) {
        clipboard->setText(tableText, QClipboard::Selection);
    }
}
