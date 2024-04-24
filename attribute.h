#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "roll.h"
#include "types.h"

namespace CharGen {

class Attribute
{
public:
    Attribute(const Types::String &label, const Types::Uint8 &id, const Types::String &displayName);

    Attribute(const Attribute &attr);

    Attribute();

    Types::String getDisplayName() const;
    Types::Uint8 getId() const;
    Types::String getLabel() const;

protected:
private:
    Types::String displayName_;
    Types::Uint8 id_;
    Types::String label_;
};

template<class Tid>
Attribute createAttribute(const Roll::RollItem<Tid> &item)
{
    return Attribute(item.getLabel(),
                     static_cast<Types::Uint8>(item.getId()),
                     item.getDisplayName());
}
} // namespace CharGen

#endif // ATTRIBUTE_H
