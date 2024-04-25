#ifndef DOMAIN_ESCHARSHEET_H
#define DOMAIN_ESCHARSHEET_H

#include "domain_attribute.h"

namespace Domain {

// Character sheet containing attributes that you can iterate over
class ESCharSheet
{
private:
    using AttrVector = Types::Vector<Attribute>;
    AttrVector attrVector_;

public:
    using Iterator = AttrVector::Iterator;

    ESCharSheet();

    void clear();

    Iterator begin();

    Iterator end();

    void insertAttribute(const Attribute attr);

    Types::Size attributeCount() const;

    Types::String toLoggableString();

    Types::String toClipboardString();
};
} // namespace Domain

#endif // DOMAIN_ESCHARSHEET_H
