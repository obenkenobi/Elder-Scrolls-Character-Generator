#ifndef CHARACTER_GEN_H
#define CHARACTER_GEN_H

#include "aliases.h"
#include "enum.h"
#include "roll.h"

namespace CharGen
{
// Archetype
// -----------------------------------------------------------------------------
ENUM(ArchetypeId, a_mage, a_thief, a_warrior, a_any);

using Archetype = Roll::RollItem<ArchetypeId>;

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

ENUM(RpgClassId,
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
     c_witch_hunter);

using RpgClass = Roll::RollItem<RpgClassId>;

using RpgClassRollList = Roll::RollList<RpgClass>;
using RpgClassRollMatcher = Roll::RollMatcher<RpgClass>;

const RpgClassRollList &getWarriorClassRollList();

const RpgClassRollList &getThiefClassRollList();

const RpgClassRollList &getMageClassRollList();

const RpgClassRollList &createRpgClassRollList(const ArchetypeId archetypeId);

// Birth Signs
// ------------------------------------------------------------------------------------------------------------
ENUM(BirthSignId,
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
     b_serpent);

class BirthSign : public Roll::RollItem<BirthSignId>
{
public:
    BirthSign(const BirthSignId id,
              const ArchetypeId archetypeId,
              const Aliases::String &displayName);

    bool rollIfArchetypeBasedOnBirthSign() const;

    ArchetypeId getArchetypeId() const { return archetypeId_; }

private:
    ArchetypeId archetypeId_;
};

using BirthSignsRollList = Roll::RollList<BirthSign>;
using BirthSignsRollMatcher = Roll::RollMatcher<BirthSign>;

const BirthSignsRollList &getBirthSignsRollList();
;

// Sex
// ------------------------------------------------------------------------------------------------------------

ENUM(SexId, male, female);

using Sex = Roll::RollItem<SexId>;

Sex rollForSex();

// Sexuality
// ------------------------------------------------------------------------------------------------------------
enum SexualityId { heterosexual, bisexual, homosexual };

using Sexuality = Roll::RollItem<SexualityId>;

using SexualitiesRollList = Roll::RollList<Sexuality>;
using SexualitiesRollMatcher = Roll::RollMatcher<Sexuality>;

const SexualitiesRollList &createSexualitiesRollList(const SexId sexId);

// Skin Color
// ------------------------------------------------------------------------------------------------------------------
ENUM(SkinColorId,
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
     sc_dark_green);

using SkinColor = Roll::RollItem<SkinColorId>;

using SkinColorRollList = Roll::RollList<SkinColor>;
using SkinColorMatcher = Roll::RollMatcher<SkinColor>;

SkinColorMatcher createSkinColorMatcher(const Roll::Range range, const SkinColorId &skinColorId);

// Hair Color
// ------------------------------------------------------------------------------------------------------------------
ENUM(HairColorId,
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
     hc_orange);

using HairColor = Roll::RollItem<HairColorId>;

using HairColorRollList = Roll::RollList<HairColor>;
using HairColorMatcher = Roll::RollMatcher<HairColor>;

HairColorMatcher createHairColorMatcher(const Roll::Range range, const HairColorId id);

// Eye Color --------------------------------------------------------
ENUM(EyeColorId,
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
     ec_yellow);

using EyeColor = Roll::RollItem<EyeColorId>;

using EyeColorRollList = Roll::RollList<EyeColor>;
using EyeColorMatcher = Roll::RollMatcher<EyeColor>;

EyeColorMatcher createEyeColorMatcher(const Roll::Range range, const EyeColorId id);

// Fur Pattern --------------------------------------------------------
ENUM(FurPatternId, fp_nil, fp_striped, fp_spotted, fp_solid, fp_tabby);

using FurPattern = Roll::RollItem<FurPatternId>;

using FurPatternRollList = Roll::RollList<FurPattern>;
using FurPatternMatcher = Roll::RollMatcher<FurPattern>;

FurPatternMatcher createFurPatternMatcher(const Roll::Range range, const FurPatternId id);

// Scale Color --------------------------------------------------------
ENUM(ScaleColorId, scl_null, scl_dark_green, scl_olive, scl_brown, scl_grey);

using ScaleColor = Roll::RollItem<ScaleColorId>;

using ScaleColorRollList = Roll::RollList<ScaleColor>;
using ScaleColorMatcher = Roll::RollMatcher<ScaleColor>;

ScaleColorMatcher createScaleColorMatcher(const Roll::Range range, const ScaleColorId id);

// Horn Type --------------------------------------------------------
ENUM(HornTypeId, ht_null, ht_none, ht_spiked, ht_curved, ht_both);

using HornType = Roll::RollItem<HornTypeId>;

using HornTypeRollList = Roll::RollList<HornType>;
using HornTypeMatcher = Roll::RollMatcher<HornType>;

HornTypeMatcher createHornTypeMatcher(const Roll::Range range, const HornTypeId id);

// Race
// ------------------------------------------------------------------------------------------------------------------
ENUM(RaceId,
     r_nord,
     r_imperial,
     r_breton,
     r_dunmer,
     r_altmer,
     r_orsimer,
     r_redguard,
     r_bosmer,
     r_khajiit,
     r_argonian);

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
};

using RaceRollList = Roll::RollList<Race>;
using RaceRollMatcher = Roll::RollMatcher<Race>;

const RaceRollList &getRaceRollList();

Aliases::String generateCharacterText();
}


#endif // CHARACTER_GEN_H
