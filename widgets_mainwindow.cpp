#include "widgets_mainwindow.h"
#include <QClipboard>
#include "./ui_widgets_mainwindow.h"
#include "types.h"

class MainWindowData : public QSharedData
{
public:
    MainWindowData()
        : charAttrLabelFont_(Types::SharedPtr<QFont>(new QFont))
        , charAtteDisplayTextFont_(Types::SharedPtr<QFont>(new QFont))
    {
        charAttrLabelFont_->setBold(true);
        charAttrLabelFont_->setPixelSize(20);

        charAtteDisplayTextFont_->setBold(false);
        charAtteDisplayTextFont_->setPixelSize(15);
    }

    Types::SharedPtr<QFont> charAttrLabelFont() const { return charAttrLabelFont_; }

    Types::SharedPtr<QFont> charAtteDisplayTextFont() const { return charAtteDisplayTextFont_; }

private:
    Types::SharedPtr<QFont> charAttrLabelFont_;
    Types::SharedPtr<QFont> charAtteDisplayTextFont_;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , data(new MainWindowData())
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

void MainWindow::onCharacterGenerated(Types::WeakPtr<Domain::ESCharSheet> sheetPtr)
{
    Types::SharedPtr<Domain::ESCharSheet> sheet = sheetPtr.lock();
    if (sheet.isNull()) {
        return;
    }

    auto characterTable = ui->characterTable;

    characterTable->clear();

    characterTable->setRowCount(sheet->attributeCount());

    static const QFont labelFont = *(this->data->charAttrLabelFont());
    static const QFont displayFont = *(this->data->charAtteDisplayTextFont());

    Types::Size rowNumber = 0;
    for (auto attrPtr = sheet->begin(); attrPtr != sheet->end(); attrPtr++) {
        auto *labelItem = new QTableWidgetItem(attrPtr->getLabel());
        labelItem->setFont(labelFont);

        auto *displayItem = new QTableWidgetItem(attrPtr->getDisplayName());
        displayItem->setFont(displayFont);

        characterTable->setItem(rowNumber, 0, labelItem);
        characterTable->setItem(rowNumber, 1, displayItem);
        rowNumber++;
    }
}

void MainWindow::on_generateCharacterButton_clicked()
{
    emit this->reqGenCharacterSignal();
}

void MainWindow::on_copyButton_clicked()
{
    emit reqCopyCharacterToClipboardSignal();
}
