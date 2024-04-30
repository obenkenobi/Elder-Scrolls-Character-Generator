#ifndef ATTRIBUTE_CPP
#define ATTRIBUTE_CPP

#include "domain_attribute.h"

Domain::Attribute::Attribute(Types::String label, Types::String displayName, Types::String description)
	: displayName_(std::move(displayName))
	  , description_(std::move(description)), label_(std::move(label))
{
}

Domain::Attribute::Attribute(Types::String label, Types::String displayName)
	: displayName_(std::move(displayName))
	  , description_(""), label_(std::move(label))
{
}

Domain::Attribute::Attribute(const Domain::Attribute& attr)
	: displayName_(attr.displayName_), description_(attr.description_),
	  label_(attr.label_)
{
}

Domain::Attribute::Attribute()
	: displayName_("NULL")
	  , label_("NULL")
{
}

bool Domain::Attribute::hasDescription() const
{
	return !description_.isEmpty();
}

Types::String Domain::Attribute::getDisplayName() const
{
	return displayName_;
}

Types::String Domain::Attribute::getDescription() const
{
	return description_.isEmpty() ? "N/A" : description_;
}

Types::String Domain::Attribute::getLabel() const
{
	return label_;
}

#endif // ATTRIBUTE_CPP
