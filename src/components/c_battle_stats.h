#ifndef COMPONENT_BATTLE_STATS_H
#define COMPONENT_BATTLE_STATS_H

#include <flecs.h>
#include "types.h"
#include "vectypes.h"
#include "enums.h"

typedef struct MonsterParameter {
	u16 hp;
	u16 attack;
	u16 defense;
    u16 spAttack;
	u16 spDefense;
	u16 spd;
	//f32 mass;
} MonsterParameter;

typedef struct MonsterBase {
	MonsterParameter baseParam;
    u8 type1;
    u8 type2;
	u16 currentHP;
	u8 level;
    u32 experience;
	u32 status1;
    u32 status2;
    u16 heldItem;
} MonsterBase;

typedef struct MonsterBattle {
	MonsterParameter battleParam;
	//int status_condition;
	//Action* action_queue;
	Vec3f position;
	Vec3f velocity;
} MonsterBattle;

typedef struct BattleMove {
    u8 effect;
    u8 power;
    u8 type;
    u8 accuracy;
    u8 pp;
    u8 secondaryEffectChance;
    u8 target;
    s8 priority;
    u8 flags;
} BattleMove;

typedef struct SideState {
    u8 spikes;
    u32 flags;
    u8 isSwitching;
} SideState;

typedef struct FieldState {
    u8 gameType;
    u8 weather;
    u8 terrain;
    u32 flags;
    SideState attackerSide;
    SideState defenderSide;
} FieldState;

extern MonsterParameter gSpeciesParameters[NUM_MONSTER_SPECIES];
extern const char gTypeNames[NUM_TYPES + 1][TYPE_NAME_LENGTH + 1];
extern const u8 gTypeEffectiveness[NUM_TYPES][NUM_TYPES];
extern const BattleMove gBattleMoves[MOVES_COUNT];

#endif