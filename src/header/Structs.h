#ifndef STRUCTS_H
#define STRUCTS_H

#include "Types.h"

typedef void (*MainCallback)(void);

struct Roamer
{
    /*0x00*/ u32 ivs;
    /*0x04*/ u32 personality;
    /*0x08*/ u16 species;
    /*0x0A*/ u16 hp;
    /*0x0C*/ u8 level;
    /*0x0D*/ u8 status;
		/*   u8 cute;
             u8 smart;
             u8 tough;
			 bool8 active;
			 u8 filler[0x8]	 */
	/*0x0E*/ bool8 canAppearOnLand; 
	/*0x0F*/ bool8 canAppearOnWater;
		/*   u8 locationHistory[3][2]; */ //没用
	/*0x10*/ u16 item;
	/*0x12*/ u8 location[2];
	/*SIZE = 0x18*/
};

extern struct Roamer gRoamers[7];

struct Pokemon
{
	u32 PID;
	u32 OTID;
	char name[10];
	char language;
	//char badegg;
	u8 isBadEgg : 1;
    u8 hasSpecies : 1;
    u8 isEgg1 : 1;
	u8 isdreamability : 1;
    u8 unused : 4;
	char OT_name[7];
	char markings;            // only the lowest 4 bits are used
	u16 checksum;
	//u16 padding_maybe;        //get_attr 6a674
	u16 randomid;
	u16 spieces;
	u16 item;
	u32 exp;
	char pointup;
	//char	PointUp1 : 2;	// @0x42,
	//char	PointUp2 : 2;	// @0x44,
	//char	PointUp3 : 2;	// @0x46,
	char bIntimate : 8;
	u16 unk0;
	u16 moves[4];        // ID of the Skill
	char movePP[4];        // Skill Points
	char evs_hp;
	char evs_atk;
	char evs_def;
	char evs_spd;
	char evs_spatk;
	char evs_spdef;
	char beauty[0x06];        // 帅气 美丽 可爱 聪明 强壮 光滑
	u32 virus : 4;        // @0x00, if any bit is set, ポケルスがかかる
	u32 blackpoint : 4;        // @0x04, if any bit is set, 黑点
	u32 catchplace : 8;
	u32 catchlevel : 7;
	u32 gameversion : 4;    // @0x17, game version (sapphire=1, ruby=2, emerald=3, fire=4, leaf=5)
	u32 ball : 4;        // @0x1B, Poke-Ball type (Write twice, why?)
	u32 unk1 : 1;            // @0x1F, 0
	u32 iv_hp : 5;
	u32 iv_atk : 5;
	u32 iv_def : 5;
	u32 iv_spd : 5;
	u32 iv_spatk : 5;
	u32 iv_spdef : 5;
	u32 isEgg : 1;
	u32 ability : 1;
	u32 ribbon0 : 3;
	u32 ribbon1 : 3;
	u32 ribbon2 : 3;
	u32 ribbon3 : 3;
	u32 ribbon4 : 3;
	u32 ribbon5 : 12;
	u32 unk2 : 4;
	u32 obedience : 1;
	// only for active (in group) pokemons
	char status;        // bit0-2:异常状态,
	char unkonw[3];
	char level;
	char pokerus;        // this is always 'FF'
	u16 current_hp;
	u16 total_hp;
	u16 attack;
	u16 defense;
	u16 speed;
	u16 sp_attack;
	u16 sp_defense;
};

extern struct Pokemon gEnemyParty[6];

struct PokeDexAreaScreenMapIdentity
{
    u8 mapGroup;
    u8 mapNum;
    u16 regionMapSectionId;
};

struct RegionMap {
    /*0x000*/ u16 mapSecId;
    /*0x002*/ u8 iconDrawType;
    /*0x003*/ u8 posWithinMapSec;
    /*0x004*/ u8 mapSecName[0x14];
    /*0x018*/ u8 (*inputCallback)(void);
    /*0x01c*/ /*struct Sprite*/ void *cursorSprite;  //节约时间
    /*0x020*/ /*struct Sprite*/ void *playerIconSprite;  //节约时间
    /*0x024*/ s32 bg2x;
    /*0x028*/ s32 bg2y;
    /*0x02c*/ u32 bg2pa;
    /*0x034*/ u32 bg2pc;
    /*0x030*/ u32 bg2pb;
    /*0x038*/ u32 bg2pd;
    /*0x03c*/ s32 unk_03c;
    /*0x040*/ s32 unk_040;
    /*0x044*/ s32 unk_044;
    /*0x048*/ s32 unk_048;
    /*0x04c*/ s32 unk_04c;
    /*0x050*/ s32 unk_050;
    /*0x054*/ u16 cursorPosX;
    /*0x056*/ u16 cursorPosY;
    /*0x058*/ u16 cursorTileTag;
    /*0x05a*/ u16 cursorPaletteTag;
    /*0x05c*/ s16 scrollX;
    /*0x05e*/ s16 scrollY;
    /*0x060*/ s16 unk_060;
    /*0x062*/ s16 unk_062;
    /*0x064*/ u16 zoomedCursorPosX;
    /*0x066*/ u16 zoomedCursorPosY;
    /*0x068*/ s16 zoomedCursorDeltaY;
    /*0x06a*/ s16 zoomedCursorDeltaX;
    /*0x06c*/ u16 zoomedCursorMovementFrameCounter;
    /*0x06e*/ u16 unk_06e;
    /*0x070*/ u16 playerIconTileTag;
    /*0x072*/ u16 playerIconPaletteTag;
    /*0x074*/ u16 playerIconSpritePosX;
    /*0x076*/ u16 playerIconSpritePosY;
    /*0x078*/ bool8 zoomed;
    /*0x079*/ u8 initStep;
    /*0x07a*/ s8 cursorMovementFrameCounter;
    /*0x07b*/ s8 cursorDeltaX;
    /*0x07c*/ s8 cursorDeltaY;
    /*0x07d*/ bool8 needUpdateVideoRegs;
    /*0x07e*/ bool8 blinkPlayerIcon;
    /*0x07f*/ bool8 playerIsInCave;
    /*0x080*/ u8 bgNum;
    /*0x081*/ u8 charBaseIdx;
    /*0x082*/ u8 mapBaseIdx;
    /*0x083*/ bool8 bgManaged;
    /*0x084*/ u8 filler_084[0x100];
    /*0x184*/ u8 cursorSmallImage[0x100];
    /*0x284*/ u8 cursorLargeImage[0x600];
}; // size = 0x884

struct PokeDexAreaScreen
{
    /*0x000*/ void (*callback)(void); // unused
    /*0x004*/ MainCallback prev; // unused
    /*0x008*/ MainCallback next; // unused
    /*0x00C*/ u16 state; // unused
    /*0x00E*/ u16 species;
    /*0x010*/ struct PokeDexAreaScreenMapIdentity overworldAreasWithMons[0x40];
    /*0x110*/ u16 numOverworldAreas;
    /*0x112*/ u16 numSpecialAreas;
    /*0x114*/ u16 drawAreaGlowState;
    /*0x116*/ u16 areaGlowTilemap[0x280];
    /*0x616*/ u16 areaShadeOrMarkerFrameCounter;
    /*0x618*/ u16 areaShadeFrameCounter;
    /*0x61A*/ u16 areaShadeBldArgLo;
    /*0x61C*/ u16 areaShadeBldArgHi;
    /*0x61E*/ u8 whichMarkersFlashing;
    /*0x61F*/ u8 specialMarkerCycleCounter;
    /*0x620*/ u16 specialAreaRegionMapSectionIds[0x20];
    /*0x660*/ /*struct Sprite*/ void *areaMarkerSprites[0x20]; //节约时间
    /*0x6E0*/ u16 numAreaMarkerSprites;
    /*0x6E2*/ u16 unk6E2;
    /*0x6E4*/ u16 unk6E4;
    /*0x6E8*/ u8 *errno;
    /*0x6EC*/ struct RegionMap regionMap;
    /*0xF70*/ u8 charBuffer[0x40];
    /*0xFB0*/ /*struct Sprite*/ void *areaUnknownSprites[3]; //节约时间
    /*0xFBC*/ u8 areaUnknownGraphicsBuffer[0x600];
};

extern struct PokeDexAreaScreen *sPokedexAreaScreen;

struct WildPokemonHeader
{
    u8 mapGroup;
    u8 mapNum;
    const /*struct WildPokemonInfo*/ void *landMonsInfo; //节约时间
    const /*struct WildPokemonInfo*/ void *waterMonsInfo; //节约时间
    const /*struct WildPokemonInfo*/ void *rockSmashMonsInfo; //节约时间
    const /*struct WildPokemonInfo*/ void *fishingMonsInfo; //节约时间
};

extern const struct WildPokemonHeader gWildMonHeaders[];

struct Coords16
{
    s16 x;
    s16 y;
};

struct WarpData
{
    s8 mapGroup;
    s8 mapNum;
    s8 warpId;
    s16 x, y;
};

struct SaveBlock1
{
    /*0x00*/ struct Coords16 pos;
    /*0x04*/ struct WarpData location;
	
    /*节约时间*/
	
};

extern struct SaveBlock1* gSaveBlock1Ptr;

struct MapHeader
{
    /* 0x00 */ const /*struct MapLayout*/ void *mapLayout; //节约时间
    /* 0x04 */ const /*struct MapEvents*/ void *events; //节约时间
    /* 0x08 */ const u8 *mapScripts;
    /* 0x0C */ const /*struct MapConnections*/ void *connections; //节约时间
    /* 0x10 */ u16 music;
    /* 0x12 */ u16 mapLayoutId;
    /* 0x14 */ u8 regionMapSectionId;
    /* 0x15 */ u8 cave;
    /* 0x16 */ u8 weather;
    /* 0x17 */ u8 mapType;
    /* 0x18 */ u8 filler_18[2];
    /* 0x1A */ u8 flags;
    /* 0x1B */ u8 battleType;
};

#endif