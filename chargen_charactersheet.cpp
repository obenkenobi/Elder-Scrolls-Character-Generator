#include "chargen_charactersheet.h"

CharGen::CharacterSheet::CharacterSheet()
    : attrVector_(AttrVector())
{}

void CharGen::CharacterSheet::clear()
{
    attrVector_.clear();
}

CharGen::CharacterSheet::Iterator CharGen::CharacterSheet::begin()
{
    return attrVector_.begin();
}

CharGen::CharacterSheet::Iterator CharGen::CharacterSheet::end()
{
    return attrVector_.end();
}

void CharGen::CharacterSheet::insertAttribute(const CharGen::Attribute attr)
{
    this->attrVector_.push_back(attr);
}

Types::Size CharGen::CharacterSheet::attributeCount() const
{
    return this->attrVector_.size();
}

Types::String CharGen::CharacterSheet::toLoggableString()
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

Types::String CharGen::CharacterSheet::toClipboardString()
{
    Types::String character_text = "Character Sheet\n\n";

    for (auto attrPtr = this->attrVector_.begin(); attrPtr != this->attrVector_.end(); attrPtr++) {
        character_text += Types::String("%1:\t%2\n")
                              .arg(attrPtr->getLabel(), attrPtr->getDisplayName());
    }

    return character_text;
}
