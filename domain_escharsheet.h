#ifndef DOMAIN_ESCHARSHEET_H
// ReSharper disable once IdentifierTypo
#define DOMAIN_ESCHARSHEET_H

#include "domain_attribute.h"

namespace Domain {

// Character sheet containing attributes that you can iterate over
class EsCharSheet
{
private:
    using AttrVector = Types::Vector<Attribute>;
    AttrVector attrVector_;

public:
    using Iterator = AttrVector::Iterator;

    EsCharSheet();

    void clear();

    Iterator begin();

    Iterator end();

    void insertAttribute(const Attribute attr);

    [[nodiscard]] Types::Size attributeCount() const;

    Types::String toLoggingString();

    Types::String toClipboardString();
};
} // namespace Domain

// ReSharper disable once CommentTypo
#endif // DOMAIN_ESCHARSHEET_H
