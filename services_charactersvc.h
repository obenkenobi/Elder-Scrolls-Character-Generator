#ifndef SERVICES_CHARACTERSVC_H
#define SERVICES_CHARACTERSVC_H

#include "domain_escharsheet.h"

#include <QObject>
#include <QSharedDataPointer>
#include "types.h"

namespace Services {
class ESCharacterSvcData;

class ESCharacterSvc : public QObject
{
    Q_OBJECT
public:
    explicit ESCharacterSvc(QObject *parent = nullptr);
    ESCharacterSvc(const ESCharacterSvc &);
    ESCharacterSvc &operator=(const ESCharacterSvc &);
    ~ESCharacterSvc();

public slots:
    void onReqGenCharacter();
    void onRequestCopyCharacterToClipboard();

signals:
    void characterGeneratedSignal(Types::WeakPtr<Domain::ESCharSheet> weakRef);

private:
    QSharedDataPointer<ESCharacterSvcData> data;
};
} // namespace Services

#endif // SERVICES_CHARACTERSVC_H
