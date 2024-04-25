#ifndef ATTRIBUTE_CPP
#define ATTRIBUTE_CPP

#include "domain_attribute.h"

Domain::Attribute::Attribute(const Types::String &label, const Types::String &displayName)
    : label_(label)
    , displayName_(displayName)
{}

Domain::Attribute::Attribute(const Domain::Attribute &attr)
    : label_(attr.label_)
    , displayName_(attr.displayName_)
{}

Domain::Attribute::Attribute()
    : label_("NULL")
    , displayName_("NULL")
{}

Types::String Domain::Attribute::getDisplayName() const
{
    return displayName_;
}

Types::String Domain::Attribute::getLabel() const
{
    return label_;
}

#endif // ATTRIBUTE_CPP
