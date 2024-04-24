#ifndef CHARGEN_CHARACTERSHEET_H
#define CHARGEN_CHARACTERSHEET_H

#include "chargen_attribute.h"

namespace CharGen {

class CharacterSheet
{
private:
    using AttrVector = Types::Vector<Attribute>;
    AttrVector attrVector_;

public:
    using Iterator = AttrVector::Iterator;

    CharacterSheet();

    void clear();

    Iterator begin();

    Iterator end();

    void insertAttribute(const Attribute attr);

    Types::Size attributeCount() const;

    Types::String toLoggableString();

    Types::String toClipboardString();
};
} // namespace CharGen

#endif // CHARGEN_CHARACTERSHEET_H
