#ifndef SERVICES_CHARACTERSVC_H
#define SERVICES_CHARACTERSVC_H

#include "chargen_charactersheet.h"

#include <QObject>
#include <QSharedDataPointer>
#include "types.h"

namespace Services {
class CharacterSvcData;

class CharacterSvc : public QObject
{
    Q_OBJECT
public:
    explicit CharacterSvc(QObject *parent = nullptr);
    CharacterSvc(const CharacterSvc &);
    CharacterSvc &operator=(const CharacterSvc &);
    ~CharacterSvc();

public slots:
    void onReqGenCharacter();
    void onRequestCopyCharacterToClipboard();

signals:
    void characterGeneratedSignal(Types::WeakPtr<CharGen::CharacterSheet> weakRef);

private:
    QSharedDataPointer<CharacterSvcData> data;
};
} // namespace Services

#endif // SERVICES_CHARACTERSVC_H
