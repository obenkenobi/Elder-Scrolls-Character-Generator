#include "domain_escharsheet.h"

Domain::EsCharSheet::EsCharSheet()
    : attrVector_(AttrVector())
{}

void Domain::EsCharSheet::clear()
{
    attrVector_.clear();
}

Domain::EsCharSheet::Iterator Domain::EsCharSheet::begin()
{
    return attrVector_.begin();
}

Domain::EsCharSheet::Iterator Domain::EsCharSheet::end()
{
    return attrVector_.end();
}

void Domain::EsCharSheet::insertAttribute(const Domain::Attribute attr)
{
    this->attrVector_.push_back(attr);
}

Types::Size Domain::EsCharSheet::attributeCount() const
{
    return this->attrVector_.size();
}

Types::String Domain::EsCharSheet::toLoggingString()
{
    Types::String characterText = "CharacterSheet Attributes={";

    for (auto attrPtr = this->attrVector_.begin(); attrPtr != this->attrVector_.end(); attrPtr++) {
        if (attrPtr != this->attrVector_.begin()) {
            characterText += ", ";
        }
        characterText += Types::String("%1=[%2]").arg(attrPtr->getLabel(),
                                                       attrPtr->getDisplayName());
    }
    characterText += "}";

    return characterText;
}

Types::String Domain::EsCharSheet::toClipboardString()
{
    Types::String characterText = "Character Sheet\n\n";

    for (auto& attrPtr : this->attrVector_)
    {
        characterText += Types::String("%1:\t%2\n")
                              .arg(attrPtr.getLabel(), attrPtr.getDisplayName());
    }

    return characterText;
}
