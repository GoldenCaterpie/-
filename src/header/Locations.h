#ifndef LOCATIONS_H
#define LOCATIONS_H

#include "Types.h"

#define ROAM_MAX 7 //修改以改变游走神兽上限，但与此同时也要修改bpee.ld中链接的地址

extern u16 var_8000;
extern u16 var_8001;
extern u16 var_8002;
extern u16 var_8003;
extern u16 var_8004;
extern u16 var_800D;

extern u16 gHasWon[50];
extern u16 sFeebasData[][3];
extern u8 sRoamerLocations[][6];
extern u8 sLocationHistory[3][2];

#endif 
