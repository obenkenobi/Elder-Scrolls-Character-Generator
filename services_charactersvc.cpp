#include "services_charactersvc.h"

#include <QApplication>
#include <QClipboard>
#include "domain_skyrim_character_rolls.h"
#include "types.h"

class Services::ESCharacterSvcData : public QSharedData
{
public:
    ESCharacterSvcData()
        : sheet_(Types::SharedPtr<Domain::ESCharSheet>(new Domain::ESCharSheet())){};

public:
    Types::WeakPtr<Domain::ESCharSheet> charSheetWeakRef() { return sheet_; };
    Types::SharedPtr<Domain::ESCharSheet> charSheetStrongRef() { return sheet_; };

private:
    Types::SharedPtr<Domain::ESCharSheet> sheet_;
};

Services::ESCharacterSvc::ESCharacterSvc(QObject *parent)
    : QObject{parent}
    , data(new ESCharacterSvcData)
{}

Services::ESCharacterSvc::ESCharacterSvc(const Services::ESCharacterSvc &rhs)
    : data{rhs.data}
{}

Services::ESCharacterSvc &Services::ESCharacterSvc::operator=(const Services::ESCharacterSvc &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Services::ESCharacterSvc::~ESCharacterSvc() {}

void Services::ESCharacterSvc::onReqGenCharacter()
{
    Types::WeakPtr<Domain::ESCharSheet> weakRef = this->data->charSheetWeakRef();
    Domain::rollForESCharSheet(weakRef);
    emit characterGeneratedSignal(weakRef);
}

void Services::ESCharacterSvc::onRequestCopyCharacterToClipboard()
{
    Types::SharedPtr<Domain::ESCharSheet> sheet = this->data->charSheetStrongRef();

    if (sheet.isNull()) {
        return;
    }

    Types::String text = sheet->toClipboardString();

    QClipboard *clipboard = QApplication::clipboard();

    clipboard->setText(text, QClipboard::Clipboard);

    if (clipboard->supportsSelection()) {
        clipboard->setText(text, QClipboard::Selection);
    }
}
