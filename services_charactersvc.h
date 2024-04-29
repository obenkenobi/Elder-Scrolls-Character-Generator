#ifndef SERVICES_CHARACTERSVC_H
#define SERVICES_CHARACTERSVC_H

#include "domain_escharsheet.h"

#include <QObject>
#include <QSharedDataPointer>
#include "types.h"

namespace Services
{
	class EsCharacterSvcData;

	class EsCharacterSvc final : public QObject
	{
		Q_OBJECT

	public:
		explicit EsCharacterSvc(QObject* parent = nullptr);
		EsCharacterSvc(const EsCharacterSvc&);
		EsCharacterSvc& operator=(const EsCharacterSvc&);
		~EsCharacterSvc() override;

	public slots:
		void onReqGenCharacter();
		void onRequestCopyCharacterToClipboard();

	signals:
		void characterGeneratedSignal(Types::WeakPtr<Domain::EsCharSheet> weakRef);

	private:
		QSharedDataPointer<EsCharacterSvcData> data_;
	};
} // namespace Services

#endif // SERVICES_CHARACTERSVC_H
