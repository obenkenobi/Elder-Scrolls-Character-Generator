#ifndef CHARGEN_ATTRIBUTE_H
#define CHARGEN_ATTRIBUTE_H

#include "roll.h"
#include "types.h"

namespace CharGen {

class Attribute
{
public:
    Attribute(const Types::String &label, const Types::String &displayName);

    Attribute(const Attribute &attr);

    Attribute();

    Types::String getDisplayName() const;
    Types::String getLabel() const;

protected:
private:
    Types::String displayName_;
    Types::String label_;
};

template<class Tid>
Attribute createAttribute(const Roll::RollItem<Tid> &item)
{
    return Attribute(item.getLabel(), item.getDisplayName());
}

} // namespace CharGen

#endif // CHARGEN_ATTRIBUTE_H
