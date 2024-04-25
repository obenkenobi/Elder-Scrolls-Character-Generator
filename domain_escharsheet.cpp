#include "domain_escharsheet.h"

Domain::ESCharSheet::ESCharSheet()
    : attrVector_(AttrVector())
{}

void Domain::ESCharSheet::clear()
{
    attrVector_.clear();
}

Domain::ESCharSheet::Iterator Domain::ESCharSheet::begin()
{
    return attrVector_.begin();
}

Domain::ESCharSheet::Iterator Domain::ESCharSheet::end()
{
    return attrVector_.end();
}

void Domain::ESCharSheet::insertAttribute(const Domain::Attribute attr)
{
    this->attrVector_.push_back(attr);
}

Types::Size Domain::ESCharSheet::attributeCount() const
{
    return this->attrVector_.size();
}

Types::String Domain::ESCharSheet::toLoggableString()
{
    Types::String character_text = "CharacterSheet Attributes={";

    for (auto attrPtr = this->attrVector_.begin(); attrPtr != this->attrVector_.end(); attrPtr++) {
        if (attrPtr != this->attrVector_.begin()) {
            character_text += ", ";
        }
        character_text += Types::String("%1=[%2]").arg(attrPtr->getLabel(),
                                                       attrPtr->getDisplayName());
    }
    character_text += "}";

    return character_text;
}

Types::String Domain::ESCharSheet::toClipboardString()
{
    Types::String character_text = "Character Sheet\n\n";

    for (auto attrPtr = this->attrVector_.begin(); attrPtr != this->attrVector_.end(); attrPtr++) {
        character_text += Types::String("%1:\t%2\n")
                              .arg(attrPtr->getLabel(), attrPtr->getDisplayName());
    }

    return character_text;
}
