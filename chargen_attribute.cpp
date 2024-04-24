#ifndef ATTRIBUTE_CPP
#define ATTRIBUTE_CPP

#include "chargen_attribute.h"

CharGen::Attribute::Attribute(const Types::String &label,
                              const Types::String &displayName)
    : label_(label)
    , displayName_(displayName)
{}

CharGen::Attribute::Attribute(const CharGen::Attribute &attr)
    : label_(attr.label_)
    , displayName_(attr.displayName_)
{}

CharGen::Attribute::Attribute()
    : label_("NULL")
    , displayName_("NULL")
{}

Types::String CharGen::Attribute::getDisplayName() const
{
    return displayName_;
}

Types::String CharGen::Attribute::getLabel() const
{
    return label_;
}

#endif // ATTRIBUTE_CPP
