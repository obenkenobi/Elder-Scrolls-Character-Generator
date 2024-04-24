#ifndef CHARACTER_GEN_H
#define CHARACTER_GEN_H

#include "aliases.h"
#include "roll.h"

namespace CharGen {
// Archetype
// -----------------------------------------------------------------------------

enum ArchetypeId { a_mage, a_thief, a_warrior, a_any };

class Archetype : public Roll::RollItem<ArchetypeId>
{
private:
    static inline const Aliases::String LABEL_ = "Archetype";

public:
    using Roll::RollItem<ArchetypeId>::RollItem;

    Aliases::String getLabel() const;
};

Archetype createArchetype(const ArchetypeId id);

using ArchetypeRollList = Roll::RollList<Archetype>;
using ArchetypeRollMatcher = Roll::RollMatcher<Archetype>;
using MageRange = Roll::Range;
using WarriorRange = Roll::Range;
using ThiefRange = Roll::Range;

ArchetypeRollList createArchetypeRollList(const MageRange mageRange,
                                          const WarriorRange warriorRange,
                                          const ThiefRange thiefRange);

//  RPG Class
//  ------------------------------------------------------------------------------

enum RpgClassId {
    c_archer,
    c_barbarian,
    c_crusader,
    c_knight,
    c_rogue,
    c_scout,
    c_warrior,
    c_acrobat,
    c_agent,
    c_assassin,
    c_bard,
    c_monk,
    c_pilgrim,
    c_thief,
    c_battle_mage,
    c_healer,
    c_mage,
    c_night_blade,
    c_sorcerer,
    c_spell_sword,
    c_witch_hunter
};

class RpgClass : public Roll::RollItem<RpgClassId>
{
private:
    static inline const Aliases::String LABEL_ = "Class";

public:
    using Roll::RollItem<RpgClassId>::RollItem;

    Aliases::String getLabel() const;
};

using RpgClassRollList = Roll::RollList<RpgClass>;
using RpgClassRollMatcher = Roll::RollMatcher<RpgClass>;

const RpgClassRollList &getWarriorClassRollList();

const RpgClassRollList &getThiefClassRollList();

const RpgClassRollList &getMageClassRollList();

const RpgClassRollList &createRpgClassRollList(const ArchetypeId archetypeId);

// Birth Signs
// ------------------------------------------------------------------------------------------------------------

enum BirthSignId {
    b_ritual,
    b_lover,
    b_lord,
    b_mage,
    b_shadow,
    b_steed,
    b_apprentice,
    b_warrior,
    b_lady,
    b_tower,
    b_atronach,
    b_thief,
    b_serpent
};

class BirthSign : public Roll::RollItem<BirthSignId>
{
public:
    BirthSign(const BirthSignId id,
              const ArchetypeId archetypeId,
              const Aliases::String &displayName);

    bool rollIfArchetypeBasedOnBirthSign() const;

    Aliases::String getLabel() const;

    ArchetypeId getArchetypeId() const;

private:
    static inline const Aliases::String LABEL_ = "Birthsign";
    ArchetypeId archetypeId_;
};

using BirthSignsRollList = Roll::RollList<BirthSign>;
using BirthSignsRollMatcher = Roll::RollMatcher<BirthSign>;

const BirthSignsRollList &getBirthSignsRollList();
;

// Sex
// ------------------------------------------------------------------------------------------------------------

// Unfortunately Elder Scrolls games do not have an
// intersex option nor a nonbinary option if you prefer
// to use gender.

enum SexId { male, female };

class Sex : public Roll::RollItem<SexId>
{
private:
    static inline const Aliases::String LABEL_ = "Sex";
    bool isTranssexual_;

public:
    Sex(SexId id, Aliases::String displayName, bool isTranssexual);

    Aliases::String getLabel() const;
    bool isTranssexual() const;
};

Sex rollForSex();

// Sexuality
// ------------------------------------------------------------------------------------------------------------

enum SexualityId { heterosexual, bisexual, homosexual };

class Sexuality : public Roll::RollItem<SexualityId>
{
private:
    static inline const Aliases::String LABEL_ = "Sexuality";

public:
    using Roll::RollItem<SexualityId>::RollItem;
    Aliases::String getLabel() const;
};

using SexualitiesRollList = Roll::RollList<Sexuality>;
using SexualitiesRollMatcher = Roll::RollMatcher<Sexuality>;

const SexualitiesRollList &createSexualitiesRollList(const SexId sexId);

// Skin Color
// ------------------------------------------------------------------------------------------------------------------

enum SkinColorId {
    sc_nil,
    sc_pale,
    sc_fair,
    sc_tan,
    sc_dark,
    sc_golden,
    sc_ashen_grey,
    sc_dark_grey,
    sc_near_black,
    sc_brown,
    sc_olive,
    sc_dark_green
};

class SkinColor : public Roll::RollItem<SkinColorId>
{
private:
    static inline const Aliases::String LABEL_ = "Skin Color";

public:
    using Roll::RollItem<SkinColorId>::RollItem;

    Aliases::String getLabel() const;
};

using SkinColorRollList = Roll::RollList<SkinColor>;
using SkinColorMatcher = Roll::RollMatcher<SkinColor>;

SkinColorMatcher createSkinColorMatcher(const Roll::Range range, const SkinColorId &skinColorId);

// Hair Color
// ------------------------------------------------------------------------------------------------------------------

enum HairColorId {
    hc_nil,
    hc_blonde,
    hc_brown,
    hc_red,
    hc_black,
    hc_dark_red,
    hc_grey,
    hc_golden_blonde,
    hc_silver_white,
    hc_light_brown,
    hc_green,
    hc_dark_brown,
    hc_white,
    hc_orange
};

class HairColor : public Roll::RollItem<HairColorId>
{
private:
    static inline const Aliases::String LABEL_ = "Hair Color";

public:
    using Roll::RollItem<HairColorId>::RollItem;
    Aliases::String getLabel() const;
};

using HairColorRollList = Roll::RollList<HairColor>;
using HairColorMatcher = Roll::RollMatcher<HairColor>;

HairColorMatcher createHairColorMatcher(const Roll::Range range, const HairColorId id);

// Eye Color --------------------------------------------------------

enum EyeColorId {
    ec_nil,
    ec_blue,
    ec_green,
    ec_grey,
    ec_brown,
    ec_hazel,
    ec_black,
    ec_amber,
    ec_red,
    ec_orange,
    ec_gold,
    ec_yellow
};

class EyeColor : public Roll::RollItem<EyeColorId>
{
private:
    static inline const Aliases::String LABEL_ = "Eye Color";

public:
    using Roll::RollItem<EyeColorId>::RollItem;
    Aliases::String getLabel() const;
};

using EyeColorRollList = Roll::RollList<EyeColor>;
using EyeColorMatcher = Roll::RollMatcher<EyeColor>;

EyeColorMatcher createEyeColorMatcher(const Roll::Range range, const EyeColorId id);

// Fur Pattern --------------------------------------------------------

enum FurPatternId { fp_nil, fp_striped, fp_spotted, fp_solid, fp_tabby };

class FurPattern : public Roll::RollItem<FurPatternId>
{
private:
    static inline const Aliases::String LABEL_ = "Fur Pattern";

public:
    using Roll::RollItem<FurPatternId>::RollItem;
    Aliases::String getLabel() const;
};

using FurPatternRollList = Roll::RollList<FurPattern>;
using FurPatternMatcher = Roll::RollMatcher<FurPattern>;

FurPatternMatcher createFurPatternMatcher(const Roll::Range range, const FurPatternId id);

// Scale Color --------------------------------------------------------

enum ScaleColorId { scl_null, scl_dark_green, scl_olive, scl_brown, scl_grey };

class ScaleColor : public Roll::RollItem<ScaleColorId>
{
private:
    static inline const Aliases::String LABEL_ = "Scale Color";

public:
    using Roll::RollItem<ScaleColorId>::RollItem;
    Aliases::String getLabel() const;
};

using ScaleColorRollList = Roll::RollList<ScaleColor>;
using ScaleColorMatcher = Roll::RollMatcher<ScaleColor>;

ScaleColorMatcher createScaleColorMatcher(const Roll::Range range, const ScaleColorId id);

// Horn Type --------------------------------------------------------
enum HornTypeId { ht_null, ht_none, ht_spiked, ht_curved, ht_both };

class HornType : public Roll::RollItem<HornTypeId>
{
private:
    static inline const Aliases::String LABEL_ = "Horn Type";

public:
    using Roll::RollItem<HornTypeId>::RollItem;
    Aliases::String getLabel() const;
};

using HornTypeRollList = Roll::RollList<HornType>;
using HornTypeMatcher = Roll::RollMatcher<HornType>;

HornTypeMatcher createHornTypeMatcher(const Roll::Range range, const HornTypeId id);

// Race
// ------------------------------------------------------------------------------------------------------------------

enum RaceId {
    r_nord,
    r_imperial,
    r_breton,
    r_dunmer,
    r_altmer,
    r_orsimer,
    r_redguard,
    r_bosmer,
    r_khajiit,
    r_argonian
};

class Race : public Roll::RollItem<RaceId>
{
public:
    Race(const RaceId &id,
         const Aliases::String &displayName,
         ArchetypeRollList archetypeRollList,
         SkinColorRollList skinColorRollList,
         HairColorRollList hairColorRollList,
         EyeColorRollList eyeColorRollList,
         FurPatternRollList furPatternRollList,
         ScaleColorRollList scaleColorRollList,
         HornTypeRollList hornTypeRollList);

    Aliases::String getLabel() const;

    Archetype rollArchetype() const;

    SkinColor rollSkinColor() const;

    HairColor rollHairColor() const;

    EyeColor rollEyeColor() const;

    FurPattern rollFurPattern() const;

    ScaleColor rollScaleColor() const;

    HornType rollHornType() const;

private:
    ArchetypeRollList archetypeRollList_;
    SkinColorRollList skinColorRollList_;
    HairColorRollList hairColorRollList_;
    EyeColorRollList eyeColorRollList_;
    FurPatternRollList furPatternRollList_;
    ScaleColorRollList scaleColorRollList_;
    HornTypeRollList hornTypeRollList_;
    static inline const Aliases::String LABEL_ = "Race";
};

using RaceRollList = Roll::RollList<Race>;
using RaceRollMatcher = Roll::RollMatcher<Race>;

const RaceRollList &getRaceRollList();

class Attribute
{
public:
    Attribute(const Aliases::String &label,
              const Aliases::Uint8 &id,
              const Aliases::String &displayName);

    Attribute(const Attribute &attr);

    Attribute();

    Aliases::String getDisplayName() const;
    Aliases::Uint8 getId() const;
    Aliases::String getLabel() const;

protected:
private:
    Aliases::String displayName_;
    Aliases::Uint8 id_;
    Aliases::String label_;
};

template<class Tid>
Attribute createAttribute(const Roll::RollItem<Tid> &item)
{
    return Attribute(item.getLabel(),
                     static_cast<Aliases::Uint8>(item.getId()),
                     item.getDisplayName());
}

class CharacterSheet
{
private:
    using AttrVector = Aliases::Vector<Attribute>;
    AttrVector attrVector_;

public:
    using Iterator = AttrVector::Iterator;

    CharacterSheet();

    Iterator begin();

    Iterator end();

    void insertAttribute(const Attribute attr);

    Aliases::String toText();

};

CharacterSheet generateCharacterSheet();

} // namespace CharGen

#endif // CHARACTER_GEN_H
