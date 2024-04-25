#ifndef DOMAIN_ATTRIBUTE_H
#define DOMAIN_ATTRIBUTE_H

#include "domain_roll.h"
#include "types.h"

namespace Domain {

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
Attribute createAttribute(const RollItem<Tid> &item)
{
    return Attribute(item.getLabel(), item.getDisplayName());
}

} // namespace Domain

#endif // DOMAIN_ATTRIBUTE_H
