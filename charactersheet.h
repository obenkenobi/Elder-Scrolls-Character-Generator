#ifndef CHARACTERSHEET_H
#define CHARACTERSHEET_H

#include "attribute.h"

namespace CharGen {

class CharacterSheet
{
private:
    using AttrVector = Types::Vector<Attribute>;
    AttrVector attrVector_;

public:
    using Iterator = AttrVector::Iterator;

    CharacterSheet();

    Iterator begin();

    Iterator end();

    void insertAttribute(const Attribute attr);

    Types::Size attributeCount() const;

    Types::String toString();
};
} // namespace CharGen

#endif // CHARACTERSHEET_H
