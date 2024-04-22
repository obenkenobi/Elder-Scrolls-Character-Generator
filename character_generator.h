#ifndef CHARACTER_GENERATOR_H
#define CHARACTER_GENERATOR_H

#include <stdexcept>
#include <utility>
#include "roll.h"
#include "types_aliases.h"

namespace char_gen
{
// Archetype
// -----------------------------------------------------------------------------
enum archetype_id_t { a_mage, a_thief, a_warrior, a_any };

using archetype_t = roll::roll_item_t<archetype_id_t>;

archetype_t create_archetype(const archetype_id_t id)
{
    switch (id)
    {
    case a_mage:
        return archetype_t(a_mage, "Mage");
    case a_warrior:
        return archetype_t(a_mage, "Warrior");
    case a_thief:
        return archetype_t(a_thief, "Thief");
    case a_any:
        break;
    }
    return archetype_t(a_any, "Any");
}

using archetype_roll_list_t = roll::roll_array_t<archetype_t, 3>;
using archetype_roll_matcher_t = roll::roll_matcher<archetype_t>;
using mage_range_t = roll::range_t;
using warrior_range_t = roll::range_t;
using thief_range_t = roll::range_t;

archetype_roll_list_t
create_archetype_roll_list(const mage_range_t mage_range,
                           const warrior_range_t warrior_range,
                           const thief_range_t thief_range)
{
    static auto mage = create_archetype(a_mage);
    static auto warrior = create_archetype(a_warrior);
    static auto thief = create_archetype(a_thief);

    return archetype_roll_list_t({
        archetype_roll_matcher_t(mage_range, mage),
        archetype_roll_matcher_t(warrior_range, warrior),
        archetype_roll_matcher_t(thief_range, thief),
    });
}

//  RPG Class
//  ------------------------------------------------------------------------------

enum rpg_class_id_t
{
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

using rpg_class_t = roll::roll_item_t<rpg_class_id_t>;

using rpg_class_roll_list_t = roll::roll_array_t<rpg_class_t, 7>;
using rpg_class_roll_matcher_t = roll::roll_matcher<rpg_class_t>;

const rpg_class_roll_list_t& get_warrior_class_roll_list()
{
    static const auto archer = rpg_class_t(c_archer, "Archer");
    static const auto barbarian = rpg_class_t(c_barbarian, "Barbarian");
    static const auto crusader = rpg_class_t(c_crusader, "Crusader");
    static const auto knight = rpg_class_t(c_knight, "Knight");
    static const auto rogue = rpg_class_t(c_rogue, "Rogue");
    static const auto scout = rpg_class_t(c_scout, "Scout");
    static const auto warrior = rpg_class_t(c_warrior, "Warrior");
    static const auto list = rpg_class_roll_list_t({
        rpg_class_roll_matcher_t(roll::range_t(1, 14), archer),
        rpg_class_roll_matcher_t(roll::range_t(15, 28), barbarian),
        rpg_class_roll_matcher_t(roll::range_t(29, 42), crusader),
        rpg_class_roll_matcher_t(roll::range_t(43, 56), knight),
        rpg_class_roll_matcher_t(roll::range_t(57, 70), rogue),
        rpg_class_roll_matcher_t(roll::range_t(71, 84), scout),
        rpg_class_roll_matcher_t(roll::range_t(85, 100), warrior),
    });
    return list;
}

const rpg_class_roll_list_t& get_thief_class_roll_list()
{
    static const auto acrobat = rpg_class_t(c_acrobat, "Acrobat");
    static const auto agent = rpg_class_t(c_agent, "Agent");
    static const auto assassin = rpg_class_t(c_assassin, "Assassin");
    static const auto bard = rpg_class_t(c_bard, "Bard");
    static const auto monk = rpg_class_t(c_monk, "Monk");
    static const auto pilgrim = rpg_class_t(c_pilgrim, "Pilgrim");
    static const auto thief = rpg_class_t(c_thief, "Thief");
    static const auto list = rpg_class_roll_list_t({
        rpg_class_roll_matcher_t(roll::range_t(1, 14), acrobat),
        rpg_class_roll_matcher_t(roll::range_t(15, 28), agent),
        rpg_class_roll_matcher_t(roll::range_t(29, 42), assassin),
        rpg_class_roll_matcher_t(roll::range_t(43, 56), bard),
        rpg_class_roll_matcher_t(roll::range_t(57, 70), monk),
        rpg_class_roll_matcher_t(roll::range_t(71, 84), pilgrim),
        rpg_class_roll_matcher_t(roll::range_t(85, 100), thief),
    });
    return list;
}

const rpg_class_roll_list_t& get_mage_class_roll_list()
{
    static const auto battle_mage = rpg_class_t(c_battle_mage, "Battle Mage");
    static const auto healer = rpg_class_t(c_healer, "Healer");
    static const auto mage = rpg_class_t(c_mage, "Mage");
    static const auto night_blade = rpg_class_t(c_night_blade, "Night Blade");
    static const auto sorcerer = rpg_class_t(c_sorcerer, "Sorcerer");
    static const auto spell_sword = rpg_class_t(c_spell_sword, "Spell Sword");
    static const auto witch_hunter = rpg_class_t(c_witch_hunter, "Witch Hunter");
    static const auto list = rpg_class_roll_list_t({
        rpg_class_roll_matcher_t(roll::range_t(1, 14), battle_mage),
        rpg_class_roll_matcher_t(roll::range_t(15, 28), healer),
        rpg_class_roll_matcher_t(roll::range_t(29, 42), mage),
        rpg_class_roll_matcher_t(roll::range_t(43, 56), night_blade),
        rpg_class_roll_matcher_t(roll::range_t(57, 70), sorcerer),
        rpg_class_roll_matcher_t(roll::range_t(71, 84), spell_sword),
        rpg_class_roll_matcher_t(roll::range_t(85, 100), witch_hunter),
    });
    return list;
}

const rpg_class_roll_list_t&
create_rpg_class_roll_list(const archetype_id_t archetype_id)
{
    switch (archetype_id)
    {
    case a_warrior:
        return get_warrior_class_roll_list();
    case a_thief:
        return get_thief_class_roll_list();
    case a_mage:
        return get_mage_class_roll_list();
    case a_any:
        break;
    }
    throw std::invalid_argument(
        "Only archetype ids of warrior, thief, and mage allowed");
}

// Birth Signs
// ------------------------------------------------------------------------------------------------------------
enum birth_sign_id_t
{
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

class birth_sign_t : public roll::roll_item_t<birth_sign_id_t>
{
public:
    birth_sign_t(const birth_sign_id_t i_id, const archetype_id_t archetype_id,
                 const type_aliases::string_t& i_display_name)
        : roll_item_t(i_id, i_display_name), archetype_id_(archetype_id)
    {
    }

    bool roll_if_archetype_based_on_birth_sign() const
    {
        if (this->id_ != b_serpent)
        {
            const roll::r_uint_t roll_num = roll::roll_rand_number();
            return roll::range_t(1, 60).in_roll_range_inclusive(roll_num);
        }
        return false;
    }

    archetype_id_t get_archetype_id() const { return archetype_id_; }

private:
    archetype_id_t archetype_id_;
};

using birth_signs_roll_list_t = roll::roll_array_t<birth_sign_t, 13>;
using birth_signs_roll_matcher_t = roll::roll_matcher<birth_sign_t>;

const birth_signs_roll_list_t& get_birth_signs_roll_list()
{
    static const auto ritual = birth_sign_t(b_ritual, a_mage, "The Ritual");
    static const auto lover = birth_sign_t(b_lover, a_thief, "The Lover");
    static const auto lord = birth_sign_t(b_lord, a_warrior, "The Lord");
    static const auto mage = birth_sign_t(b_mage, a_mage, "The Mage");
    static const auto shadow = birth_sign_t(b_shadow, a_thief, "The Shadow");
    static const auto steed = birth_sign_t(b_steed, a_warrior, "The Steed");
    static const auto apprentice =
        birth_sign_t(b_apprentice, a_mage, "The Apprentice");
    static const auto warrior = birth_sign_t(b_warrior, a_warrior, "The Warrior");
    static const auto lady = birth_sign_t(b_lady, a_thief, "The Lady");
    static const auto tower = birth_sign_t(b_tower, a_thief, "The Tower");
    static const auto atronach = birth_sign_t(b_atronach, a_mage, "The Atronach");
    static const auto thief = birth_sign_t(b_thief, a_thief, "The Thief");
    static const auto serpent = birth_sign_t(b_serpent, a_any, "The Serpent");

    static const auto list = birth_signs_roll_list_t(
        {
            birth_signs_roll_matcher_t(roll::range_t(1, 8), ritual),
            birth_signs_roll_matcher_t(roll::range_t(9, 14), lover),
            birth_signs_roll_matcher_t(roll::range_t(15, 22), lord),
            birth_signs_roll_matcher_t(roll::range_t(23, 30), mage),
            birth_signs_roll_matcher_t(roll::range_t(31, 38), shadow),
            birth_signs_roll_matcher_t(roll::range_t(39, 46), steed),
            birth_signs_roll_matcher_t(roll::range_t(47, 55), apprentice),
            birth_signs_roll_matcher_t(roll::range_t(56, 63), warrior),
            birth_signs_roll_matcher_t(roll::range_t(64, 72), lady),
            birth_signs_roll_matcher_t(roll::range_t(73, 81), tower),
            birth_signs_roll_matcher_t(roll::range_t(82, 90), atronach),
            birth_signs_roll_matcher_t(roll::range_t(91, 99), thief),
            birth_signs_roll_matcher_t(roll::range_t(100, 100), serpent)
        });
    return list;
};

// Sex
// ------------------------------------------------------------------------------------------------------------

enum sex_id_t { male, female };

using sex_t = roll::roll_item_t<sex_id_t>;

sex_t roll_for_sex()
{
    const roll::r_uint_t roll_num = roll::roll_rand_number();
    return roll::range_t(1, 50).in_roll_range_inclusive(roll_num)
               ? sex_t(male, "Male")
               : sex_t(female, "Female");
}

// Sexuality
// ------------------------------------------------------------------------------------------------------------
enum sexuality_id_t { heterosexual, bisexual, homosexual };

using sexuality_t = roll::roll_item_t<sexuality_id_t>;

using sexualities_roll_list_t = roll::roll_array_t<sexuality_t, 3>;
using sexualities_roll_matcher_t = roll::roll_matcher<sexuality_t>;

const sexualities_roll_list_t&
create_sexualities_roll_list(const sex_id_t sex_id)
{
    static const auto hetero = sexuality_t(heterosexual, "Heterosexual");
    static const auto bi = sexuality_t(bisexual, "Bisexual");
    static const auto homo = sexuality_t(homosexual, "Homosexual");
    static const auto female_list = sexualities_roll_list_t({
        sexualities_roll_matcher_t(roll::range_t(1, 67), hetero),
        sexualities_roll_matcher_t(roll::range_t(68, 90), bi),
        sexualities_roll_matcher_t(roll::range_t(91, 100), homo),
    });
    static const auto male_list = sexualities_roll_list_t({
        sexualities_roll_matcher_t(roll::range_t(1, 72), hetero),
        sexualities_roll_matcher_t(roll::range_t(73, 92), bi),
        sexualities_roll_matcher_t(roll::range_t(93, 100), homo),
    });
    if (sex_id == female)
    {
        return female_list;
    }
    return male_list;
}

// Skin Color
// ------------------------------------------------------------------------------------------------------------------
enum skin_color_id_t
{
    sc_null,
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

using skin_color_t = roll::roll_item_t<skin_color_id_t>;

using skin_color_roll_list_t = roll::roll_vector_t<skin_color_t>;
using skin_color_matcher_t = roll::roll_matcher<skin_color_t>;

skin_color_matcher_t
create_skin_color_matcher(const roll::range_t range,
                          const skin_color_id_t& skin_color_id)
{
    static const auto null = skin_color_t(sc_null, "N/A");
    static const auto pale = skin_color_t(sc_pale, "Pale");
    static const auto fair = skin_color_t(sc_fair, "Fair");
    static const auto tan = skin_color_t(sc_tan, "Tan");
    static const auto dark = skin_color_t(sc_dark, "Dark");
    static const auto golden = skin_color_t(sc_golden, "Golden");
    static const auto ashen_grey = skin_color_t(sc_ashen_grey, "Ashen Grey");
    static const auto dark_grey = skin_color_t(sc_dark_grey, "Dark Grey");
    static const auto near_black = skin_color_t(sc_near_black, "Near Black");
    static const auto brown = skin_color_t(sc_brown, "Brown");
    static const auto olive = skin_color_t(sc_olive, "Olive");
    static const auto dark_green = skin_color_t(sc_dark_green, "Dark Green");
    switch (skin_color_id)
    {
    case sc_pale:
        return skin_color_matcher_t{range, pale};
    case sc_fair:
        return skin_color_matcher_t{range, fair};
    case sc_tan:
        return skin_color_matcher_t{range, tan};
    case sc_dark:
        return skin_color_matcher_t{range, dark};
    case sc_golden:
        return skin_color_matcher_t{range, golden};
    case sc_ashen_grey:
        return skin_color_matcher_t{range, ashen_grey};
    case sc_dark_grey:
        return skin_color_matcher_t{range, dark_grey};
    case sc_near_black:
        return skin_color_matcher_t{range, near_black};
    case sc_brown:
        return skin_color_matcher_t{range, brown};
    case sc_olive:
        return skin_color_matcher_t{range, olive};
    case sc_dark_green:
        return skin_color_matcher_t{range, dark_green};
    case sc_null:
        return skin_color_matcher_t{range, null};
    }
    return skin_color_matcher_t{range, null};
}

// Hair Color
// ------------------------------------------------------------------------------------------------------------------
enum hair_color_id_t
{
    hc_null,
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

using hair_color_t = roll::roll_item_t<hair_color_id_t>;

using hair_color_roll_list_t = roll::roll_vector_t<hair_color_t>;
using hair_color_matcher_t = roll::roll_matcher<hair_color_t>;

hair_color_matcher_t create_hair_color_matcher(const roll::range_t range,
                                               const hair_color_id_t id)
{
    static const auto null = hair_color_t(hc_null, "N/A");
    static const auto blonde = hair_color_t(hc_blonde, "Blonde");
    static const auto brown = hair_color_t(hc_brown, "Brown");
    static const auto red = hair_color_t(hc_red, "Red");
    static const auto black = hair_color_t(hc_black, "Black");
    static const auto dark_red = hair_color_t(hc_dark_red, "Dark Red");
    static const auto grey = hair_color_t(hc_grey, "Grey");
    static const auto golden_blonde =
        hair_color_t(hc_golden_blonde, "Golden Blonde");
    static const auto silver_white =
        hair_color_t(hc_silver_white, "Silver White");
    static const auto light_brown = hair_color_t(hc_light_brown, "Light Brown");
    static const auto green = hair_color_t(hc_green, "Green");
    static const auto dark_brown = hair_color_t(hc_dark_brown, "Dark Brown");
    static const auto white = hair_color_t(hc_white, "White");
    static const auto orange = hair_color_t(hc_orange, "Orange");

    switch (id)
    {
    case hc_blonde:
        return hair_color_matcher_t{range, blonde};
    case hc_brown:
        return hair_color_matcher_t{range, brown};
    case hc_red:
        return hair_color_matcher_t{range, red};
    case hc_black:
        return hair_color_matcher_t{range, black};
    case hc_dark_red:
        return hair_color_matcher_t{range, dark_red};
    case hc_grey:
        return hair_color_matcher_t{range, grey};
    case hc_golden_blonde:
        return hair_color_matcher_t{range, golden_blonde};
    case hc_silver_white:
        return hair_color_matcher_t{range, silver_white};
    case hc_light_brown:
        return hair_color_matcher_t{range, light_brown};
    case hc_green:
        return hair_color_matcher_t{range, green};
    case hc_dark_brown:
        return hair_color_matcher_t{range, dark_brown};
    case hc_white:
        return hair_color_matcher_t{range, white};
    case hc_orange:
        return hair_color_matcher_t{range, orange};
    case hc_null:
        return hair_color_matcher_t{range, null};
    }
    return hair_color_matcher_t{range, null};
}

// Eye Color --------------------------------------------------------

enum eye_color_id_t
{
    ec_null,
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

using eye_color_t = roll::roll_item_t<eye_color_id_t>;

using eye_color_roll_list_t = roll::roll_vector_t<eye_color_t>;
using eye_color_matcher_t = roll::roll_matcher<eye_color_t>;

eye_color_matcher_t create_eye_color_matcher(const roll::range_t range,
                                             const eye_color_id_t id)
{
    static const auto blue = eye_color_t(ec_blue, "Blue");
    static const auto green = eye_color_t(ec_green, "Green");
    static const auto grey = eye_color_t(ec_grey, "Grey");
    static const auto brown = eye_color_t(ec_brown, "Brown");
    static const auto black = eye_color_t(ec_black, "Black");
    static const auto hazel = eye_color_t(ec_hazel, "Hazel");
    static const auto amber = eye_color_t(ec_amber, "Amber");
    static const auto red = eye_color_t(ec_red, "Red");
    static const auto orange = eye_color_t(ec_orange, "Orange");
    static const auto gold = eye_color_t(ec_gold, "Gold");
    static const auto yellow = eye_color_t(ec_yellow, "Yellow");
    static const auto null = eye_color_t(ec_null, "N/A");

    switch (id)
    {
    case ec_blue:
        return eye_color_matcher_t{range, blue};
    case ec_green:
        return eye_color_matcher_t{range, green};
    case ec_grey:
        return eye_color_matcher_t{range, grey};
    case ec_brown:
        return eye_color_matcher_t{range, brown};
    case ec_black:
        return eye_color_matcher_t{range, black};
    case ec_hazel:
        return eye_color_matcher_t{range, hazel};
    case ec_amber:
        return eye_color_matcher_t{range, amber};
    case ec_red:
        return eye_color_matcher_t{range, red};
    case ec_orange:
        return eye_color_matcher_t{range, orange};
    case ec_gold:
        return eye_color_matcher_t{range, gold};
    case ec_yellow:
        return eye_color_matcher_t{range, yellow};
    case ec_null:
        return eye_color_matcher_t{range, null};
    }
    return eye_color_matcher_t{range, null};
}

// Fur Pattern --------------------------------------------------------
enum fur_pattern_id_t { fp_null, fp_striped, fp_spotted, fp_solid, fp_tabby };

using fur_pattern_t = roll::roll_item_t<fur_pattern_id_t>;

using fur_pattern_roll_list_t = roll::roll_vector_t<fur_pattern_t>;
using fur_pattern_matcher_t = roll::roll_matcher<fur_pattern_t>;

fur_pattern_matcher_t create_fur_pattern_matcher(const roll::range_t range,
                                                 const fur_pattern_id_t id)
{
    static const auto striped = fur_pattern_t(fp_striped, "Striped");
    static const auto spotted = fur_pattern_t(fp_spotted, "Spotted");
    static const auto solid = fur_pattern_t(fp_solid, "Solid");
    static const auto tabby = fur_pattern_t(fp_tabby, "Tabby");
    static const auto null = fur_pattern_t(fp_null, "N/A");

    switch (id)
    {
    case fp_striped:
        return fur_pattern_matcher_t{range, striped};
    case fp_spotted:
        return fur_pattern_matcher_t{range, spotted};
    case fp_solid:
        return fur_pattern_matcher_t{range, solid};
    case fp_tabby:
        return fur_pattern_matcher_t{range, tabby};
    case fp_null:
        return fur_pattern_matcher_t{range, null};
    }
    return fur_pattern_matcher_t{range, null};
}

// Scale Color --------------------------------------------------------
enum scale_color_id_t
{
    scl_null,
    scl_dark_green,
    scl_olive,
    scl_brown,
    scl_grey
};

using scale_color_t = roll::roll_item_t<scale_color_id_t>;

using scale_color_roll_list_t = roll::roll_vector_t<scale_color_t>;
using scale_color_matcher_t = roll::roll_matcher<scale_color_t>;

scale_color_matcher_t create_scale_color_matcher(const roll::range_t range,
                                                 const scale_color_id_t id)
{
    static const auto dark_green = scale_color_t(scl_dark_green, "Dark Green");
    static const auto olive = scale_color_t(scl_olive, "Olive");
    static const auto brown = scale_color_t(scl_brown, "Brown");
    static const auto grey = scale_color_t(scl_grey, "Grey");
    static const auto null = scale_color_t(scl_null, "N/A");

    switch (id)
    {
    case scl_dark_green:
        return scale_color_matcher_t{range, dark_green};
    case scl_olive:
        return scale_color_matcher_t{range, olive};
    case scl_brown:
        return scale_color_matcher_t{range, brown};
    case scl_grey:
        return scale_color_matcher_t{range, grey};
    case scl_null:
        return scale_color_matcher_t{range, null};
    }
    return scale_color_matcher_t{range, null};
}

// Horn Type --------------------------------------------------------
enum horn_type_id_t { ht_null, ht_none, ht_spiked, ht_curved, ht_both };

using horn_type_t = roll::roll_item_t<horn_type_id_t>;

using horn_type_roll_list_t = roll::roll_vector_t<horn_type_t>;
using horn_type_matcher_t = roll::roll_matcher<horn_type_t>;

horn_type_matcher_t create_horn_type_matcher(const roll::range_t range,
                                             const horn_type_id_t id)
{
    static const auto none = horn_type_t(ht_none, "None");
    static const auto spiked = horn_type_t(ht_spiked, "Spiked");
    static const auto curved = horn_type_t(ht_curved, "Curved");
    static const auto both = horn_type_t(ht_both, "Spiked & Curved");
    static const auto null = horn_type_t(ht_null, "N/A");

    switch (id)
    {
    case ht_none:
        return horn_type_matcher_t{range, none};
    case ht_spiked:
        return horn_type_matcher_t{range, spiked};
    case ht_curved:
        return horn_type_matcher_t{range, curved};
    case ht_both:
        return horn_type_matcher_t{range, both};
    case ht_null:
        return horn_type_matcher_t{range, null};
    }
    return horn_type_matcher_t{range, null};
}

// Race
// ------------------------------------------------------------------------------------------------------------------
enum race_id_t
{
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

class race_t : public roll::roll_item_t<race_id_t>
{
public:
    race_t(const race_id_t& i_id, const type_aliases::string_t& i_display_name,
           archetype_roll_list_t archetype_roll_list,
           skin_color_roll_list_t skin_color_roll_list,
           hair_color_roll_list_t hair_color_roll_list,
           eye_color_roll_list_t eye_color_roll_list,
           fur_pattern_roll_list_t fur_pattern_roll_list,
           scale_color_roll_list_t scale_color_roll_list,
           horn_type_roll_list_t horn_type_roll_list)
        : roll_item_t(i_id, i_display_name),
        archetype_roll_list_(std::move(archetype_roll_list)),
        skin_color_roll_list_(std::move(skin_color_roll_list)),
        hair_color_roll_list_(std::move(hair_color_roll_list)),
        eye_color_roll_list_(std::move(eye_color_roll_list)),
        fur_pattern_roll_list_(std::move(fur_pattern_roll_list)),
        scale_color_roll_list_(std::move(scale_color_roll_list)),
        horn_type_roll_list_(std::move(horn_type_roll_list))
    {
    }

    archetype_t roll_archetype() const
    {
        return archetype_roll_list_.roll_for_item();
    }

    skin_color_t roll_skin_color() const
    {
        return skin_color_roll_list_.roll_for_item();
    }

    hair_color_t roll_hair_color() const
    {
        return hair_color_roll_list_.roll_for_item();
    }

    eye_color_t roll_eye_color() const
    {
        return eye_color_roll_list_.roll_for_item();
    }

    fur_pattern_t roll_fur_pattern() const
    {
        return fur_pattern_roll_list_.roll_for_item();
    }

    scale_color_t roll_scale_color() const
    {
        return scale_color_roll_list_.roll_for_item();
    }

    horn_type_t roll_horn_type() const
    {
        return horn_type_roll_list_.roll_for_item();
    }

private:
    archetype_roll_list_t archetype_roll_list_;
    skin_color_roll_list_t skin_color_roll_list_;
    hair_color_roll_list_t hair_color_roll_list_;
    eye_color_roll_list_t eye_color_roll_list_;
    fur_pattern_roll_list_t fur_pattern_roll_list_;
    scale_color_roll_list_t scale_color_roll_list_;
    horn_type_roll_list_t horn_type_roll_list_;
};

using race_roll_list_t = roll::roll_array_t<race_t, 10>;
using race_roll_matcher_t = roll::roll_matcher<race_t>;

const race_roll_list_t& get_race_roll_list()
{
    static const auto nord = race_t(
        r_nord, "Nord",
        create_archetype_roll_list(mage_range_t(1, 60), warrior_range_t(61, 80),
                                   thief_range_t(81, 100)),
        skin_color_roll_list_t(
            {
                create_skin_color_matcher(roll::range_t(1, 70), sc_pale),
                create_skin_color_matcher(roll::range_t(71, 95), sc_fair),
                create_skin_color_matcher(roll::range_t(96, 100), sc_tan)
            }),
        hair_color_roll_list_t(
            {
                create_hair_color_matcher(roll::range_t(1, 60), hc_blonde),
                create_hair_color_matcher(roll::range_t(61, 90), hc_brown),
                create_hair_color_matcher(roll::range_t(91, 97), hc_red),
                create_hair_color_matcher(roll::range_t(98, 100), hc_black)
            }),
        eye_color_roll_list_t(
            {
                create_eye_color_matcher(roll::range_t(1, 50), ec_blue),
                create_eye_color_matcher(roll::range_t(51, 80), ec_green),
                create_eye_color_matcher(roll::range_t(81, 90), ec_grey),
                create_eye_color_matcher(roll::range_t(91, 95), ec_brown),
                create_eye_color_matcher(roll::range_t(96, 100), ec_hazel)
            }),
        fur_pattern_roll_list_t({create_fur_pattern_matcher(roll::range_t(1, 100), fp_null)}),
        scale_color_roll_list_t({create_scale_color_matcher(roll::range_t(1, 100), scl_null)}),
        horn_type_roll_list_t({create_horn_type_matcher(roll::range_t(1, 100), ht_null)}));
    static const auto imperial = race_t(
        r_imperial, "Imperial",
        create_archetype_roll_list(mage_range_t(1, 40), warrior_range_t(41, 60),
                                   thief_range_t(61, 100)),
        skin_color_roll_list_t(
            {
                create_skin_color_matcher(roll::range_t(1, 50), sc_tan),
                create_skin_color_matcher(roll::range_t(51, 80), sc_fair),
                create_skin_color_matcher(roll::range_t(81, 95), sc_pale),
                create_skin_color_matcher(roll::range_t(96, 100), sc_dark)
            }),
        hair_color_roll_list_t(
            {
                create_hair_color_matcher(roll::range_t(1, 40), hc_brown),
                create_hair_color_matcher(roll::range_t(41, 75), hc_black),
                create_hair_color_matcher(roll::range_t(76, 90), hc_blonde),
                create_hair_color_matcher(roll::range_t(91, 100), hc_red)
            }),
        eye_color_roll_list_t(
            {
                create_eye_color_matcher(roll::range_t(1, 60), ec_brown),
                create_eye_color_matcher(roll::range_t(61, 80), ec_hazel),
                create_eye_color_matcher(roll::range_t(81, 95), ec_blue),
                create_eye_color_matcher(roll::range_t(96, 100), ec_green)
            }),
        fur_pattern_roll_list_t({create_fur_pattern_matcher(roll::range_t(1, 100), fp_null)}),
        scale_color_roll_list_t({create_scale_color_matcher(roll::range_t(1, 100), scl_null)}),
        horn_type_roll_list_t({create_horn_type_matcher(roll::range_t(1, 100), ht_null)}));
    static const auto breton = race_t(
        r_breton, "Breton",
        create_archetype_roll_list(mage_range_t(1, 25), warrior_range_t(26, 50),
                                   thief_range_t(51, 100)),
        skin_color_roll_list_t({
            create_skin_color_matcher(roll::range_t(1, 40), sc_pale),
            create_skin_color_matcher(roll::range_t(41, 90), sc_fair),
            create_skin_color_matcher(roll::range_t(91, 100), sc_tan),
        }),
        hair_color_roll_list_t(
            {
                create_hair_color_matcher(roll::range_t(1, 40), hc_brown),
                create_hair_color_matcher(roll::range_t(41, 70), hc_black),
                create_hair_color_matcher(roll::range_t(71, 90), hc_blonde),
                create_hair_color_matcher(roll::range_t(91, 100), hc_red)
            }),
        eye_color_roll_list_t({
            create_eye_color_matcher(roll::range_t(1, 40), ec_blue),
            create_eye_color_matcher(roll::range_t(41, 70), ec_green),
            create_eye_color_matcher(roll::range_t(71, 80), ec_grey),
            create_eye_color_matcher(roll::range_t(81, 90), ec_brown),
            create_eye_color_matcher(roll::range_t(91, 100), ec_hazel)
        }),
        fur_pattern_roll_list_t({create_fur_pattern_matcher(roll::range_t(1, 100), fp_null)}),
        scale_color_roll_list_t({create_scale_color_matcher(roll::range_t(1, 100), scl_null)}),
        horn_type_roll_list_t({create_horn_type_matcher(roll::range_t(1, 100), ht_null)}));
    static const auto redguard = race_t(
        r_redguard, "Redguard",
        create_archetype_roll_list(mage_range_t(1, 60), warrior_range_t(61, 80),
                                   thief_range_t(81, 100)),
        skin_color_roll_list_t({
            create_skin_color_matcher(roll::range_t(1, 60), sc_dark),
            create_skin_color_matcher(roll::range_t(61, 90), sc_tan),
            create_skin_color_matcher(roll::range_t(91, 100), sc_olive),
        }),
        hair_color_roll_list_t({
            create_hair_color_matcher(roll::range_t(1, 70), hc_black),
            create_hair_color_matcher(roll::range_t(71, 90), hc_brown),
            create_hair_color_matcher(roll::range_t(91, 100), hc_dark_red)
        }),
        eye_color_roll_list_t({
            create_eye_color_matcher(roll::range_t(1, 60), ec_brown),
            create_eye_color_matcher(roll::range_t(61, 80), ec_black),
            create_eye_color_matcher(roll::range_t(81, 95), ec_amber),
            create_eye_color_matcher(roll::range_t(96, 100), ec_hazel)
        }),
        fur_pattern_roll_list_t({create_fur_pattern_matcher(roll::range_t(1, 100), fp_null)}),
        scale_color_roll_list_t({create_scale_color_matcher(roll::range_t(1, 100), scl_null)}),
        horn_type_roll_list_t({create_horn_type_matcher(roll::range_t(1, 100), ht_null)}));
    static const auto dunmer = race_t(
        r_dunmer, "Dunmer (Dark Elf)",
        create_archetype_roll_list(mage_range_t(1, 35), warrior_range_t(36, 65),
                                   thief_range_t(66, 100)),
        skin_color_roll_list_t({
            create_skin_color_matcher(roll::range_t(1, 70), sc_ashen_grey),
            create_skin_color_matcher(roll::range_t(71, 95), sc_dark_grey),
            create_skin_color_matcher(roll::range_t(96, 100), sc_near_black),
        }),
        hair_color_roll_list_t({
            create_hair_color_matcher(roll::range_t(1, 80), hc_black),
            create_hair_color_matcher(roll::range_t(81, 95), hc_dark_red),
            create_hair_color_matcher(roll::range_t(96, 100), hc_grey)
        }),
        eye_color_roll_list_t({
            create_eye_color_matcher(roll::range_t(1, 60), ec_red),
            create_eye_color_matcher(roll::range_t(61, 90), ec_amber),
            create_eye_color_matcher(roll::range_t(91, 95), ec_orange),
            create_eye_color_matcher(roll::range_t(96, 100), ec_brown)
        }),
        fur_pattern_roll_list_t({create_fur_pattern_matcher(roll::range_t(1, 100), fp_null)}),
        scale_color_roll_list_t({create_scale_color_matcher(roll::range_t(1, 100), scl_null)}),
        horn_type_roll_list_t({create_horn_type_matcher(roll::range_t(1, 100), ht_null)}));
    static const auto altmer = race_t(
        r_altmer, "Altmer (High Elf)",
        create_archetype_roll_list(mage_range_t(1, 15), warrior_range_t(16, 30),
                                   thief_range_t(31, 100)),
        skin_color_roll_list_t({
            create_skin_color_matcher(roll::range_t(1, 70), sc_fair),
            create_skin_color_matcher(roll::range_t(71, 90), sc_pale),
            create_skin_color_matcher(roll::range_t(91, 100), sc_golden),
        }),
        hair_color_roll_list_t({
            create_hair_color_matcher(roll::range_t(1, 60), hc_golden_blonde),
            create_hair_color_matcher(roll::range_t(61, 90), hc_silver_white),
            create_hair_color_matcher(roll::range_t(91, 100), hc_light_brown)
        }),
        eye_color_roll_list_t({
            create_eye_color_matcher(roll::range_t(1, 70), ec_gold),
            create_eye_color_matcher(roll::range_t(71, 90), ec_blue),
            create_eye_color_matcher(roll::range_t(91, 95), ec_green),
            create_eye_color_matcher(roll::range_t(96, 100), ec_amber)
        }),
        fur_pattern_roll_list_t({create_fur_pattern_matcher(roll::range_t(1, 100), fp_null)}),
        scale_color_roll_list_t({create_scale_color_matcher(roll::range_t(1, 100), scl_null)}),
        horn_type_roll_list_t({create_horn_type_matcher(roll::range_t(1, 100), ht_null)}));
    static const auto bosmer = race_t(
        r_bosmer, "Bosmer (Wood Elf)",
        create_archetype_roll_list(mage_range_t(1, 35), warrior_range_t(36, 85), thief_range_t(86, 100)),
        skin_color_roll_list_t({
            create_skin_color_matcher(roll::range_t(1, 50), sc_tan),
            create_skin_color_matcher(roll::range_t(51, 80), sc_olive),
            create_skin_color_matcher(roll::range_t(81, 100), sc_brown),
        }),
        hair_color_roll_list_t({
            create_hair_color_matcher(roll::range_t(1, 60), hc_brown),
            create_hair_color_matcher(roll::range_t(61, 80), hc_black),
            create_hair_color_matcher(roll::range_t(81, 90), hc_green),
            create_hair_color_matcher(roll::range_t(91, 95), hc_blonde),
            create_hair_color_matcher(roll::range_t(96, 100), hc_red)
        }),
        eye_color_roll_list_t(
            {
                create_eye_color_matcher(roll::range_t(1, 60), ec_green),
                create_eye_color_matcher(roll::range_t(61, 80), ec_hazel),
                create_eye_color_matcher(roll::range_t(81, 95), ec_brown),
                create_eye_color_matcher(roll::range_t(96, 100), ec_amber)
            }),
        fur_pattern_roll_list_t({create_fur_pattern_matcher(roll::range_t(1, 100), fp_null)}),
        scale_color_roll_list_t({create_scale_color_matcher(roll::range_t(1, 100), scl_null)}),
        horn_type_roll_list_t({create_horn_type_matcher(roll::range_t(1, 100), ht_null)}));
    static const auto orsimer = race_t(
        r_orsimer, "Orsimer (Orc)",
        create_archetype_roll_list(mage_range_t(1, 65), warrior_range_t(66, 80),
                                   thief_range_t(81, 100)),
        skin_color_roll_list_t({
            create_skin_color_matcher(roll::range_t(1, 60), sc_olive),
            create_skin_color_matcher(roll::range_t(61, 90), sc_dark_green),
            create_skin_color_matcher(roll::range_t(91, 100), sc_dark),
        }),
        hair_color_roll_list_t({
            create_hair_color_matcher(roll::range_t(1, 70), hc_black),
            create_hair_color_matcher(roll::range_t(71, 90), hc_dark_brown),
            create_hair_color_matcher(roll::range_t(91, 95), hc_grey),
            create_hair_color_matcher(roll::range_t(96, 100), hc_red)
        }),
        eye_color_roll_list_t({
            create_eye_color_matcher(roll::range_t(1, 60), ec_brown),
            create_eye_color_matcher(roll::range_t(61, 80), ec_red),
            create_eye_color_matcher(roll::range_t(81, 90), ec_yellow),
            create_eye_color_matcher(roll::range_t(91, 95), ec_amber),
            create_eye_color_matcher(roll::range_t(96, 100), ec_orange)
        }),
        fur_pattern_roll_list_t({create_fur_pattern_matcher(roll::range_t(1, 100), fp_null)}),
        scale_color_roll_list_t({create_scale_color_matcher(roll::range_t(1, 100), scl_null)}),
        horn_type_roll_list_t({create_horn_type_matcher(roll::range_t(1, 100), ht_null)}));
    static const auto khajiit = race_t(
        r_khajiit, "Khajiit",
        create_archetype_roll_list(mage_range_t(1, 35), warrior_range_t(36, 75), thief_range_t(76, 100)),
        skin_color_roll_list_t({create_skin_color_matcher(roll::range_t(1, 100), sc_null)}),
        hair_color_roll_list_t({
            create_hair_color_matcher(roll::range_t(1, 30), hc_brown),
            create_hair_color_matcher(roll::range_t(31, 55), hc_black),
            create_hair_color_matcher(roll::range_t(56, 75), hc_grey),
            create_hair_color_matcher(roll::range_t(76, 90), hc_white),
            create_hair_color_matcher(roll::range_t(91, 100), hc_orange)
        }),
        eye_color_roll_list_t({
            create_eye_color_matcher(roll::range_t(1, 40), ec_amber),
            create_eye_color_matcher(roll::range_t(41, 70), ec_green),
            create_eye_color_matcher(roll::range_t(71, 90), ec_yellow),
            create_eye_color_matcher(roll::range_t(91, 95), ec_blue),
            create_eye_color_matcher(roll::range_t(96, 100), ec_brown)
        }),
        fur_pattern_roll_list_t({
            create_fur_pattern_matcher(roll::range_t(1, 40), fp_striped),
            create_fur_pattern_matcher(roll::range_t(41, 70), fp_spotted),
            create_fur_pattern_matcher(roll::range_t(71, 90), fp_solid),
            create_fur_pattern_matcher(roll::range_t(91, 100), fp_tabby),
        }),
        scale_color_roll_list_t({create_scale_color_matcher(roll::range_t(1, 100), scl_null)}),
        horn_type_roll_list_t({create_horn_type_matcher(roll::range_t(1, 100), ht_null)}));
    static const auto argonian = race_t(
        r_argonian, "Argonian",
        create_archetype_roll_list(mage_range_t(1, 40), warrior_range_t(41, 80), thief_range_t(81, 100)),
        skin_color_roll_list_t({create_skin_color_matcher(roll::range_t(1, 100), sc_null)}),
        hair_color_roll_list_t({create_hair_color_matcher(roll::range_t(1, 100), hc_null)}),
        eye_color_roll_list_t({
            create_eye_color_matcher(roll::range_t(1, 40), ec_yellow),
            create_eye_color_matcher(roll::range_t(41, 70), ec_red),
            create_eye_color_matcher(roll::range_t(71, 85), ec_orange),
            create_eye_color_matcher(roll::range_t(86, 95), ec_green),
            create_eye_color_matcher(roll::range_t(96, 100), ec_amber)
        }),
        fur_pattern_roll_list_t({create_fur_pattern_matcher(roll::range_t(1, 100), fp_null)}),
        scale_color_roll_list_t({
            create_scale_color_matcher(roll::range_t(1, 50), scl_dark_green),
            create_scale_color_matcher(roll::range_t(51, 80), scl_olive),
            create_scale_color_matcher(roll::range_t(81, 95), scl_brown),
            create_scale_color_matcher(roll::range_t(96, 100), scl_grey),
        }),
        horn_type_roll_list_t({
            create_horn_type_matcher(roll::range_t(1, 35), ht_none),
            create_horn_type_matcher(roll::range_t(36, 60), ht_spiked),
            create_horn_type_matcher(roll::range_t(61, 85), ht_curved),
            create_horn_type_matcher(roll::range_t(86, 100), ht_both)
        }));
    static const auto list =
        race_roll_list_t({
            race_roll_matcher_t(roll::range_t(1, 42), nord),
            race_roll_matcher_t(roll::range_t(43, 55), imperial),
            race_roll_matcher_t(roll::range_t(56, 67), breton),
            race_roll_matcher_t(roll::range_t(68, 75), dunmer),
            race_roll_matcher_t(roll::range_t(76, 81), altmer),
            race_roll_matcher_t(roll::range_t(82, 87), orsimer),
            race_roll_matcher_t(roll::range_t(88, 92), redguard),
            race_roll_matcher_t(roll::range_t(93, 95), bosmer),
            race_roll_matcher_t(roll::range_t(96, 98), khajiit),
            race_roll_matcher_t(roll::range_t(99, 100), argonian)
        });
    return list;
};


type_aliases::string_t generate_character_text()
{
    type_aliases::string_t character_text = "";

    const race_roll_list_t& race_roll_list = get_race_roll_list();
    const race_t& race = race_roll_list.roll_for_item();

    character_text += race.create_labeled_name("Race") + '\n';

    const birth_signs_roll_list_t& birth_sign_roll_list = get_birth_signs_roll_list();
    const birth_sign_t& birth_sign = birth_sign_roll_list.roll_for_item();

    character_text += birth_sign.create_labeled_name("Birthsign") + '\n';

    const sex_t sex = roll_for_sex();

    character_text += sex.create_labeled_name("Sex") + '\n';

    const sexualities_roll_list_t sexualities_roll_list = create_sexualities_roll_list(sex.get_id());
    const sexuality_t& sexuality = sexualities_roll_list.roll_for_item();

    character_text += sexuality.create_labeled_name("Sexuality") + '\n';

    const bool is_archetype_based_on_birth_sign = birth_sign.roll_if_archetype_based_on_birth_sign();
    const archetype_t archetype = is_archetype_based_on_birth_sign ? create_archetype(birth_sign.get_archetype_id()) : race.roll_archetype();

    character_text += archetype.create_labeled_name("Archetype") + '\n';

    const rpg_class_roll_list_t rpg_class_roll_list = create_rpg_class_roll_list(archetype.get_id());
    const rpg_class_t rpg_class = rpg_class_roll_list.roll_for_item();

    character_text += rpg_class.create_labeled_name("RPG Class") + '\n';

    const skin_color_t skin_color = race.roll_skin_color();
    if (skin_color.get_id() != sc_null)
    {
        character_text += skin_color.create_labeled_name("Skin Color") + '\n';
    }

    const hair_color_t hair_color = race.roll_hair_color();
    if (hair_color.get_id() != hc_null)
    {
        character_text += hair_color.create_labeled_name("Hair Color") + '\n';
    }

    const fur_pattern_t fur_pattern = race.roll_fur_pattern();
    if(fur_pattern.get_id() != fp_null)
    {
        character_text += fur_pattern.create_labeled_name("Fur Pattern") + '\n';
    }

    const scale_color_t scale_color = race.roll_scale_color();
    if (scale_color.get_id() != scl_null)
    {
        character_text += scale_color.create_labeled_name("Scale Color") + '\n';
    }

    const horn_type_t horn_type = race.roll_horn_type();
    if (horn_type.get_id() != ht_null)
    {
        character_text += horn_type.create_labeled_name("Horn Type") + '\n';
    }

    const eye_color_t eye_color = race.roll_eye_color();

    return character_text;
}

}


#endif // CHARACTER_GENERATOR_H
