#pragma once

#define RG_GRAPH
#define RG_EXPEREMENTAL
#define RG_ADDONS
#define RG_SOUND
#define RG_NEW_VIEW
#define RG_WIP_CONTENT
#include "../Rinegine/Rinegine.h"


enum Location
{
	LOC_EXIT = -1,
	LOC_MENU,
	LOC_SETTINGS,
	LOC_WORLDS,
	LOC_GAME,
};
///////////////////////////////////////SETS


RG_lang &translation = RG_StandartLang;

bool DebugSetting = false;
bool FlySetting = false;
bool MSAASetting = true;
bool MSAASettingReal = true;

uint MSAASettings = 4;
uint VSyn = 1;
uint VSynReal = 1 ;
//uint RenderDistance = 1024;
uint RenderDistance = 6;
//uint RenderDistance = -1000;
//uint SizePlat = 256;
uint DiameterChunks = 2;

float SpeenTemp = 1;
float SpeedSpeen = 1.6;
bool StageSpeen = 0;
//////////////




//////////////





Location NowIsPlay;

void SetLocate(Location loc)
{
	NowIsPlay = loc;
}



RG_Timer RR_MainTimer;

RG_Object RR_BACKGROUND;
RG_Text SHOW_FPS_RR;


bool RR_INIT = false;






RG_Camera &RR_MainCamera = StandartCam;

//////////////////////////////////////////////////LOCATIONS

#include "Locations/set.h"