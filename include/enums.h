#ifndef ENUM_DEF_H
#define ENUM_DEF_H

#define NUM_MONSTER_SPECIES 1

#define FLAG_MAKES_CONTACT          (1 << 0)
#define FLAG_PROTECT_AFFECTED       (1 << 1)
#define FLAG_MAGIC_COAT_AFFECTED    (1 << 2)
#define FLAG_SNATCH_AFFECTED        (1 << 3)
#define FLAG_MIRROR_MOVE_AFFECTED   (1 << 4)
#define FLAG_KINGS_ROCK_AFFECTED    (1 << 5)

enum TypeMultiplier {
    TYPE_MULT_NONE,
    TYPE_MULT_HALF,
    TYPE_MULT_NORM,
    TYPE_MULT_SUPR,
};

#define TYPE_NAME_LENGTH 8
enum ElementalTypes {
    TYPE_NORMAL,
    TYPE_FIRE,
    TYPE_WATER,
    TYPE_ELECTRIC,
    TYPE_GRASS,
    TYPE_ICE,
    TYPE_FIGHTING,
    TYPE_POISON,
    TYPE_GROUND,
    TYPE_FLYING,
    TYPE_PSYCHIC,
    TYPE_BUG,
    TYPE_ROCK,
    TYPE_GHOST,
    TYPE_DRAGON,
    TYPE_DARK,
    TYPE_STEEL,
    TYPE_FAIRY,
    TYPE_NONE,
    NUM_TYPES = TYPE_NONE,
};

enum B_GameType {
    GAMETYPE_SINGLES,
    GAMETYPE_DOUBLES,
};

enum Terrain {
    TERRAIN_ELECTRIC,
    TERRAIN_GRASSY,
    TERRAIN_PSYCHIC,
    TERRAIN_MISTY,
};

enum WeatherTypes {
    WEATHER_SAND,
    WEATHER_SUN,
    WEATHER_RAIN,
    WEATHER_HAIL,
    WEATHER_SNOW,
    WEATHER_HARSH_SUN,
    WEATHER_HEAVY_RAIN,
    WEATHER_STRNG_WIND,
};

enum Moves_Hardcoded {
    MOVE_NONE,
    MOVE_POUND,
    MOVE_HYDRO_STEAM,
    MOVES_COUNT,
};

enum MoveEffects_HardCoded {
    EFFECT_HIT,
    NUM_BATTLE_MOVE_EFFECTS,
};

enum MoveTarget {
    MOVE_TARGET_SELECTED         = 0,
    MOVE_TARGET_DEPENDS          = (1 << 0),
    MOVE_TARGET_USER_OR_SELECTED = (1 << 1),
    MOVE_TARGET_RANDOM           = (1 << 2),
    MOVE_TARGET_BOTH             = (1 << 3),
    MOVE_TARGET_USER             = (1 << 4),
    MOVE_TARGET_FOES_AND_ALLY    = (1 << 5),
    MOVE_TARGET_OPPONENTS_FIELD  = (1 << 6),
};

enum BodyTypes {
    HEAD_ONLY,
    HEAD_BASE,
    HEAD_BASE_TAIL, //serpentine form
    HEAD_LEGS,
    HEAD_FOUR_LEGS,
    HEAD_MORE_LEGS,
    ISCT_LEGS, //insectoid form
    HEAD_ARMS,
    PAIR_WINGS,
    MULT_PAIR_WINGS,
    FINS,
    HEAD_BASE_ARMS_LEGS, //bipedal, tailless form
    HEAD_BASE_ARMS_LEGS_TAIL, //bipedal, tailed form
    BODY_MULT,
};

#endif