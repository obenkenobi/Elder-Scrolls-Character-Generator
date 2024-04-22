#ifndef CHARACTER_GEN_H
#define CHARACTER_GEN_H

#include "roll.h"
#include "types_aliases.h"

namespace CharGen
{
// Archetype
// -----------------------------------------------------------------------------
enum archetype_id_t { a_mage, a_thief, a_warrior, a_any };

using archetype_t = Roll::RollItem<archetype_id_t>;

archetype_t create_archetype(const archetype_id_t id);

using archetype_roll_list_t = Roll::RollArray<archetype_t, 3>;
using archetype_roll_matcher_t = Roll::RollMatcher<archetype_t>;
using mage_range_t = Roll::Range;
using warrior_range_t = Roll::Range;
using thief_range_t = Roll::Range;

archetype_roll_list_t
create_archetype_roll_list(const mage_range_t mage_range,
                           const warrior_range_t warrior_range,
                           const thief_range_t thief_range);

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

using rpg_class_t = Roll::RollItem<rpg_class_id_t>;

using rpg_class_roll_list_t = Roll::RollArray<rpg_class_t, 7>;
using rpg_class_roll_matcher_t = Roll::RollMatcher<rpg_class_t>;

const rpg_class_roll_list_t& get_warrior_class_roll_list();

const rpg_class_roll_list_t& get_thief_class_roll_list();

const rpg_class_roll_list_t& get_mage_class_roll_list();

const rpg_class_roll_list_t& create_rpg_class_roll_list(const archetype_id_t archetype_id);

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

class birth_sign_t : public Roll::RollItem<birth_sign_id_t>
{
public:
    birth_sign_t(const birth_sign_id_t i_id, const archetype_id_t archetype_id,
                 const TAS::String& i_display_name);

    bool roll_if_archetype_based_on_birth_sign() const;

    archetype_id_t get_archetype_id() const { return archetype_id_; }

private:
    archetype_id_t archetype_id_;
};

using birth_signs_roll_list_t = Roll::RollArray<birth_sign_t, 13>;
using birth_signs_roll_matcher_t = Roll::RollMatcher<birth_sign_t>;

const birth_signs_roll_list_t& get_birth_signs_roll_list();;

// Sex
// ------------------------------------------------------------------------------------------------------------

enum sex_id_t { male, female };

using sex_t = Roll::RollItem<sex_id_t>;

sex_t roll_for_sex();

// Sexuality
// ------------------------------------------------------------------------------------------------------------
enum sexuality_id_t { heterosexual, bisexual, homosexual };

using sexuality_t = Roll::RollItem<sexuality_id_t>;

using sexualities_roll_list_t = Roll::RollArray<sexuality_t, 3>;
using sexualities_roll_matcher_t = Roll::RollMatcher<sexuality_t>;

const sexualities_roll_list_t& create_sexualities_roll_list(const sex_id_t sex_id);

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

using skin_color_t = Roll::RollItem<skin_color_id_t>;

using skin_color_roll_list_t = Roll::RollVector<skin_color_t>;
using skin_color_matcher_t = Roll::RollMatcher<skin_color_t>;

skin_color_matcher_t create_skin_color_matcher(const Roll::Range range, const skin_color_id_t& skin_color_id);

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

using hair_color_t = Roll::RollItem<hair_color_id_t>;

using hair_color_roll_list_t = Roll::RollVector<hair_color_t>;
using hair_color_matcher_t = Roll::RollMatcher<hair_color_t>;

hair_color_matcher_t create_hair_color_matcher(const Roll::Range range, const hair_color_id_t id);

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

using eye_color_t = Roll::RollItem<eye_color_id_t>;

using eye_color_roll_list_t = Roll::RollVector<eye_color_t>;
using eye_color_matcher_t = Roll::RollMatcher<eye_color_t>;

eye_color_matcher_t create_eye_color_matcher(const Roll::Range range, const eye_color_id_t id);

// Fur Pattern --------------------------------------------------------
enum fur_pattern_id_t { fp_null, fp_striped, fp_spotted, fp_solid, fp_tabby };

using fur_pattern_t = Roll::RollItem<fur_pattern_id_t>;

using fur_pattern_roll_list_t = Roll::RollVector<fur_pattern_t>;
using fur_pattern_matcher_t = Roll::RollMatcher<fur_pattern_t>;

fur_pattern_matcher_t create_fur_pattern_matcher(const Roll::Range range, const fur_pattern_id_t id);

// Scale Color --------------------------------------------------------
enum scale_color_id_t
{
    scl_null,
    scl_dark_green,
    scl_olive,
    scl_brown,
    scl_grey
};

using scale_color_t = Roll::RollItem<scale_color_id_t>;

using scale_color_roll_list_t = Roll::RollVector<scale_color_t>;
using scale_color_matcher_t = Roll::RollMatcher<scale_color_t>;

scale_color_matcher_t create_scale_color_matcher(const Roll::Range range, const scale_color_id_t id);

// Horn Type --------------------------------------------------------
enum horn_type_id_t { ht_null, ht_none, ht_spiked, ht_curved, ht_both };

using horn_type_t = Roll::RollItem<horn_type_id_t>;

using horn_type_roll_list_t = Roll::RollVector<horn_type_t>;
using horn_type_matcher_t = Roll::RollMatcher<horn_type_t>;

horn_type_matcher_t create_horn_type_matcher(const Roll::Range range, const horn_type_id_t id);

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

class race_t : public Roll::RollItem<race_id_t>
{
public:
    race_t(const race_id_t& i_id, const TAS::String& i_display_name,
           archetype_roll_list_t archetype_roll_list,
           skin_color_roll_list_t skin_color_roll_list,
           hair_color_roll_list_t hair_color_roll_list,
           eye_color_roll_list_t eye_color_roll_list,
           fur_pattern_roll_list_t fur_pattern_roll_list,
           scale_color_roll_list_t scale_color_roll_list,
           horn_type_roll_list_t horn_type_roll_list);

    archetype_t roll_archetype() const;

    skin_color_t roll_skin_color() const;

    hair_color_t roll_hair_color() const;

    eye_color_t roll_eye_color() const;

    fur_pattern_t roll_fur_pattern() const;

    scale_color_t roll_scale_color() const;

    horn_type_t roll_horn_type() const;

private:
    archetype_roll_list_t archetype_roll_list_;
    skin_color_roll_list_t skin_color_roll_list_;
    hair_color_roll_list_t hair_color_roll_list_;
    eye_color_roll_list_t eye_color_roll_list_;
    fur_pattern_roll_list_t fur_pattern_roll_list_;
    scale_color_roll_list_t scale_color_roll_list_;
    horn_type_roll_list_t horn_type_roll_list_;
};

using race_roll_list_t = Roll::RollArray<race_t, 10>;
using race_roll_matcher_t = Roll::RollMatcher<race_t>;

const race_roll_list_t& get_race_roll_list();;


TAS::String generate_character_text();

}


#endif // CHARACTER_GEN_H
