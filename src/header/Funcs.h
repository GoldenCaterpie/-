#ifndef FUNCS_H
#define FUNCS_H

#include "Types.h"
#include "Structs.h"

void* memset(void *dst, u8 pattern, u8 size);
void SetAreaHasMon(u16 mapGroup, u16 mapNum);
void SetSpecialMapHasMon(u16 mapGroup, u16 mapNum);
bool8 MapHasMon(struct WildPokemonHeader *info, u16 species);
struct MapHeader *Overworld_GetMapHeaderByGroupAndId(u16 mapGroup, u16 mapNum);
void CreateMon(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId);
u32 GetMonData(struct Pokemon *mon, s32 field, u8* data);
void SetMonData(struct Pokemon *mon, s32 field, void *dataArg);
u16 Random(void);
bool8 IsWildLevelAllowedByRepel(u8 level);
void CreateMonWithIVsPersonality(struct Pokemon *mon, u16 species, u8 level, u32 ivs, u32 personality);
u32 __umodsi3__(u32 numerator, u32 denumerator);
u16 VarGet(u16 id);

#endif