#ifndef DOMAIN_ATTRIBUTE_H
#define DOMAIN_ATTRIBUTE_H

#include "domain_roll.h"
#include "types.h"

namespace Domain {

class Attribute
{
public:
    Attribute(Types::String label, Types::String displayName);

    Attribute(const Attribute &attr);

    Attribute();

    [[nodiscard]] Types::String getDisplayName() const;
    [[nodiscard]] Types::String getLabel() const;

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
