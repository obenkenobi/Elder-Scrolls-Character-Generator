#include "domain_character_rolls.h"
#include "domain_roll.h"
#include "logging.h"
#include <stdexcept>
#include <utility>

// Archetype
// -----------------------------------------------------------------------------

enum ArchetypeId { a_mage, a_thief, a_warrior, a_any };

class Archetype : public Domain::RollItem<ArchetypeId>
{
private:
    static inline const Types::String LABEL_ = "Archetype";

public:
    using Domain::RollItem<ArchetypeId>::RollItem;

    Types::String getLabel() const { return LABEL_; }
};

Archetype createArchetype(const ArchetypeId id)
{
    switch (id) {
    case a_mage:
        return Archetype(id, "Mage");
    case a_warrior:
        return Archetype(id, "Warrior");
    case a_thief:
        return Archetype(id, "Thief");
    case a_any:
        return Archetype(id, "Any");
    }
    std::invalid_argument("Invalid archetype id when creating archetype");
}

using ArchetypeRollList = Domain::RollList<Archetype>;
using ArchetypeRollMatcher = Domain::RollMatcher<Archetype>;
using MageRange = Domain::Range;
using WarriorRange = Domain::Range;
using ThiefRange = Domain::Range;

ArchetypeRollList createArchetypeRollList(const WarriorRange warriorRange,
                                          const ThiefRange thiefRange,
                                          const MageRange mageRange)
{
    static auto warrior = createArchetype(a_warrior);
    static auto thief = createArchetype(a_thief);
    static auto mage = createArchetype(a_mage);

    return ArchetypeRollList{
        ArchetypeRollMatcher(warriorRange, warrior),
        ArchetypeRollMatcher(thiefRange, thief),
        ArchetypeRollMatcher(mageRange, mage),
    };
}

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

class RpgClass : public Domain::RollItem<RpgClassId>
{
private:
    static inline const Types::String LABEL_ = "Class";

public:
    using Domain::RollItem<RpgClassId>::RollItem;

    Types::String getLabel() const { return LABEL_; }
};

using RpgClassRollList = Domain::RollList<RpgClass>;
using RpgClassRollMatcher = Domain::RollMatcher<RpgClass>;

const RpgClassRollList &getWarriorClassRollList()
{
    static const auto archer = RpgClass(c_archer, "Archer");
    static const auto barbarian = RpgClass(c_barbarian, "Barbarian");
    static const auto crusader = RpgClass(c_crusader, "Crusader");
    static const auto knight = RpgClass(c_knight, "Knight");
    static const auto rogue = RpgClass(c_rogue, "Rogue");
    static const auto scout = RpgClass(c_scout, "Scout");
    static const auto warrior = RpgClass(c_warrior, "Warrior");
    static const auto list = RpgClassRollList{
        RpgClassRollMatcher(Domain::Range(1, 14), archer),
        RpgClassRollMatcher(Domain::Range(15, 28), barbarian),
        RpgClassRollMatcher(Domain::Range(29, 42), crusader),
        RpgClassRollMatcher(Domain::Range(43, 56), knight),
        RpgClassRollMatcher(Domain::Range(57, 70), rogue),
        RpgClassRollMatcher(Domain::Range(71, 84), scout),
        RpgClassRollMatcher(Domain::Range(85, 100), warrior),
    };
    return list;
}

const RpgClassRollList &getThiefClassRollList()
{
    static const auto acrobat = RpgClass(c_acrobat, "Acrobat");
    static const auto agent = RpgClass(c_agent, "Agent");
    static const auto assassin = RpgClass(c_assassin, "Assassin");
    static const auto bard = RpgClass(c_bard, "Bard");
    static const auto monk = RpgClass(c_monk, "Monk");
    static const auto pilgrim = RpgClass(c_pilgrim, "Pilgrim");
    static const auto thief = RpgClass(c_thief, "Thief");
    static const auto list = RpgClassRollList{
        RpgClassRollMatcher(Domain::Range(1, 14), acrobat),
        RpgClassRollMatcher(Domain::Range(15, 28), agent),
        RpgClassRollMatcher(Domain::Range(29, 42), assassin),
        RpgClassRollMatcher(Domain::Range(43, 56), bard),
        RpgClassRollMatcher(Domain::Range(57, 70), monk),
        RpgClassRollMatcher(Domain::Range(71, 84), pilgrim),
        RpgClassRollMatcher(Domain::Range(85, 100), thief),
    };
    return list;
}

const RpgClassRollList &getMageClassRollList()
{
    static const auto battleMage = RpgClass(c_battle_mage, "Battle Mage");
    static const auto healer = RpgClass(c_healer, "Healer");
    static const auto mage = RpgClass(c_mage, "Mage");
    static const auto nightBlade = RpgClass(c_night_blade, "Night Blade");
    static const auto sorcerer = RpgClass(c_sorcerer, "Sorcerer");
    static const auto spellSword = RpgClass(c_spell_sword, "Spell Sword");
    static const auto witchHunter = RpgClass(c_witch_hunter, "Witch Hunter");
    static const auto list = RpgClassRollList{
        RpgClassRollMatcher(Domain::Range(1, 14), battleMage),
        RpgClassRollMatcher(Domain::Range(15, 28), healer),
        RpgClassRollMatcher(Domain::Range(29, 42), mage),
        RpgClassRollMatcher(Domain::Range(43, 56), nightBlade),
        RpgClassRollMatcher(Domain::Range(57, 70), sorcerer),
        RpgClassRollMatcher(Domain::Range(71, 84), spellSword),
        RpgClassRollMatcher(Domain::Range(85, 100), witchHunter),
    };
    return list;
}

const RpgClassRollList &createRpgClassRollList(const ArchetypeId archetypeId)
{
    switch (archetypeId) {
    case a_warrior:
        return getWarriorClassRollList();
    case a_thief:
        return getThiefClassRollList();
    case a_mage:
        return getMageClassRollList();
    case a_any:
        break;
    }
    throw std::invalid_argument("Only archetype ids of warrior, thief, and mage allowed");
}

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

class BirthSign : public Domain::RollItem<BirthSignId>
{
public:
    BirthSign(const BirthSignId id, const ArchetypeId archetypeId, const Types::String &displayName)
        : RollItem(id, displayName)
        , archetypeId_(archetypeId)
    {}

    bool rollIfArchetypeBasedOnBirthSign() const
    {
        if (this->id_ != b_serpent) {
            const Domain::RollUint rollNum = Domain::rollRandNumber();
            return Domain::Range(1, 60).inRollRangeInclusive(rollNum);
        }
        return false;
    }

    Types::String getLabel() const { return LABEL_; }

    ArchetypeId getArchetypeId() const { return archetypeId_; }

private:
    static inline const Types::String LABEL_ = "Birthsign";
    ArchetypeId archetypeId_;
};

using BirthSignsRollList = Domain::RollList<BirthSign>;
using BirthSignsRollMatcher = Domain::RollMatcher<BirthSign>;

const BirthSignsRollList &getBirthSignsRollList()
{
    static const auto ritual = BirthSign(b_ritual, a_mage, "The Ritual");
    static const auto lover = BirthSign(b_lover, a_thief, "The Lover");
    static const auto lord = BirthSign(b_lord, a_warrior, "The Lord");
    static const auto mage = BirthSign(b_mage, a_mage, "The Mage");
    static const auto shadow = BirthSign(b_shadow, a_thief, "The Shadow");
    static const auto steed = BirthSign(b_steed, a_warrior, "The Steed");
    static const auto apprentice = BirthSign(b_apprentice, a_mage, "The Apprentice");
    static const auto warrior = BirthSign(b_warrior, a_warrior, "The Warrior");
    static const auto lady = BirthSign(b_lady, a_thief, "The Lady");
    static const auto tower = BirthSign(b_tower, a_thief, "The Tower");
    static const auto atronach = BirthSign(b_atronach, a_mage, "The Atronach");
    static const auto thief = BirthSign(b_thief, a_thief, "The Thief");
    static const auto serpent = BirthSign(b_serpent, a_any, "The Serpent");

    static const auto list
        = BirthSignsRollList{BirthSignsRollMatcher(Domain::Range(1, 8), ritual),
                             BirthSignsRollMatcher(Domain::Range(9, 14), lover),
                             BirthSignsRollMatcher(Domain::Range(15, 22), lord),
                             BirthSignsRollMatcher(Domain::Range(23, 30), mage),
                             BirthSignsRollMatcher(Domain::Range(31, 38), shadow),
                             BirthSignsRollMatcher(Domain::Range(39, 46), steed),
                             BirthSignsRollMatcher(Domain::Range(47, 55), apprentice),
                             BirthSignsRollMatcher(Domain::Range(56, 63), warrior),
                             BirthSignsRollMatcher(Domain::Range(64, 72), lady),
                             BirthSignsRollMatcher(Domain::Range(73, 81), tower),
                             BirthSignsRollMatcher(Domain::Range(82, 90), atronach),
                             BirthSignsRollMatcher(Domain::Range(91, 99), thief),
                             BirthSignsRollMatcher(Domain::Range(100, 100), serpent)};
    return list;
}

// Gender
// ------------------------------------------------------------------------------------------------------------

enum GenderId { gender_nil, male, female, nonbinary };
enum GenderAssignmentId : Types::Uint8 { gender_assignment_nil, afab, amab };

class Gender : public Domain::RollItem<GenderId>
{
private:
    static inline const Types::String LABEL_ = "Gender";
    bool isTrans_;
    GenderAssignmentId genderAssignmentId_;

public:
    Gender(GenderId id,
           Types::String displayName,
           bool isTranssexual,
           GenderAssignmentId genderAssignmentId)
        : RollItem(id, displayName)
        , isTrans_(isTranssexual)
        , genderAssignmentId_(genderAssignmentId)
    {}

    Gender()
        : RollItem(gender_nil, "")
        , isTrans_(true)
        , genderAssignmentId_(gender_assignment_nil)
    {}

    Types::String getLabel() const { return LABEL_; }
    bool isTrans() const { return isTrans_; }
    GenderAssignmentId genderAssignmentId() const { return genderAssignmentId_; };
};

using GenderRollMatcher = Domain::RollMatcher<Gender>;

using GenderRollList = Domain::RollList<Gender>;

GenderAssignmentId rollForGenderAssignment()
{
    static const auto afabRange = Domain::Range(1, 50);
    const Domain::RollUint assignedGenderRollNum = Domain::rollRandNumber();
    LOG_DEBUG << Types::String(
                     "Gender assignment roll number [%1] where afab is 1-50 and amab is 51-100")
                     .arg(assignedGenderRollNum);
    return afabRange.inRollRangeInclusive(assignedGenderRollNum) ? afab : amab;
}

bool rollForIsTrans()
{
    static const auto transRange = Domain::Range(99, 100);
    const Domain::RollUint transRollNum = Domain::rollRandNumber();
    LOG_DEBUG << Types::String("Trans roll number [%1] where being trans means you rolled a 100")
                     .arg(transRollNum);
    return transRange.inRollRangeInclusive(transRollNum);
}

bool rollIsNonbinary(bool isTrans)
{
    if (!isTrans) {
        return false;
    }
    static auto nbRange = Domain::Range(1, 50);
    const Domain::RollUint nbRollNum = Domain::rollRandNumber();
    LOG_DEBUG << Types::String("Nonbinary roll number [%1] where you are nonbinary in range [%2]")
                     .arg(nbRollNum)
                     .arg(nbRange.toString());

    return nbRange.inRollRangeInclusive(nbRollNum);
}

Gender rollGender()
{
    const GenderAssignmentId genderAssignmentId = rollForGenderAssignment();
    const bool isTrans = rollForIsTrans();
    const bool isNonbinary = rollIsNonbinary(isTrans);

    if (!isTrans) {
        return genderAssignmentId == amab ? Gender(male, "Man", isTrans, genderAssignmentId)
                                          : Gender(male, "Woman", isTrans, genderAssignmentId);
    }

    if (isNonbinary) {
        const Types::String assignmentStr = (genderAssignmentId == afab) ? "(AFAB)" : "(AMAB)";
        return Gender(male, "Nonbinary " + assignmentStr, isTrans, genderAssignmentId);
    }

    if (genderAssignmentId == amab) {
        return Gender(female, "Transgender Woman ", isTrans, genderAssignmentId);
    } else {
        return Gender(male, "Transgender Man", isTrans, genderAssignmentId);
    }
}

Gender rollGenderWithLogging()
{
    Gender gender = rollGender();
    LOG_DEBUG << Types::String("Rolled gender ") + gender.getDisplayName();
    return gender;
}

// Sexuality
// ------------------------------------------------------------------------------------------------------------

enum SexualityId { heterosexual, bisexual, homosexual };

class Sexuality : public Domain::RollItem<SexualityId>
{
private:
    static inline const Types::String LABEL_ = "Sexuality";

public:
    using Domain::RollItem<SexualityId>::RollItem;
    Types::String getLabel() const { return LABEL_; }
};

using SexualitiesRollList = Domain::RollList<Sexuality>;
using SexualitiesRollMatcher = Domain::RollMatcher<Sexuality>;

const SexualitiesRollList &createSexualitiesRollList(const GenderId genderId)
{
    static const auto hetero = Sexuality(heterosexual, "Heterosexual");
    static const auto bi = Sexuality(bisexual, "Bisexual");
    static const auto homo = Sexuality(homosexual, "Homosexual");
    static const auto femaleList = SexualitiesRollList{
        SexualitiesRollMatcher(Domain::Range(1, 67), hetero),
        SexualitiesRollMatcher(Domain::Range(68, 90), bi),
        SexualitiesRollMatcher(Domain::Range(91, 100), homo),
    };
    static const auto maleList = SexualitiesRollList{
        SexualitiesRollMatcher(Domain::Range(1, 72), hetero),
        SexualitiesRollMatcher(Domain::Range(73, 92), bi),
        SexualitiesRollMatcher(Domain::Range(93, 100), homo),
    };

    static const auto nonBinaryList = SexualitiesRollList{
        SexualitiesRollMatcher(Domain::Range(1, 69), hetero),
        SexualitiesRollMatcher(Domain::Range(70, 91), bi),
        SexualitiesRollMatcher(Domain::Range(92, 100), homo),
    };
    switch (genderId) {
    case male:
        return nonBinaryList;
    case female:
        return femaleList;
    case nonbinary:
        break;
    case gender_nil:
        break;
    }
    return nonBinaryList;
}

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

class SkinColor : public Domain::RollItem<SkinColorId>
{
private:
    static inline const Types::String LABEL_ = "Skin Color";

public:
    using Domain::RollItem<SkinColorId>::RollItem;

    Types::String getLabel() const { return LABEL_; }
};

using SkinColorRollList = Domain::RollList<SkinColor>;
using SkinColorMatcher = Domain::RollMatcher<SkinColor>;

SkinColorMatcher createSkinColorMatcher(const Domain::Range range, const SkinColorId &skinColorId)
{
    static const auto nil = SkinColor(sc_nil, "N/A");
    static const auto pale = SkinColor(sc_pale, "Pale");
    static const auto fair = SkinColor(sc_fair, "Fair");
    static const auto tan = SkinColor(sc_tan, "Tan");
    static const auto dark = SkinColor(sc_dark, "Dark");
    static const auto golden = SkinColor(sc_golden, "Golden");
    static const auto ashenGrey = SkinColor(sc_ashen_grey, "Ashen Grey");
    static const auto darkGrey = SkinColor(sc_dark_grey, "Dark Grey");
    static const auto nearBlack = SkinColor(sc_near_black, "Near Black");
    static const auto brown = SkinColor(sc_brown, "Brown");
    static const auto olive = SkinColor(sc_olive, "Olive");
    static const auto darkGreen = SkinColor(sc_dark_green, "Dark Green");
    switch (skinColorId) {
    case sc_pale:
        return SkinColorMatcher{range, pale};
    case sc_fair:
        return SkinColorMatcher{range, fair};
    case sc_tan:
        return SkinColorMatcher{range, tan};
    case sc_dark:
        return SkinColorMatcher{range, dark};
    case sc_golden:
        return SkinColorMatcher{range, golden};
    case sc_ashen_grey:
        return SkinColorMatcher{range, ashenGrey};
    case sc_dark_grey:
        return SkinColorMatcher{range, darkGrey};
    case sc_near_black:
        return SkinColorMatcher{range, nearBlack};
    case sc_brown:
        return SkinColorMatcher{range, brown};
    case sc_olive:
        return SkinColorMatcher{range, olive};
    case sc_dark_green:
        return SkinColorMatcher{range, darkGreen};
    case sc_nil:
        return SkinColorMatcher{range, nil};
    }
    return SkinColorMatcher{range, nil};
}

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

class HairColor : public Domain::RollItem<HairColorId>
{
private:
    static inline const Types::String LABEL_ = "Hair Color";

public:
    using Domain::RollItem<HairColorId>::RollItem;
    Types::String getLabel() const { return LABEL_; }
};

using HairColorRollList = Domain::RollList<HairColor>;
using HairColorMatcher = Domain::RollMatcher<HairColor>;

HairColorMatcher createHairColorMatcher(const Domain::Range range, const HairColorId id)
{
    static const auto nil = HairColor(hc_nil, "N/A");
    static const auto blonde = HairColor(hc_blonde, "Blonde");
    static const auto brown = HairColor(hc_brown, "Brown");
    static const auto red = HairColor(hc_red, "Red");
    static const auto black = HairColor(hc_black, "Black");
    static const auto darkRed = HairColor(hc_dark_red, "Dark Red");
    static const auto grey = HairColor(hc_grey, "Grey");
    static const auto goldenBlonde = HairColor(hc_golden_blonde, "Golden Blonde");
    static const auto silverWhite = HairColor(hc_silver_white, "Silver White");
    static const auto lightBrown = HairColor(hc_light_brown, "Light Brown");
    static const auto green = HairColor(hc_green, "Green");
    static const auto darkBrown = HairColor(hc_dark_brown, "Dark Brown");
    static const auto white = HairColor(hc_white, "White");
    static const auto orange = HairColor(hc_orange, "Orange");

    switch (id) {
    case hc_blonde:
        return HairColorMatcher{range, blonde};
    case hc_brown:
        return HairColorMatcher{range, brown};
    case hc_red:
        return HairColorMatcher{range, red};
    case hc_black:
        return HairColorMatcher{range, black};
    case hc_dark_red:
        return HairColorMatcher{range, darkRed};
    case hc_grey:
        return HairColorMatcher{range, grey};
    case hc_golden_blonde:
        return HairColorMatcher{range, goldenBlonde};
    case hc_silver_white:
        return HairColorMatcher{range, silverWhite};
    case hc_light_brown:
        return HairColorMatcher{range, lightBrown};
    case hc_green:
        return HairColorMatcher{range, green};
    case hc_dark_brown:
        return HairColorMatcher{range, darkBrown};
    case hc_white:
        return HairColorMatcher{range, white};
    case hc_orange:
        return HairColorMatcher{range, orange};
    case hc_nil:
        return HairColorMatcher{range, nil};
    }
    return HairColorMatcher{range, nil};
}

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

class EyeColor : public Domain::RollItem<EyeColorId>
{
private:
    static inline const Types::String LABEL_ = "Eye Color";

public:
    using Domain::RollItem<EyeColorId>::RollItem;
    Types::String getLabel() const { return LABEL_; }
};

using EyeColorRollList = Domain::RollList<EyeColor>;
using EyeColorMatcher = Domain::RollMatcher<EyeColor>;

EyeColorMatcher createEyeColorMatcher(const Domain::Range range, const EyeColorId id)
{
    static const auto blue = EyeColor(ec_blue, "Blue");
    static const auto green = EyeColor(ec_green, "Green");
    static const auto grey = EyeColor(ec_grey, "Grey");
    static const auto brown = EyeColor(ec_brown, "Brown");
    static const auto black = EyeColor(ec_black, "Black");
    static const auto hazel = EyeColor(ec_hazel, "Hazel");
    static const auto amber = EyeColor(ec_amber, "Amber");
    static const auto red = EyeColor(ec_red, "Red");
    static const auto orange = EyeColor(ec_orange, "Orange");
    static const auto gold = EyeColor(ec_gold, "Gold");
    static const auto yellow = EyeColor(ec_yellow, "Yellow");
    static const auto nil = EyeColor(ec_nil, "N/A");

    switch (id) {
    case ec_blue:
        return EyeColorMatcher{range, blue};
    case ec_green:
        return EyeColorMatcher{range, green};
    case ec_grey:
        return EyeColorMatcher{range, grey};
    case ec_brown:
        return EyeColorMatcher{range, brown};
    case ec_black:
        return EyeColorMatcher{range, black};
    case ec_hazel:
        return EyeColorMatcher{range, hazel};
    case ec_amber:
        return EyeColorMatcher{range, amber};
    case ec_red:
        return EyeColorMatcher{range, red};
    case ec_orange:
        return EyeColorMatcher{range, orange};
    case ec_gold:
        return EyeColorMatcher{range, gold};
    case ec_yellow:
        return EyeColorMatcher{range, yellow};
    case ec_nil:
        return EyeColorMatcher{range, nil};
    }
    return EyeColorMatcher{range, nil};
}

// Fur Pattern --------------------------------------------------------

enum FurPatternId { fp_nil, fp_striped, fp_spotted, fp_solid, fp_tabby };

class FurPattern : public Domain::RollItem<FurPatternId>
{
private:
    static inline const Types::String LABEL_ = "Fur Pattern";

public:
    using Domain::RollItem<FurPatternId>::RollItem;
    Types::String getLabel() const { return LABEL_; }
};

using FurPatternRollList = Domain::RollList<FurPattern>;
using FurPatternMatcher = Domain::RollMatcher<FurPattern>;

FurPatternMatcher createFurPatternMatcher(const Domain::Range range, const FurPatternId id)
{
    static const auto striped = FurPattern(fp_striped, "Striped");
    static const auto spotted = FurPattern(fp_spotted, "Spotted");
    static const auto solid = FurPattern(fp_solid, "Solid");
    static const auto tabby = FurPattern(fp_tabby, "Tabby");
    static const auto nil = FurPattern(fp_nil, "N/A");

    switch (id) {
    case fp_striped:
        return FurPatternMatcher{range, striped};
    case fp_spotted:
        return FurPatternMatcher{range, spotted};
    case fp_solid:
        return FurPatternMatcher{range, solid};
    case fp_tabby:
        return FurPatternMatcher{range, tabby};
    case fp_nil:
        return FurPatternMatcher{range, nil};
    }
    return FurPatternMatcher{range, nil};
}

// Scale Color --------------------------------------------------------

enum ScaleColorId { scl_null, scl_dark_green, scl_olive, scl_brown, scl_grey };

class ScaleColor : public Domain::RollItem<ScaleColorId>
{
private:
    static inline const Types::String LABEL_ = "Scale Color";

public:
    using Domain::RollItem<ScaleColorId>::RollItem;
    Types::String getLabel() const { return LABEL_; }
};

using ScaleColorRollList = Domain::RollList<ScaleColor>;
using ScaleColorMatcher = Domain::RollMatcher<ScaleColor>;

ScaleColorMatcher createScaleColorMatcher(const Domain::Range range, const ScaleColorId id)
{
    static const auto darkGreen = ScaleColor(scl_dark_green, "Dark Green");
    static const auto olive = ScaleColor(scl_olive, "Olive");
    static const auto brown = ScaleColor(scl_brown, "Brown");
    static const auto grey = ScaleColor(scl_grey, "Grey");
    static const auto null = ScaleColor(scl_null, "N/A");

    switch (id) {
    case scl_dark_green:
        return ScaleColorMatcher{range, darkGreen};
    case scl_olive:
        return ScaleColorMatcher{range, olive};
    case scl_brown:
        return ScaleColorMatcher{range, brown};
    case scl_grey:
        return ScaleColorMatcher{range, grey};
    case scl_null:
        return ScaleColorMatcher{range, null};
    }
    return ScaleColorMatcher{range, null};
}

// Horn Type --------------------------------------------------------
enum HornTypeId { ht_null, ht_none, ht_spiked, ht_curved, ht_both };

class HornType : public Domain::RollItem<HornTypeId>
{
private:
    static inline const Types::String LABEL_ = "Horn Type";

public:
    using Domain::RollItem<HornTypeId>::RollItem;
    Types::String getLabel() const { return LABEL_; }
};

using HornTypeRollList = Domain::RollList<HornType>;
using HornTypeMatcher = Domain::RollMatcher<HornType>;

HornTypeMatcher createHornTypeMatcher(const Domain::Range range, const HornTypeId id)
{
    static const auto none = HornType(ht_none, "None");
    static const auto spiked = HornType(ht_spiked, "Spiked");
    static const auto curved = HornType(ht_curved, "Curved");
    static const auto both = HornType(ht_both, "Spiked & Curved");
    static const auto null = HornType(ht_null, "N/A");

    switch (id) {
    case ht_none:
        return HornTypeMatcher{range, none};
    case ht_spiked:
        return HornTypeMatcher{range, spiked};
    case ht_curved:
        return HornTypeMatcher{range, curved};
    case ht_both:
        return HornTypeMatcher{range, both};
    case ht_null:
        return HornTypeMatcher{range, null};
    }
    return HornTypeMatcher{range, null};
}

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

class Race : public Domain::RollItem<RaceId>
{
public:
    Race(const RaceId &id,
         const Types::String &displayName,
         ArchetypeRollList archetypeRollList,
         SkinColorRollList skinColorRollList,
         HairColorRollList hairColorRollList,
         EyeColorRollList eyeColorRollList,
         FurPatternRollList furPatternRollList,
         ScaleColorRollList scaleColorRollList,
         HornTypeRollList hornTypeRollList)
        : RollItem(id, displayName)
        , archetypeRollList_(std::move(archetypeRollList))
        , skinColorRollList_(std::move(skinColorRollList))
        , hairColorRollList_(std::move(hairColorRollList))
        , eyeColorRollList_(std::move(eyeColorRollList))
        , furPatternRollList_(std::move(furPatternRollList))
        , scaleColorRollList_(std::move(scaleColorRollList))
        , hornTypeRollList_(std::move(hornTypeRollList))
    {}

    Types::String getLabel() const { return LABEL_; }

    Archetype rollArchetype() const { return archetypeRollList_.rollForItem(); }

    SkinColor rollSkinColor() const { return skinColorRollList_.rollForItem(); }

    HairColor rollHairColor() const { return hairColorRollList_.rollForItem(); }

    EyeColor rollEyeColor() const { return eyeColorRollList_.rollForItem(); }

    FurPattern rollFurPattern() const { return furPatternRollList_.rollForItem(); }

    ScaleColor rollScaleColor() const { return scaleColorRollList_.rollForItem(); }

    HornType rollHornType() const { return hornTypeRollList_.rollForItem(); }

private:
    ArchetypeRollList archetypeRollList_;
    SkinColorRollList skinColorRollList_;
    HairColorRollList hairColorRollList_;
    EyeColorRollList eyeColorRollList_;
    FurPatternRollList furPatternRollList_;
    ScaleColorRollList scaleColorRollList_;
    HornTypeRollList hornTypeRollList_;
    static inline const Types::String LABEL_ = "Race";
};

using RaceRollList = Domain::RollList<Race>;
using RaceRollMatcher = Domain::RollMatcher<Race>;

const RaceRollList &getRaceRollList()
{
    static const auto nord
        = Race{r_nord,
               "Nord",
               createArchetypeRollList(WarriorRange(1, 60), ThiefRange(61, 80), MageRange(81, 100)),
               SkinColorRollList{createSkinColorMatcher(Domain::Range(1, 70), sc_pale),
                                 createSkinColorMatcher(Domain::Range(71, 95), sc_fair),
                                 createSkinColorMatcher(Domain::Range(96, 100), sc_tan)},
               HairColorRollList{createHairColorMatcher(Domain::Range(1, 60), hc_blonde),
                                 createHairColorMatcher(Domain::Range(61, 90), hc_brown),
                                 createHairColorMatcher(Domain::Range(91, 97), hc_red),
                                 createHairColorMatcher(Domain::Range(98, 100), hc_black)},
               EyeColorRollList{createEyeColorMatcher(Domain::Range(1, 50), ec_blue),
                                createEyeColorMatcher(Domain::Range(51, 80), ec_green),
                                createEyeColorMatcher(Domain::Range(81, 90), ec_grey),
                                createEyeColorMatcher(Domain::Range(91, 95), ec_brown),
                                createEyeColorMatcher(Domain::Range(96, 100), ec_hazel)},
               FurPatternRollList{createFurPatternMatcher(Domain::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Domain::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Domain::Range(1, 100), ht_null)}};
    static const auto imperial
        = Race{r_imperial,
               "Imperial",
               createArchetypeRollList(WarriorRange(1, 40), ThiefRange(41, 60), MageRange(61, 100)),
               SkinColorRollList{createSkinColorMatcher(Domain::Range(1, 50), sc_tan),
                                 createSkinColorMatcher(Domain::Range(51, 80), sc_fair),
                                 createSkinColorMatcher(Domain::Range(81, 95), sc_pale),
                                 createSkinColorMatcher(Domain::Range(96, 100), sc_dark)},
               HairColorRollList{createHairColorMatcher(Domain::Range(1, 40), hc_brown),
                                 createHairColorMatcher(Domain::Range(41, 75), hc_black),
                                 createHairColorMatcher(Domain::Range(76, 90), hc_blonde),
                                 createHairColorMatcher(Domain::Range(91, 100), hc_red)},
               EyeColorRollList{createEyeColorMatcher(Domain::Range(1, 60), ec_brown),
                                createEyeColorMatcher(Domain::Range(61, 80), ec_hazel),
                                createEyeColorMatcher(Domain::Range(81, 95), ec_blue),
                                createEyeColorMatcher(Domain::Range(96, 100), ec_green)},
               FurPatternRollList{createFurPatternMatcher(Domain::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Domain::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Domain::Range(1, 100), ht_null)}};
    static const auto breton
        = Race{r_breton,
               "Breton",
               createArchetypeRollList(WarriorRange(1, 25), ThiefRange(26, 50), MageRange(51, 100)),
               SkinColorRollList{
                   createSkinColorMatcher(Domain::Range(1, 40), sc_pale),
                   createSkinColorMatcher(Domain::Range(41, 90), sc_fair),
                   createSkinColorMatcher(Domain::Range(91, 100), sc_tan),
               },
               HairColorRollList{createHairColorMatcher(Domain::Range(1, 40), hc_brown),
                                 createHairColorMatcher(Domain::Range(41, 70), hc_black),
                                 createHairColorMatcher(Domain::Range(71, 90), hc_blonde),
                                 createHairColorMatcher(Domain::Range(91, 100), hc_red)},
               EyeColorRollList{createEyeColorMatcher(Domain::Range(1, 40), ec_blue),
                                createEyeColorMatcher(Domain::Range(41, 70), ec_green),
                                createEyeColorMatcher(Domain::Range(71, 80), ec_grey),
                                createEyeColorMatcher(Domain::Range(81, 90), ec_brown),
                                createEyeColorMatcher(Domain::Range(91, 100), ec_hazel)},
               FurPatternRollList{createFurPatternMatcher(Domain::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Domain::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Domain::Range(1, 100), ht_null)}};
    static const auto redguard
        = Race{r_redguard,
               "Redguard",
               createArchetypeRollList(WarriorRange(1, 60), ThiefRange(61, 80), MageRange(81, 100)),
               SkinColorRollList{
                   createSkinColorMatcher(Domain::Range(1, 60), sc_dark),
                   createSkinColorMatcher(Domain::Range(61, 90), sc_tan),
                   createSkinColorMatcher(Domain::Range(91, 100), sc_olive),
               },
               HairColorRollList{createHairColorMatcher(Domain::Range(1, 70), hc_black),
                                 createHairColorMatcher(Domain::Range(71, 90), hc_brown),
                                 createHairColorMatcher(Domain::Range(91, 100), hc_dark_red)},
               EyeColorRollList{createEyeColorMatcher(Domain::Range(1, 60), ec_brown),
                                createEyeColorMatcher(Domain::Range(61, 80), ec_black),
                                createEyeColorMatcher(Domain::Range(81, 95), ec_amber),
                                createEyeColorMatcher(Domain::Range(96, 100), ec_hazel)},
               FurPatternRollList{createFurPatternMatcher(Domain::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Domain::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Domain::Range(1, 100), ht_null)}};
    static const auto dunmer
        = Race(r_dunmer,
               "Dunmer (Dark Elf)",
               createArchetypeRollList(WarriorRange(1, 35), ThiefRange(36, 65), MageRange(66, 100)),
               SkinColorRollList{createSkinColorMatcher(Domain::Range(1, 70), sc_ashen_grey),
                                 createSkinColorMatcher(Domain::Range(71, 95), sc_dark_grey),
                                 createSkinColorMatcher(Domain::Range(96, 100), sc_near_black)},
               HairColorRollList{createHairColorMatcher(Domain::Range(1, 80), hc_black),
                                 createHairColorMatcher(Domain::Range(81, 95), hc_dark_red),
                                 createHairColorMatcher(Domain::Range(96, 100), hc_grey)},
               EyeColorRollList{createEyeColorMatcher(Domain::Range(1, 60), ec_red),
                                createEyeColorMatcher(Domain::Range(61, 90), ec_amber),
                                createEyeColorMatcher(Domain::Range(91, 95), ec_orange),
                                createEyeColorMatcher(Domain::Range(96, 100), ec_brown)},
               FurPatternRollList{createFurPatternMatcher(Domain::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Domain::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Domain::Range(1, 100), ht_null)});
    static const auto altmer
        = Race{r_altmer,
               "Altmer (High Elf)",
               createArchetypeRollList(WarriorRange(1, 15), ThiefRange(16, 30), MageRange(31, 100)),
               SkinColorRollList{
                   createSkinColorMatcher(Domain::Range(1, 70), sc_fair),
                   createSkinColorMatcher(Domain::Range(71, 90), sc_pale),
                   createSkinColorMatcher(Domain::Range(91, 100), sc_golden),
               },
               HairColorRollList{createHairColorMatcher(Domain::Range(1, 60), hc_golden_blonde),
                                 createHairColorMatcher(Domain::Range(61, 90), hc_silver_white),
                                 createHairColorMatcher(Domain::Range(91, 100), hc_light_brown)},
               EyeColorRollList{createEyeColorMatcher(Domain::Range(1, 70), ec_gold),
                                createEyeColorMatcher(Domain::Range(71, 90), ec_blue),
                                createEyeColorMatcher(Domain::Range(91, 95), ec_green),
                                createEyeColorMatcher(Domain::Range(96, 100), ec_amber)},
               FurPatternRollList{createFurPatternMatcher(Domain::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Domain::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Domain::Range(1, 100), ht_null)}};
    static const auto bosmer
        = Race{r_bosmer,
               "Bosmer (Wood Elf)",
               createArchetypeRollList(WarriorRange(1, 35), ThiefRange(36, 85), MageRange(86, 100)),
               SkinColorRollList{
                   createSkinColorMatcher(Domain::Range(1, 50), sc_tan),
                   createSkinColorMatcher(Domain::Range(51, 80), sc_olive),
                   createSkinColorMatcher(Domain::Range(81, 100), sc_brown),
               },
               HairColorRollList{createHairColorMatcher(Domain::Range(1, 60), hc_brown),
                                 createHairColorMatcher(Domain::Range(61, 80), hc_black),
                                 createHairColorMatcher(Domain::Range(81, 90), hc_green),
                                 createHairColorMatcher(Domain::Range(91, 95), hc_blonde),
                                 createHairColorMatcher(Domain::Range(96, 100), hc_red)},
               EyeColorRollList{createEyeColorMatcher(Domain::Range(1, 60), ec_green),
                                createEyeColorMatcher(Domain::Range(61, 80), ec_hazel),
                                createEyeColorMatcher(Domain::Range(81, 95), ec_brown),
                                createEyeColorMatcher(Domain::Range(96, 100), ec_amber)},
               FurPatternRollList{createFurPatternMatcher(Domain::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Domain::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Domain::Range(1, 100), ht_null)}};
    static const auto orsimer
        = Race{r_orsimer,
               "Orsimer (Orc)",
               createArchetypeRollList(WarriorRange(1, 65), ThiefRange(66, 80), MageRange(81, 100)),
               SkinColorRollList{
                   createSkinColorMatcher(Domain::Range(1, 60), sc_olive),
                   createSkinColorMatcher(Domain::Range(61, 90), sc_dark_green),
                   createSkinColorMatcher(Domain::Range(91, 100), sc_dark),
               },
               HairColorRollList{createHairColorMatcher(Domain::Range(1, 70), hc_black),
                                 createHairColorMatcher(Domain::Range(71, 90), hc_dark_brown),
                                 createHairColorMatcher(Domain::Range(91, 95), hc_grey),
                                 createHairColorMatcher(Domain::Range(96, 100), hc_red)},
               EyeColorRollList{createEyeColorMatcher(Domain::Range(1, 60), ec_brown),
                                createEyeColorMatcher(Domain::Range(61, 80), ec_red),
                                createEyeColorMatcher(Domain::Range(81, 90), ec_yellow),
                                createEyeColorMatcher(Domain::Range(91, 95), ec_amber),
                                createEyeColorMatcher(Domain::Range(96, 100), ec_orange)},
               FurPatternRollList{createFurPatternMatcher(Domain::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Domain::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Domain::Range(1, 100), ht_null)}};
    static const auto khajiit
        = Race{r_khajiit,
               "Khajiit",
               createArchetypeRollList(WarriorRange(1, 35), ThiefRange(36, 75), MageRange(76, 100)),
               SkinColorRollList{createSkinColorMatcher(Domain::Range(1, 100), sc_nil)},
               HairColorRollList{createHairColorMatcher(Domain::Range(1, 30), hc_brown),
                                 createHairColorMatcher(Domain::Range(31, 55), hc_black),
                                 createHairColorMatcher(Domain::Range(56, 75), hc_grey),
                                 createHairColorMatcher(Domain::Range(76, 90), hc_white),
                                 createHairColorMatcher(Domain::Range(91, 100), hc_orange)},
               EyeColorRollList{createEyeColorMatcher(Domain::Range(1, 40), ec_amber),
                                createEyeColorMatcher(Domain::Range(41, 70), ec_green),
                                createEyeColorMatcher(Domain::Range(71, 90), ec_yellow),
                                createEyeColorMatcher(Domain::Range(91, 95), ec_blue),
                                createEyeColorMatcher(Domain::Range(96, 100), ec_brown)},
               FurPatternRollList{
                   createFurPatternMatcher(Domain::Range(1, 40), fp_striped),
                   createFurPatternMatcher(Domain::Range(41, 70), fp_spotted),
                   createFurPatternMatcher(Domain::Range(71, 90), fp_solid),
                   createFurPatternMatcher(Domain::Range(91, 100), fp_tabby),
               },
               ScaleColorRollList{createScaleColorMatcher(Domain::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Domain::Range(1, 100), ht_null)}};
    static const auto argonian
        = Race{r_argonian,
               "Argonian",
               createArchetypeRollList(WarriorRange(1, 40), ThiefRange(41, 80), MageRange(81, 100)),
               SkinColorRollList{createSkinColorMatcher(Domain::Range(1, 100), sc_nil)},
               HairColorRollList{createHairColorMatcher(Domain::Range(1, 100), hc_nil)},
               EyeColorRollList{createEyeColorMatcher(Domain::Range(1, 40), ec_yellow),
                                createEyeColorMatcher(Domain::Range(41, 70), ec_red),
                                createEyeColorMatcher(Domain::Range(71, 85), ec_orange),
                                createEyeColorMatcher(Domain::Range(86, 95), ec_green),
                                createEyeColorMatcher(Domain::Range(96, 100), ec_amber)},
               FurPatternRollList{createFurPatternMatcher(Domain::Range(1, 100), fp_nil)},
               ScaleColorRollList{
                   createScaleColorMatcher(Domain::Range(1, 50), scl_dark_green),
                   createScaleColorMatcher(Domain::Range(51, 80), scl_olive),
                   createScaleColorMatcher(Domain::Range(81, 95), scl_brown),
                   createScaleColorMatcher(Domain::Range(96, 100), scl_grey),
               },
               HornTypeRollList{createHornTypeMatcher(Domain::Range(1, 35), ht_none),
                                createHornTypeMatcher(Domain::Range(36, 60), ht_spiked),
                                createHornTypeMatcher(Domain::Range(61, 85), ht_curved),
                                createHornTypeMatcher(Domain::Range(86, 100), ht_both)}};
    static const auto list = RaceRollList{RaceRollMatcher(Domain::Range(1, 42), nord),
                                          RaceRollMatcher(Domain::Range(43, 55), imperial),
                                          RaceRollMatcher(Domain::Range(56, 67), breton),
                                          RaceRollMatcher(Domain::Range(68, 75), dunmer),
                                          RaceRollMatcher(Domain::Range(76, 81), altmer),
                                          RaceRollMatcher(Domain::Range(82, 87), orsimer),
                                          RaceRollMatcher(Domain::Range(88, 92), redguard),
                                          RaceRollMatcher(Domain::Range(93, 95), bosmer),
                                          RaceRollMatcher(Domain::Range(96, 98), khajiit),
                                          RaceRollMatcher(Domain::Range(99, 100), argonian)};
    return list;
}

Archetype rollArchetype(const BirthSign &birthSign, const Race &race)
{
    static const Types::String logFormat
        = "Archetype rolls based on [%1] [%2] and the archetype rolled is [%3]";
    const bool isArchetypeBasedOnBirthSign = birthSign.rollIfArchetypeBasedOnBirthSign();
    if (isArchetypeBasedOnBirthSign) {
        Archetype archetypeBsign = createArchetype(birthSign.getArchetypeId());
        LOG_INFO << logFormat.arg("birthsign",
                                  birthSign.getDisplayName(),
                                  archetypeBsign.getDisplayName());
    }
    Archetype rolledArchetype = race.rollArchetype();
    LOG_INFO << logFormat.arg("race", race.getDisplayName(), rolledArchetype.getDisplayName());
    return rolledArchetype;
}

void Domain::rollForESCharSheet(Types::WeakPtr<ESCharSheet> weakPtr)
{
    Types::SharedPtr<ESCharSheet> sheet = weakPtr.lock();
    if (sheet.isNull()) {
        return;
    }

    sheet->clear();

    LOG_INFO << "__________Begin rolling for character__________";

    const RaceRollList &raceRollList = getRaceRollList();
    const Race &race = raceRollList.rollForItem();

    sheet->insertAttribute(createAttribute(race));

    const BirthSignsRollList &birthSignRollList = getBirthSignsRollList();
    const BirthSign &birthSign = birthSignRollList.rollForItem();

    sheet->insertAttribute(createAttribute(birthSign));

    const Gender gender = rollGenderWithLogging();

    sheet->insertAttribute(createAttribute(gender));

    const SexualitiesRollList sexualitiesRollList = createSexualitiesRollList(gender.getId());
    const Sexuality &sexuality = sexualitiesRollList.rollForItem();

    sheet->insertAttribute(createAttribute(sexuality));

    const Archetype archetype = rollArchetype(birthSign, race);
    sheet->insertAttribute(createAttribute(archetype));

    const RpgClassRollList rpgClassRollList = createRpgClassRollList(archetype.getId());
    const RpgClass rpgClass = rpgClassRollList.rollForItem();

    sheet->insertAttribute(createAttribute(rpgClass));

    const SkinColor skinColor = race.rollSkinColor();
    if (skinColor.getId() != sc_nil) {
        sheet->insertAttribute(createAttribute(skinColor));
    }

    const HairColor hairColor = race.rollHairColor();
    if (hairColor.getId() != hc_nil) {
        sheet->insertAttribute(createAttribute(hairColor));
    }

    const FurPattern furPattern = race.rollFurPattern();
    if (furPattern.getId() != fp_nil) {
        sheet->insertAttribute(createAttribute(furPattern));
    }

    const ScaleColor scaleColor = race.rollScaleColor();
    if (scaleColor.getId() != scl_null) {
        sheet->insertAttribute(createAttribute(scaleColor));
    }

    const HornType hornType = race.rollHornType();
    if (hornType.getId() != ht_null) {
        sheet->insertAttribute(createAttribute(hornType));
    }

    const EyeColor eyeColor = race.rollEyeColor();
    sheet->insertAttribute(createAttribute(eyeColor));

    LOG_INFO << "__________Finished rolling character__________";

    LOG_INFO << "New Character Sheet";
    LOG_INFO << sheet->toLoggableString();
}
