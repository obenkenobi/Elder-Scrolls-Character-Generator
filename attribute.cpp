#ifndef ATTRIBUTE_CPP
#define ATTRIBUTE_CPP

#include "attribute.h"

CharGen::Attribute::Attribute(const Types::String &label,
                              const Types::Uint8 &id,
                              const Types::String &displayName)
    : label_(label)
    , id_(id)
    , displayName_(displayName)
{}

CharGen::Attribute::Attribute(const CharGen::Attribute &attr)
    : label_(attr.label_)
    , id_(attr.id_)
    , displayName_(attr.displayName_)
{}

CharGen::Attribute::Attribute()
    : label_("NULL")
    , id_(0)
    , displayName_("NULL")
{}

Types::String CharGen::Attribute::getDisplayName() const
{
    return displayName_;
}

Types::Uint8 CharGen::Attribute::getId() const
{
    return id_;
}

Types::String CharGen::Attribute::getLabel() const
{
    return label_;
}

#endif // ATTRIBUTE_CPP
