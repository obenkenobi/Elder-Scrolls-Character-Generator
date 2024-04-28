#ifndef ATTRIBUTE_CPP
#define ATTRIBUTE_CPP

#include "domain_attribute.h"

Domain::Attribute::Attribute(Types::String label, Types::String displayName)
    : displayName_(std::move(displayName))
    , label_(std::move(label))
{}

Domain::Attribute::Attribute(const Domain::Attribute &attr)
    : displayName_(attr.displayName_)
    , label_(attr.label_)
{}

Domain::Attribute::Attribute()
    : displayName_("NULL")
    , label_("NULL")
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
