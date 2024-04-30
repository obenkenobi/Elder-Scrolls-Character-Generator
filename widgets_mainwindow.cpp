#include "widgets_mainwindow.h"
#include <QClipboard>
#include "./ui_widgets_mainwindow.h"
#include "types.h"

class MainWindowData : public QSharedData
{
private:
	using FontPtr = Types::SharedPtr<QFont>;

public:
	MainWindowData()
		: charAttrLabelFont_(FontPtr(new QFont)),
		  charAtteDisplayTextFont_(FontPtr(new QFont)),
		  headingFont_(FontPtr(new QFont))
	{
		charAttrLabelFont_->setBold(true);
		charAttrLabelFont_->setPixelSize(15);

		charAtteDisplayTextFont_->setBold(false);
		charAtteDisplayTextFont_->setPixelSize(15);

		headingFont_->setBold(true);
		headingFont_->setPixelSize(20);
	}

	QFont& charAttrLabelFont() const { return *charAttrLabelFont_; }

	QFont& charAtteDisplayTextFont() const { return *charAtteDisplayTextFont_; }

	QFont& getHeadingFont() const { return *headingFont_; }

private:
	FontPtr charAttrLabelFont_;
	FontPtr charAtteDisplayTextFont_;
	FontPtr headingFont_;
};

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	  , ui_(new Ui::MainWindow)
	  , data_(new MainWindowData())
{
	ui_->setupUi(this);
	this->setWindowTitle("Elder Scrolls Character Generator");

	const auto characterTable = ui_->characterTable;
	characterTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	characterTable->setColumnCount(3);
}

MainWindow::~MainWindow()
{
	delete ui_;
}

void MainWindow::onCharacterGenerated(Types::WeakPtr<Domain::EsCharSheet> sheetPtr)
{
	const Types::SharedPtr<Domain::EsCharSheet> sheet = sheetPtr.lock();
	if (sheet.isNull())
	{
		return;
	}

	const auto characterTable = ui_->characterTable;

	characterTable->clear();

	characterTable->setRowCount(static_cast<int>(1 + sheet->attributeCount()));

	{
		static const QFont& headingFont = this->data_->getHeadingFont();

		auto* labelHeadingItem = new QTableWidgetItem("Label");
		auto* displayHeadingItem = new QTableWidgetItem("Name");
		auto* descriptionHeadingItem = new QTableWidgetItem("Description");


		labelHeadingItem->setFont(headingFont);
		displayHeadingItem->setFont(headingFont);
		descriptionHeadingItem->setFont(headingFont);


		characterTable->setItem(0, 0, labelHeadingItem);
		characterTable->setItem(0, 1, displayHeadingItem);
		characterTable->setItem(0, 2, descriptionHeadingItem);
	}

	static const QFont& labelFont = this->data_->charAttrLabelFont();
	static const QFont& displayFont = this->data_->charAtteDisplayTextFont();

	int rowNumber = 1;
	for (auto& attrPtr : *sheet)
	{
		auto* labelItem = new QTableWidgetItem(attrPtr.getLabel());
		auto* displayItem = new QTableWidgetItem(attrPtr.getDisplayName());
		auto* descriptionItem = new QTableWidgetItem(attrPtr.getDescription());

		labelItem->setFont(labelFont);
		displayItem->setFont(displayFont);

		characterTable->setItem(rowNumber, 0, labelItem);
		characterTable->setItem(rowNumber, 1, displayItem);
		characterTable->setItem(rowNumber, 2, descriptionItem);

		rowNumber++;
	}
}

// ReSharper disable once CppInconsistentNaming
void MainWindow::on_generateCharacterButton_clicked()
{
	emit this->reqGenCharacterSignal();
}

// ReSharper disable once CppInconsistentNaming
void MainWindow::on_copyButton_clicked()
{
	emit reqCopyCharacterToClipboardSignal();
}
