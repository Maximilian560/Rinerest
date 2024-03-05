#include "source.h"



void RR_KeyEvent(GLFWwindow* win, int key, int scancode, int action, int mods)
{
	RG_KeyEvent(win,key,scancode,action,mods);

	/*RG_KEYS[key] = action;
	if(key == GLFW_KEY_F11&&action==GLFW_PRESS)
	{
		RG_MainWindow->Active_Fullscreen();
		////if(RG_CursorFix)glfwSetCursorPos(RG_MainWindow->mon(),RG_MainWindow->set().resolution.x/2.,RG_MainWindow->set().resolution.y/2.);
	}*/
	if(key == GLFW_KEY_F3&&action==GLFW_PRESS)
	{
		DebugSetting = !DebugSetting;
		//cout<<DebugSetting<<endl;
	}
	if(key == GLFW_KEY_F4&&action==GLFW_PRESS)
	{
		FlySetting = !FlySetting;
	}
}


void RR_prepare(){
	translation.init();
 	glfwSetKeyCallback(RG_MainWindow->win(), RR_KeyEvent);

  RG_LoadFont("data/images/other/Font.ttf",46);	
  uint countTextures = 8;
	string NamesTextures[countTextures] = 
	{
		"data/images/gui/Logo.png",
		"data/images/world/blocks/stone.png",
		"data/images/world/blocks/grass.png",
		"data/images/world/blocks/dirt.png",
		"data/images/gui/SwitchOn.png",
		"data/images/gui/SwitchOff.png",
		"data/images/gui/Plus.png",
		"data/images/gui/Minus.png"
	};

	string NamesId[countTextures] = 
	{
		"LogoRinerest",
		"Stone",
		"Grass",
		"Dirt",
		"SwitchOn",
		"SwitchOff",
		"Plus",
		"Minus"
	};

  RG_LoadsTextures.resize(countTextures);

  //RG_LoadsTexture temp;


	RG_FOR_CYCLEi(countTextures)
	{
		RG_LoadsTextures[i].texture = RG_LoadTexture(NamesTextures[i]);
		//temp.texture = RG_LoadTexture(NamesTextures[i]);
		RG_LoadsTextures[i].name = NamesId[i];
	//return -101;
	}
  RG_EX_PreparationAtlas();
}


int main(){
	RG_MainKeyEvent = &RR_KeyEvent;
	RG_SettingWindow set;
	#ifdef _WIN64
	set.name = "Rinerest InDev.7";
	#else
	set.name = "Rinerest InDev.7 x32";
	#endif
	
	RG_Array<int(*)(int)> funcs;
	funcs.append(RR_Menu);
	funcs.append(RR_Settings);
	funcs.append(RR_Worlds);
	funcs.append(RR_Game);
	return Rinegine_Start(funcs,RR_prepare,set);
}
