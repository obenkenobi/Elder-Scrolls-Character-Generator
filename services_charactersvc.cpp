#include "services_charactersvc.h"

#include <QApplication>
#include <QClipboard>
#include "chargen_rolls.h"
#include "types.h"

class Services::CharacterSvcData : public QSharedData
{
public:
    CharacterSvcData()
        : sheet_(Types::SharedPtr<CharGen::CharacterSheet>(new CharGen::CharacterSheet())){};

public:
    Types::WeakPtr<CharGen::CharacterSheet> charSheetWeakRef() { return sheet_; };
    Types::SharedPtr<CharGen::CharacterSheet> charSheetStrongRef() { return sheet_; };

private:
    Types::SharedPtr<CharGen::CharacterSheet> sheet_;
};

Services::CharacterSvc::CharacterSvc(QObject *parent)
    : QObject{parent}
    , data(new CharacterSvcData)
{}

Services::CharacterSvc::CharacterSvc(const Services::CharacterSvc &rhs)
    : data{rhs.data}
{}

Services::CharacterSvc &Services::CharacterSvc::operator=(const Services::CharacterSvc &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Services::CharacterSvc::~CharacterSvc() {}

void Services::CharacterSvc::onReqGenCharacter()
{
    Types::WeakPtr<CharGen::CharacterSheet> weakRef = this->data->charSheetWeakRef();
    CharGen::rollForCharacterSheet(weakRef);
    emit characterGeneratedSignal(weakRef);
}

void Services::CharacterSvc::onRequestCopyCharacterToClipboard()
{
    Types::SharedPtr<CharGen::CharacterSheet> sheet = this->data->charSheetStrongRef();

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
