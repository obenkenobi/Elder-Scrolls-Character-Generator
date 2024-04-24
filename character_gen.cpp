#include "character_gen.h"
#include "logging.h"
#include <stdexcept>
#include <utility>

namespace CharGen {

Aliases::String Archetype::getLabel() const
{
    return LABEL_;
}

Archetype createArchetype(const ArchetypeId id)
{
    switch (id) {
    case a_mage:
        return Archetype(a_mage, "Mage");
    case a_warrior:
        return Archetype(a_mage, "Warrior");
    case a_thief:
        return Archetype(a_thief, "Thief");
    case a_any:
        break;
    }
    return Archetype(a_any, "Any");
}

ArchetypeRollList createArchetypeRollList(const MageRange mageRange,
                                          const WarriorRange warriorRange,
                                          const ThiefRange thiefRange)
{
    static auto mage = createArchetype(a_mage);
    static auto warrior = createArchetype(a_warrior);
    static auto thief = createArchetype(a_thief);

    return ArchetypeRollList{
        ArchetypeRollMatcher(mageRange, mage),
        ArchetypeRollMatcher(warriorRange, warrior),
        ArchetypeRollMatcher(thiefRange, thief),
    };
}

Aliases::String RpgClass::getLabel() const
{
    return LABEL_;
}

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
        RpgClassRollMatcher(Roll::Range(1, 14), archer),
        RpgClassRollMatcher(Roll::Range(15, 28), barbarian),
        RpgClassRollMatcher(Roll::Range(29, 42), crusader),
        RpgClassRollMatcher(Roll::Range(43, 56), knight),
        RpgClassRollMatcher(Roll::Range(57, 70), rogue),
        RpgClassRollMatcher(Roll::Range(71, 84), scout),
        RpgClassRollMatcher(Roll::Range(85, 100), warrior),
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
        RpgClassRollMatcher(Roll::Range(1, 14), acrobat),
        RpgClassRollMatcher(Roll::Range(15, 28), agent),
        RpgClassRollMatcher(Roll::Range(29, 42), assassin),
        RpgClassRollMatcher(Roll::Range(43, 56), bard),
        RpgClassRollMatcher(Roll::Range(57, 70), monk),
        RpgClassRollMatcher(Roll::Range(71, 84), pilgrim),
        RpgClassRollMatcher(Roll::Range(85, 100), thief),
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
        RpgClassRollMatcher(Roll::Range(1, 14), battleMage),
        RpgClassRollMatcher(Roll::Range(15, 28), healer),
        RpgClassRollMatcher(Roll::Range(29, 42), mage),
        RpgClassRollMatcher(Roll::Range(43, 56), nightBlade),
        RpgClassRollMatcher(Roll::Range(57, 70), sorcerer),
        RpgClassRollMatcher(Roll::Range(71, 84), spellSword),
        RpgClassRollMatcher(Roll::Range(85, 100), witchHunter),
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

BirthSign::BirthSign(const BirthSignId id,
                     const ArchetypeId archetypeId,
                     const Aliases::String &displayName)
    : RollItem(id, displayName)
    , archetypeId_(archetypeId)
{}

bool BirthSign::rollIfArchetypeBasedOnBirthSign() const
{
    if (this->id_ != b_serpent) {
        const Roll::RollUint rollNum = Roll::rollRandNumber();
        return Roll::Range(1, 60).inRollRangeInclusive(rollNum);
    }
    return false;
}

Aliases::String BirthSign::getLabel() const
{
    return LABEL_;
}

ArchetypeId BirthSign::getArchetypeId() const
{
    return archetypeId_;
}

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
        = BirthSignsRollList{BirthSignsRollMatcher(Roll::Range(1, 8), ritual),
                             BirthSignsRollMatcher(Roll::Range(9, 14), lover),
                             BirthSignsRollMatcher(Roll::Range(15, 22), lord),
                             BirthSignsRollMatcher(Roll::Range(23, 30), mage),
                             BirthSignsRollMatcher(Roll::Range(31, 38), shadow),
                             BirthSignsRollMatcher(Roll::Range(39, 46), steed),
                             BirthSignsRollMatcher(Roll::Range(47, 55), apprentice),
                             BirthSignsRollMatcher(Roll::Range(56, 63), warrior),
                             BirthSignsRollMatcher(Roll::Range(64, 72), lady),
                             BirthSignsRollMatcher(Roll::Range(73, 81), tower),
                             BirthSignsRollMatcher(Roll::Range(82, 90), atronach),
                             BirthSignsRollMatcher(Roll::Range(91, 99), thief),
                             BirthSignsRollMatcher(Roll::Range(100, 100), serpent)};
    return list;
}

bool Sex::isTranssexual() const
{
    return isTranssexual_;
}

Sex::Sex(SexId id, Aliases::String displayName, bool isTranssexual)
    : RollItem(id, displayName)
    , isTranssexual_(isTranssexual)
{}

Aliases::String Sex::getLabel() const
{
    return LABEL_;
}

Sex rollForSex()
{
    static const auto sexRange = Roll::Range(1, 50);
    const Roll::RollUint sexIdRollNum = Roll::rollRandNumber();
    const SexId sexId = sexRange.inRollRangeInclusive(sexIdRollNum) ? male : female;
    const Aliases::String sexString = sexId == male ? "Man" : "Woman";

    static const auto transRange = Roll::Range(100, 100);
    const Roll::RollUint transRollNum = Roll::rollRandNumber();
    static bool isTrans = transRange.inRollRangeInclusive(transRollNum);
    const Aliases::String transStatusString = !isTrans ? "" : "Transsexual ";

    const Aliases::String displayName = transStatusString + sexString;

    LOG_DEBUG << Aliases::String("Rolled for sex [%1] with sex roll %2 and trans roll %3")
                     .arg(displayName)
                     .arg(sexIdRollNum)
                     .arg(transRollNum);

    return Sex(sexId, displayName, isTrans);
}

Aliases::String Sexuality::getLabel() const
{
    return LABEL_;
}

const SexualitiesRollList &createSexualitiesRollList(const SexId sexId)
{
    static const auto hetero = Sexuality(heterosexual, "Heterosexual");
    static const auto bi = Sexuality(bisexual, "Bisexual");
    static const auto homo = Sexuality(homosexual, "Homosexual");
    static const auto femaleList = SexualitiesRollList{
        SexualitiesRollMatcher(Roll::Range(1, 67), hetero),
        SexualitiesRollMatcher(Roll::Range(68, 90), bi),
        SexualitiesRollMatcher(Roll::Range(91, 100), homo),
    };
    static const auto maleList = SexualitiesRollList{
        SexualitiesRollMatcher(Roll::Range(1, 72), hetero),
        SexualitiesRollMatcher(Roll::Range(73, 92), bi),
        SexualitiesRollMatcher(Roll::Range(93, 100), homo),
    };
    if (sexId == female) {
        return femaleList;
    }
    return maleList;
}

Aliases::String SkinColor::getLabel() const
{
    return LABEL_;
}

SkinColorMatcher createSkinColorMatcher(const Roll::Range range, const SkinColorId &skinColorId)
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

Aliases::String HairColor::getLabel() const
{
    return LABEL_;
}

HairColorMatcher createHairColorMatcher(const Roll::Range range, const HairColorId id)
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

Aliases::String EyeColor::getLabel() const
{
    return LABEL_;
}

EyeColorMatcher createEyeColorMatcher(const Roll::Range range, const EyeColorId id)
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

Aliases::String FurPattern::getLabel() const
{
    return LABEL_;
}

FurPatternMatcher createFurPatternMatcher(const Roll::Range range, const FurPatternId id)
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

Aliases::String ScaleColor::getLabel() const
{
    return LABEL_;
}

ScaleColorMatcher createScaleColorMatcher(const Roll::Range range, const ScaleColorId id)
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

Aliases::String HornType::getLabel() const
{
    return LABEL_;
}

HornTypeMatcher createHornTypeMatcher(const Roll::Range range, const HornTypeId id)
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

Race::Race(const RaceId &id,
           const Aliases::String &displayName,
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

Aliases::String Race::getLabel() const
{
    return LABEL_;
}

Archetype Race::rollArchetype() const
{
    return archetypeRollList_.rollForItem();
}

SkinColor Race::rollSkinColor() const
{
    return skinColorRollList_.rollForItem();
}

HairColor Race::rollHairColor() const
{
    return hairColorRollList_.rollForItem();
}

EyeColor Race::rollEyeColor() const
{
    return eyeColorRollList_.rollForItem();
}

FurPattern Race::rollFurPattern() const
{
    return furPatternRollList_.rollForItem();
}

ScaleColor Race::rollScaleColor() const
{
    return scaleColorRollList_.rollForItem();
}

HornType Race::rollHornType() const
{
    return hornTypeRollList_.rollForItem();
}

const RaceRollList &getRaceRollList()
{
    static const auto nord
        = Race{r_nord,
               "Nord",
               createArchetypeRollList(MageRange(1, 60), WarriorRange(61, 80), ThiefRange(81, 100)),
               SkinColorRollList{createSkinColorMatcher(Roll::Range(1, 70), sc_pale),
                                 createSkinColorMatcher(Roll::Range(71, 95), sc_fair),
                                 createSkinColorMatcher(Roll::Range(96, 100), sc_tan)},
               HairColorRollList{createHairColorMatcher(Roll::Range(1, 60), hc_blonde),
                                 createHairColorMatcher(Roll::Range(61, 90), hc_brown),
                                 createHairColorMatcher(Roll::Range(91, 97), hc_red),
                                 createHairColorMatcher(Roll::Range(98, 100), hc_black)},
               EyeColorRollList{createEyeColorMatcher(Roll::Range(1, 50), ec_blue),
                                createEyeColorMatcher(Roll::Range(51, 80), ec_green),
                                createEyeColorMatcher(Roll::Range(81, 90), ec_grey),
                                createEyeColorMatcher(Roll::Range(91, 95), ec_brown),
                                createEyeColorMatcher(Roll::Range(96, 100), ec_hazel)},
               FurPatternRollList{createFurPatternMatcher(Roll::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Roll::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Roll::Range(1, 100), ht_null)}};
    static const auto imperial
        = Race{r_imperial,
               "Imperial",
               createArchetypeRollList(MageRange(1, 40), WarriorRange(41, 60), ThiefRange(61, 100)),
               SkinColorRollList{createSkinColorMatcher(Roll::Range(1, 50), sc_tan),
                                 createSkinColorMatcher(Roll::Range(51, 80), sc_fair),
                                 createSkinColorMatcher(Roll::Range(81, 95), sc_pale),
                                 createSkinColorMatcher(Roll::Range(96, 100), sc_dark)},
               HairColorRollList{createHairColorMatcher(Roll::Range(1, 40), hc_brown),
                                 createHairColorMatcher(Roll::Range(41, 75), hc_black),
                                 createHairColorMatcher(Roll::Range(76, 90), hc_blonde),
                                 createHairColorMatcher(Roll::Range(91, 100), hc_red)},
               EyeColorRollList{createEyeColorMatcher(Roll::Range(1, 60), ec_brown),
                                createEyeColorMatcher(Roll::Range(61, 80), ec_hazel),
                                createEyeColorMatcher(Roll::Range(81, 95), ec_blue),
                                createEyeColorMatcher(Roll::Range(96, 100), ec_green)},
               FurPatternRollList{createFurPatternMatcher(Roll::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Roll::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Roll::Range(1, 100), ht_null)}};
    static const auto breton
        = Race{r_breton,
               "Breton",
               createArchetypeRollList(MageRange(1, 25), WarriorRange(26, 50), ThiefRange(51, 100)),
               SkinColorRollList{
                   createSkinColorMatcher(Roll::Range(1, 40), sc_pale),
                   createSkinColorMatcher(Roll::Range(41, 90), sc_fair),
                   createSkinColorMatcher(Roll::Range(91, 100), sc_tan),
               },
               HairColorRollList{createHairColorMatcher(Roll::Range(1, 40), hc_brown),
                                 createHairColorMatcher(Roll::Range(41, 70), hc_black),
                                 createHairColorMatcher(Roll::Range(71, 90), hc_blonde),
                                 createHairColorMatcher(Roll::Range(91, 100), hc_red)},
               EyeColorRollList{createEyeColorMatcher(Roll::Range(1, 40), ec_blue),
                                createEyeColorMatcher(Roll::Range(41, 70), ec_green),
                                createEyeColorMatcher(Roll::Range(71, 80), ec_grey),
                                createEyeColorMatcher(Roll::Range(81, 90), ec_brown),
                                createEyeColorMatcher(Roll::Range(91, 100), ec_hazel)},
               FurPatternRollList{createFurPatternMatcher(Roll::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Roll::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Roll::Range(1, 100), ht_null)}};
    static const auto redguard
        = Race{r_redguard,
               "Redguard",
               createArchetypeRollList(MageRange(1, 60), WarriorRange(61, 80), ThiefRange(81, 100)),
               SkinColorRollList{
                   createSkinColorMatcher(Roll::Range(1, 60), sc_dark),
                   createSkinColorMatcher(Roll::Range(61, 90), sc_tan),
                   createSkinColorMatcher(Roll::Range(91, 100), sc_olive),
               },
               HairColorRollList{createHairColorMatcher(Roll::Range(1, 70), hc_black),
                                 createHairColorMatcher(Roll::Range(71, 90), hc_brown),
                                 createHairColorMatcher(Roll::Range(91, 100), hc_dark_red)},
               EyeColorRollList{createEyeColorMatcher(Roll::Range(1, 60), ec_brown),
                                createEyeColorMatcher(Roll::Range(61, 80), ec_black),
                                createEyeColorMatcher(Roll::Range(81, 95), ec_amber),
                                createEyeColorMatcher(Roll::Range(96, 100), ec_hazel)},
               FurPatternRollList{createFurPatternMatcher(Roll::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Roll::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Roll::Range(1, 100), ht_null)}};
    static const auto dunmer
        = Race(r_dunmer,
               "Dunmer (Dark Elf)",
               createArchetypeRollList(MageRange(1, 35), WarriorRange(36, 65), ThiefRange(66, 100)),
               SkinColorRollList{createSkinColorMatcher(Roll::Range(1, 70), sc_ashen_grey),
                                 createSkinColorMatcher(Roll::Range(71, 95), sc_dark_grey),
                                 createSkinColorMatcher(Roll::Range(96, 100), sc_near_black)},
               HairColorRollList{createHairColorMatcher(Roll::Range(1, 80), hc_black),
                                 createHairColorMatcher(Roll::Range(81, 95), hc_dark_red),
                                 createHairColorMatcher(Roll::Range(96, 100), hc_grey)},
               EyeColorRollList{createEyeColorMatcher(Roll::Range(1, 60), ec_red),
                                createEyeColorMatcher(Roll::Range(61, 90), ec_amber),
                                createEyeColorMatcher(Roll::Range(91, 95), ec_orange),
                                createEyeColorMatcher(Roll::Range(96, 100), ec_brown)},
               FurPatternRollList{createFurPatternMatcher(Roll::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Roll::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Roll::Range(1, 100), ht_null)});
    static const auto altmer
        = Race{r_altmer,
               "Altmer (High Elf)",
               createArchetypeRollList(MageRange(1, 15), WarriorRange(16, 30), ThiefRange(31, 100)),
               SkinColorRollList{
                   createSkinColorMatcher(Roll::Range(1, 70), sc_fair),
                   createSkinColorMatcher(Roll::Range(71, 90), sc_pale),
                   createSkinColorMatcher(Roll::Range(91, 100), sc_golden),
               },
               HairColorRollList{createHairColorMatcher(Roll::Range(1, 60), hc_golden_blonde),
                                 createHairColorMatcher(Roll::Range(61, 90), hc_silver_white),
                                 createHairColorMatcher(Roll::Range(91, 100), hc_light_brown)},
               EyeColorRollList{createEyeColorMatcher(Roll::Range(1, 70), ec_gold),
                                createEyeColorMatcher(Roll::Range(71, 90), ec_blue),
                                createEyeColorMatcher(Roll::Range(91, 95), ec_green),
                                createEyeColorMatcher(Roll::Range(96, 100), ec_amber)},
               FurPatternRollList{createFurPatternMatcher(Roll::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Roll::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Roll::Range(1, 100), ht_null)}};
    static const auto bosmer
        = Race{r_bosmer,
               "Bosmer (Wood Elf)",
               createArchetypeRollList(MageRange(1, 35), WarriorRange(36, 85), ThiefRange(86, 100)),
               SkinColorRollList{
                   createSkinColorMatcher(Roll::Range(1, 50), sc_tan),
                   createSkinColorMatcher(Roll::Range(51, 80), sc_olive),
                   createSkinColorMatcher(Roll::Range(81, 100), sc_brown),
               },
               HairColorRollList{createHairColorMatcher(Roll::Range(1, 60), hc_brown),
                                 createHairColorMatcher(Roll::Range(61, 80), hc_black),
                                 createHairColorMatcher(Roll::Range(81, 90), hc_green),
                                 createHairColorMatcher(Roll::Range(91, 95), hc_blonde),
                                 createHairColorMatcher(Roll::Range(96, 100), hc_red)},
               EyeColorRollList{createEyeColorMatcher(Roll::Range(1, 60), ec_green),
                                createEyeColorMatcher(Roll::Range(61, 80), ec_hazel),
                                createEyeColorMatcher(Roll::Range(81, 95), ec_brown),
                                createEyeColorMatcher(Roll::Range(96, 100), ec_amber)},
               FurPatternRollList{createFurPatternMatcher(Roll::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Roll::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Roll::Range(1, 100), ht_null)}};
    static const auto orsimer
        = Race{r_orsimer,
               "Orsimer (Orc)",
               createArchetypeRollList(MageRange(1, 65), WarriorRange(66, 80), ThiefRange(81, 100)),
               SkinColorRollList{
                   createSkinColorMatcher(Roll::Range(1, 60), sc_olive),
                   createSkinColorMatcher(Roll::Range(61, 90), sc_dark_green),
                   createSkinColorMatcher(Roll::Range(91, 100), sc_dark),
               },
               HairColorRollList{createHairColorMatcher(Roll::Range(1, 70), hc_black),
                                 createHairColorMatcher(Roll::Range(71, 90), hc_dark_brown),
                                 createHairColorMatcher(Roll::Range(91, 95), hc_grey),
                                 createHairColorMatcher(Roll::Range(96, 100), hc_red)},
               EyeColorRollList{createEyeColorMatcher(Roll::Range(1, 60), ec_brown),
                                createEyeColorMatcher(Roll::Range(61, 80), ec_red),
                                createEyeColorMatcher(Roll::Range(81, 90), ec_yellow),
                                createEyeColorMatcher(Roll::Range(91, 95), ec_amber),
                                createEyeColorMatcher(Roll::Range(96, 100), ec_orange)},
               FurPatternRollList{createFurPatternMatcher(Roll::Range(1, 100), fp_nil)},
               ScaleColorRollList{createScaleColorMatcher(Roll::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Roll::Range(1, 100), ht_null)}};
    static const auto khajiit
        = Race{r_khajiit,
               "Khajiit",
               createArchetypeRollList(MageRange(1, 35), WarriorRange(36, 75), ThiefRange(76, 100)),
               SkinColorRollList{createSkinColorMatcher(Roll::Range(1, 100), sc_nil)},
               HairColorRollList{createHairColorMatcher(Roll::Range(1, 30), hc_brown),
                                 createHairColorMatcher(Roll::Range(31, 55), hc_black),
                                 createHairColorMatcher(Roll::Range(56, 75), hc_grey),
                                 createHairColorMatcher(Roll::Range(76, 90), hc_white),
                                 createHairColorMatcher(Roll::Range(91, 100), hc_orange)},
               EyeColorRollList{createEyeColorMatcher(Roll::Range(1, 40), ec_amber),
                                createEyeColorMatcher(Roll::Range(41, 70), ec_green),
                                createEyeColorMatcher(Roll::Range(71, 90), ec_yellow),
                                createEyeColorMatcher(Roll::Range(91, 95), ec_blue),
                                createEyeColorMatcher(Roll::Range(96, 100), ec_brown)},
               FurPatternRollList{
                   createFurPatternMatcher(Roll::Range(1, 40), fp_striped),
                   createFurPatternMatcher(Roll::Range(41, 70), fp_spotted),
                   createFurPatternMatcher(Roll::Range(71, 90), fp_solid),
                   createFurPatternMatcher(Roll::Range(91, 100), fp_tabby),
               },
               ScaleColorRollList{createScaleColorMatcher(Roll::Range(1, 100), scl_null)},
               HornTypeRollList{createHornTypeMatcher(Roll::Range(1, 100), ht_null)}};
    static const auto argonian
        = Race{r_argonian,
               "Argonian",
               createArchetypeRollList(MageRange(1, 40), WarriorRange(41, 80), ThiefRange(81, 100)),
               SkinColorRollList{createSkinColorMatcher(Roll::Range(1, 100), sc_nil)},
               HairColorRollList{createHairColorMatcher(Roll::Range(1, 100), hc_nil)},
               EyeColorRollList{createEyeColorMatcher(Roll::Range(1, 40), ec_yellow),
                                createEyeColorMatcher(Roll::Range(41, 70), ec_red),
                                createEyeColorMatcher(Roll::Range(71, 85), ec_orange),
                                createEyeColorMatcher(Roll::Range(86, 95), ec_green),
                                createEyeColorMatcher(Roll::Range(96, 100), ec_amber)},
               FurPatternRollList{createFurPatternMatcher(Roll::Range(1, 100), fp_nil)},
               ScaleColorRollList{
                   createScaleColorMatcher(Roll::Range(1, 50), scl_dark_green),
                   createScaleColorMatcher(Roll::Range(51, 80), scl_olive),
                   createScaleColorMatcher(Roll::Range(81, 95), scl_brown),
                   createScaleColorMatcher(Roll::Range(96, 100), scl_grey),
               },
               HornTypeRollList{createHornTypeMatcher(Roll::Range(1, 35), ht_none),
                                createHornTypeMatcher(Roll::Range(36, 60), ht_spiked),
                                createHornTypeMatcher(Roll::Range(61, 85), ht_curved),
                                createHornTypeMatcher(Roll::Range(86, 100), ht_both)}};
    static const auto list = RaceRollList{RaceRollMatcher(Roll::Range(1, 42), nord),
                                          RaceRollMatcher(Roll::Range(43, 55), imperial),
                                          RaceRollMatcher(Roll::Range(56, 67), breton),
                                          RaceRollMatcher(Roll::Range(68, 75), dunmer),
                                          RaceRollMatcher(Roll::Range(76, 81), altmer),
                                          RaceRollMatcher(Roll::Range(82, 87), orsimer),
                                          RaceRollMatcher(Roll::Range(88, 92), redguard),
                                          RaceRollMatcher(Roll::Range(93, 95), bosmer),
                                          RaceRollMatcher(Roll::Range(96, 98), khajiit),
                                          RaceRollMatcher(Roll::Range(99, 100), argonian)};
    return list;
}

Attribute::Attribute(const Aliases::String &label,
                     const Aliases::Uint8 &id,
                     const Aliases::String &displayName)
    : label_(label)
    , id_(id)
    , displayName_(displayName)
{}

Attribute::Attribute(const Attribute &attr)
    : label_(attr.label_)
    , id_(attr.id_)
    , displayName_(attr.displayName_)
{}

Attribute::Attribute()
    : label_("NULL")
    , id_(0)
    , displayName_("NULL")
{}

Aliases::String Attribute::getDisplayName() const
{
    return displayName_;
}

Aliases::Uint8 Attribute::getId() const
{
    return id_;
}

Aliases::String Attribute::getLabel() const
{
    return label_;
}

CharacterSheet::CharacterSheet()
    : attrVector_(AttrVector())
{}

inline CharacterSheet::Iterator CharacterSheet::begin()
{
    return attrVector_.begin();
}

inline CharacterSheet::Iterator CharacterSheet::end()
{
    return attrVector_.end();
}

void CharacterSheet::insertAttribute(const Attribute attr)
{
    this->attrVector_.push_back(attr);
}

Aliases::String CharacterSheet::toText()
{
    Aliases::String character_text = "<table>";

    for (auto i = this->attrVector_.begin(); i != this->attrVector_.end(); i++) {
        Attribute attr = *i;
        character_text += "<tr><td><b>" + attr.getLabel() + "</b></td><td>" + attr.getDisplayName()
                          + "</td></tr>";
    }
    character_text += "<table>";
    return character_text;
}

Archetype _rollArchetype(const BirthSign &birthSign, const Race &race)
{
    static const Aliases::String logFormat
        = "Archetype based on [%1] [%2] so the archetype is [%3]";
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

CharacterSheet generateCharacterSheet()
{
    CharacterSheet sheet = CharacterSheet();

    const RaceRollList &raceRollList = getRaceRollList();
    const Race &race = raceRollList.rollForItem();

    sheet.insertAttribute(createAttribute(race));

    const BirthSignsRollList &birthSignRollList = getBirthSignsRollList();
    const BirthSign &birthSign = birthSignRollList.rollForItem();

    sheet.insertAttribute(createAttribute(birthSign));

    const Sex sex = rollForSex();

    sheet.insertAttribute(createAttribute(sex));

    const SexualitiesRollList sexualitiesRollList = createSexualitiesRollList(sex.getId());
    const Sexuality &sexuality = sexualitiesRollList.rollForItem();

    sheet.insertAttribute(createAttribute(sexuality));

    const bool isArchetypeBasedOnBirthSign = birthSign.rollIfArchetypeBasedOnBirthSign();
    const Archetype archetype = isArchetypeBasedOnBirthSign
                                    ? createArchetype(birthSign.getArchetypeId())
                                    : race.rollArchetype();
    sheet.insertAttribute(createAttribute(archetype));

    const RpgClassRollList rpgClassRollList = createRpgClassRollList(archetype.getId());
    const RpgClass rpgClass = rpgClassRollList.rollForItem();

    sheet.insertAttribute(createAttribute(rpgClass));

    const SkinColor skinColor = race.rollSkinColor();
    if (skinColor.getId() != sc_nil) {
        sheet.insertAttribute(createAttribute(skinColor));
    }

    const HairColor hairColor = race.rollHairColor();
    if (hairColor.getId() != hc_nil) {
        sheet.insertAttribute(createAttribute(hairColor));
    }

    const FurPattern furPattern = race.rollFurPattern();
    if (furPattern.getId() != fp_nil) {
        sheet.insertAttribute(createAttribute(furPattern));
    }

    const ScaleColor scaleColor = race.rollScaleColor();
    if (scaleColor.getId() != scl_null) {
        sheet.insertAttribute(createAttribute(scaleColor));
    }

    const HornType hornType = race.rollHornType();
    if (hornType.getId() != ht_null) {
        sheet.insertAttribute(createAttribute(hornType));
    }

    const EyeColor eyeColor = race.rollEyeColor();
    sheet.insertAttribute(createAttribute(eyeColor));

    return sheet;
}

} // namespace CharGen
