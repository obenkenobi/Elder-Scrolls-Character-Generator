#include "services_charactersvc.h"

#include <QApplication>
#include <QClipboard>
#include "domain_skyrim_character_rolls.h"
#include "types.h"

class Services::EsCharacterSvcData : public QSharedData
{
public:
    EsCharacterSvcData()
        : sheet_(Types::SharedPtr<Domain::EsCharSheet>(new Domain::EsCharSheet())){};

public:
    Types::WeakPtr<Domain::EsCharSheet> charSheetWeakRef() { return sheet_; };
    Types::SharedPtr<Domain::EsCharSheet> charSheetStrongRef() { return sheet_; };

private:
    Types::SharedPtr<Domain::EsCharSheet> sheet_;
};

Services::EsCharacterSvc::EsCharacterSvc(QObject *parent)
    : QObject{parent}
    , data_(new EsCharacterSvcData)
{}

Services::EsCharacterSvc::EsCharacterSvc(const Services::EsCharacterSvc &rhs)
    : data_{rhs.data_}
{}

Services::EsCharacterSvc &Services::EsCharacterSvc::operator=(const Services::EsCharacterSvc &rhs)
{
    if (this != &rhs)
        data_.operator=(rhs.data_);
    return *this;
}

Services::EsCharacterSvc::~EsCharacterSvc() = default;

void Services::EsCharacterSvc::onReqGenCharacter()
{
	const Types::WeakPtr<Domain::EsCharSheet> weakRef = this->data_->charSheetWeakRef();
    Domain::rollForEsCharSheet(weakRef);
    emit characterGeneratedSignal(weakRef);
}

void Services::EsCharacterSvc::onRequestCopyCharacterToClipboard()
{
	const Types::SharedPtr<Domain::EsCharSheet> sheet = this->data_->charSheetStrongRef();

    if (sheet.isNull()) {
        return;
    }

	const Types::String text = sheet->toClipboardString();

    QClipboard *clipboard = QApplication::clipboard();

    clipboard->setText(text, QClipboard::Clipboard);

    if (clipboard->supportsSelection()) {
        clipboard->setText(text, QClipboard::Selection);
    }
}
