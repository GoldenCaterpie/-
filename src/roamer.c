#include "header/Define_all.h"

void CleargHasWon(void);
void NewFindMapsWithMon(u16 species);
static void NewGetRoamerLocation(u8 *mapGroup, u8 *mapNum, u8 i);
void NewInitRoamer(void);
static u8 GetValidMapNum(u8 type, u16 i);
static bool8 isMapNumOnLand(u8 mapnum);
void NewRoamerMove(void);
void NewRoamerMoveToOtherLocationSet(void);
bool8 NewTryStartRoamerEncounter(void);
static bool8 NewIsRoamerAt(u16 i, u8 mapGroup, u8 mapNum);
void NewUpdateRoamerHPStatus(struct Pokemon *mon);
void NewSetRoamerInactive(void);

void CleargHasWon(void)
{
	memset(gHasWon, 0, sizeof(u16) * 50);
}

void NewFindMapsWithMon(u16 species)
{
    u16 i;

    sPokedexAreaScreen->unk6E2 = 0;
    sPokedexAreaScreen->unk6E4 = VarGet(0x403E);
    if (sPokedexAreaScreen->unk6E4 > 8)
        sPokedexAreaScreen->unk6E4 = 0;
	
	for (i = 0; i < ROAM_MAX; i++)
		if (species == gRoamers[i].species)
			break;
	
    if (ROAM_MAX == i) //不是游走神兽
    {
        sPokedexAreaScreen->numOverworldAreas = 0;
        sPokedexAreaScreen->numSpecialAreas = 0;
		/*
        for (i = 0; i < ARRAY_COUNT(sSpeciesHiddenFromAreaScreen); i++)
        {
            if (sSpeciesHiddenFromAreaScreen[i] == species)
                return;
        }
		*/

		if (360 == species)
			return;
		
        for (i = 0; sFeebasData[i][0] != 412; i++)
        {
            if (species == sFeebasData[i][0])
            {
                switch (sFeebasData[i][1])
                {
                    case 0:
                        SetAreaHasMon(sFeebasData[i][1], sFeebasData[i][2]);
                        break;
                    case 0x18:
                    case 0x1A:
                        SetSpecialMapHasMon(sFeebasData[i][1], sFeebasData[i][2]);
                        break;
                }
            }
        }

        for (i = 0; gWildMonHeaders[i].mapGroup != 0xFF; i++) //0813CC44
        {
            if (MapHasMon(&gWildMonHeaders[i], species)) //0813CC5A
            {
                switch (gWildMonHeaders[i].mapGroup)
                {
                    case 0:
                        SetAreaHasMon(gWildMonHeaders[i].mapGroup, gWildMonHeaders[i].mapNum); //0813CC86
                        break;
                    case 0x18:
                    case 0x1A:
                        SetSpecialMapHasMon(gWildMonHeaders[i].mapGroup, gWildMonHeaders[i].mapNum);
                        break;
                }
            }
        }
    }
    else //是游走神兽
    {
		sPokedexAreaScreen->numSpecialAreas = 0;
        NewGetRoamerLocation(&sPokedexAreaScreen->overworldAreasWithMons[0].mapGroup, &sPokedexAreaScreen->overworldAreasWithMons[0].mapNum, i);
        sPokedexAreaScreen->overworldAreasWithMons[0].regionMapSectionId = Overworld_GetMapHeaderByGroupAndId(sPokedexAreaScreen->overworldAreasWithMons[0].mapGroup, sPokedexAreaScreen->overworldAreasWithMons[0].mapNum)->regionMapSectionId;
        sPokedexAreaScreen->numOverworldAreas = 1;
    }
}

static void NewGetRoamerLocation(u8 *mapGroup, u8 *mapNum, u8 i)
{
    *mapGroup = gRoamers[i].location[0];
    *mapNum = gRoamers[i].location[1];
}

/*****
	var_8000 种类 
	var_8001 等级
	var_8002 是否出现在陆上
	var_8003 是否出现在水上
	var_8004 携带道具
*/
void NewInitRoamer(void)
{
    u16 i;
	
	var_800D = false;
	
	if (!var_8002 && !var_8003) //防止卡死
		return;
		
	for (i = 0; i < ROAM_MAX; i++) //防止重复游走
		if (var_8000 == gRoamers[i].species)
			return;
		
	for (i = 0; (gHasWon[i] != 0) && (i < 50 /*最多支持储存五十只神兽*/ ); i++) //防止重复捕捉
		if (var_8000 == gHasWon[i])
			return;		
	if (gHasWon[49] != 0) //超过上限
		return;
	
	for (i = 0; i < ROAM_MAX; i++)
	{
		if (0 == gRoamers[i].species)
		{
			gRoamers[i].species = var_8000;
			gRoamers[i].level = var_8001;
			CreateMon(&gEnemyParty[0], gRoamers[i].species, gRoamers[i].level, 0x20, 0, 0, 0, 0);
			gRoamers[i].ivs = GetMonData(&gEnemyParty[0], 66, NULL);
			gRoamers[i].personality = GetMonData(&gEnemyParty[0], 0, NULL);
			gRoamers[i].hp = GetMonData(&gEnemyParty[0], 58, NULL);
			gRoamers[i].status = 0;
			gRoamers[i].item = var_8004;
			
			gRoamers[i].canAppearOnLand = var_8002;
			gRoamers[i].canAppearOnWater = var_8003;
			gRoamers[i].location[0] = 0;
			gRoamers[i].location[1] = GetValidMapNum(0, i);
			
			break;
		}
	}
	
	if (i != ROAM_MAX)
		var_800D = true;
}

static u8 GetValidMapNum(u8 type, u16 i)
{
	u16 j;
	u8 mapnum, locSet;
	
	if (0 == type)
	{
		for (j = 0; j < 100; j++) //防止卡死
		{
			mapnum = sRoamerLocations[__umodsi3__(Random(), 0x14)][0];
			
			if (gRoamers[i].location[1] == mapnum)
				continue;
			if (!gRoamers[i].canAppearOnLand)
				if (isMapNumOnLand(mapnum))
					continue;
			if (!gRoamers[i].canAppearOnWater)
				if (!isMapNumOnLand(mapnum))
					continue;
				
			break;
		}
		
		if (100 == j)
			return GetValidMapNum(1, i);
	}
	else
	{
		for (locSet = 0; locSet < 0x14; locSet++)
		{
			if (gRoamers[i].location[1] == sRoamerLocations[locSet][0])
			{
				for (j = 0; j < 100; j++) //防止卡死
				{
					mapnum = sRoamerLocations[locSet][__umodsi3__(Random(), 5) + 1];
					if (((0 == sLocationHistory[2][0]) && (mapnum == sLocationHistory[2][1])) || (0xFF == mapnum))
						continue;
					if (!gRoamers[i].canAppearOnLand)
						if (isMapNumOnLand(mapnum))
							continue;
					if (!gRoamers[i].canAppearOnWater)
						if (!isMapNumOnLand(mapnum))
							continue;
						
					break;
				}
				
				if (100 == j)
					return GetValidMapNum(0, i);
			}
		}
	}
	
	return mapnum;
}

static bool8 isMapNumOnLand(u8 mapnum)
{
	if ((mapnum >= 16 && mapnum <= 19) || (mapnum >= 25 && mapnum <= 36) || (38 == mapnum))
		return true;
	else
		return false;
}

void NewRoamerMove(void)
{
	u16 i;
	u8 type;
	
	for (i = 0; i < ROAM_MAX; i++)
	{
		if (0 != gRoamers[i].species)
		{
			if (0 == __umodsi3__(Random(), 16))
				type = 0;
			else
				type = 1;
			
			gRoamers[i].location[1] = GetValidMapNum(type, i);
		}
	}
}

void NewRoamerMoveToOtherLocationSet(void)
{
	u16 i;
	
	for (i = 0; i < ROAM_MAX; i++)
		if (0 != gRoamers[i].species)
			gRoamers[i].location[1] = GetValidMapNum(0, i);
}

bool8 NewTryStartRoamerEncounter(void)
{
	u16 i;
	
	for (i = 0; i < ROAM_MAX; i++)
	{
		if ((gRoamers[i].species != 0) && NewIsRoamerAt(i, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum) && (__umodsi3__(Random(), 4)) == 0)
		{
			if (!IsWildLevelAllowedByRepel(gRoamers[i].level))
				continue;
			
			CreateMonWithIVsPersonality(&gEnemyParty[0], gRoamers[i].species, gRoamers[i].level, gRoamers[i].ivs, gRoamers[i].personality);
			SetMonData(&gEnemyParty[0], 55, &gRoamers[i].status);
			SetMonData(&gEnemyParty[0], 57, &gRoamers[i].hp);
			SetMonData(&gEnemyParty[0], 12, &gRoamers[i].item);
			
			return true;
		}
	}
	
	return false;
}

static bool8 NewIsRoamerAt(u16 i, u8 mapGroup, u8 mapNum)
{
    if (mapGroup == gRoamers[i].location[0] && mapNum == gRoamers[i].location[1])
        return true;
    else
        return false;
}

void NewUpdateRoamerHPStatus(struct Pokemon *mon)
{
    u16 i;
	u16 species = GetMonData(mon, 11, NULL);
	
	for (i = 0; i < ROAM_MAX; i++)
	{
		if (species == gRoamers[i].species)
		{
			gRoamers[i].status = GetMonData(mon, 55, NULL);
			gRoamers[i].hp = GetMonData(mon, 57, NULL);
			gRoamers[i].item = GetMonData(mon, 12, NULL);
			
			break;
		}
	}

    NewRoamerMoveToOtherLocationSet();
}

void NewSetRoamerInactive(void)
{
	u16 i, j;
	u16 species = GetMonData(&gEnemyParty[0], 11, NULL);
	
	for (i = 0; i < ROAM_MAX; i++)
	{
		if (species == gRoamers[i].species)
		{
			memset(&gRoamers[i], 0, sizeof(struct Roamer));
			
			for (j = 0; j < 50; j++)
			{
				if (0 == gHasWon[j])
				{
					gHasWon[j] = species;
					
					break;
				}				
			}	
		}
	}
}
