#pragma once

#define RG_GRAPH
#define RG_EXPEREMENTAL
#define RG_ADDONS
#define RG_SOUND

#include "../Rinegine/Rinegine.h"


enum Location
{
	LOC_EXIT = -1,
	LOC_MENU,
	LOC_SETTINGS,
	LOC_GAME,
};
///////////////////////////////////////SETS

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
///////////////////////////////menu
int RR_Menu(){
	//cout<<"Menu\n";
	RR_MainCamera.reset();
  int NowPlay = LOC_EXIT;
	//cout<<"loc\n";
	SetLocate(LOC_MENU);
	//cout<<"setloc\n";
	if(!RR_INIT){
		RR_INIT = 1;
		//RG_CreateBackground(RR_BACKGROUND,RG_BG_GradientVertical,{0,102./255.,192./255.,1},{0,191./255,0,1});
		RG_CreateBackground(RR_BACKGROUND,RG_BG_GradientVertical,{0,72./255.,255./255.,1},{0,191./255,0,1});

		RG_CreateText(SHOW_FPS_RR,{0.,-(float)RG_SIZEFONT/RG_MainSizeWindow*0.5},0.5,true,RG_GUI_LINK_LEFT_TOP );
		SHOW_FPS_RR.setPos({0,-(float)RG_SIZEFONT/RG_MainSizeWindow*0.5});
		SHOW_FPS_RR.setColor((COLOR4D<double>){1,1,1});
		SHOW_FPS_RR.update();

	}
	bool play = true;
	RG_Object logoRinerest;
	RG_CreateObject(logoRinerest,{-0.18*2,-200/RG_MainSizeWindow,0},{0.8,0.4,1},{0,0,0},{1,1,1,1},3,RG_GetTexture("LogoRinerest"),true,RG_GUI_LINK_RIGHT_TOP);


	RG_Object bt_start;
	RG_CreateObject(bt_start,{-0.175*2,-450/RG_MainSizeWindow,0},{0.175,0.02,1},{0,0,0},{0,0,0,0.3},2,-1,true,RG_GUI_LINK_RIGHT_TOP);
	RG_Object bt_settings;
	RG_CreateObject(bt_settings,{-0.175*2,-650/RG_MainSizeWindow,0},{0.175,0.02,1},{0,0,0},{0,0,0,0.3},2,-1,true,RG_GUI_LINK_RIGHT_TOP);
	RG_Object bt_exit;
	RG_CreateObject(bt_exit,{-0.175*2,-850/RG_MainSizeWindow,0},{0.175,0.02,1},{0,0,0},{0,0,0,0.3},2,-1,true,RG_GUI_LINK_RIGHT_TOP);
	
	RG_Text tx_start;
	RG_CreateText(tx_start, translation.getWstring(L"rinerest:start"), {-0.175*2,-450/RG_MainSizeWindow,0},1,true, RG_GUI_LINK_RIGHT_TOP,true);

	RG_Text tx_settings;
	RG_CreateText(tx_settings, translation.getWstring(L"rinerest:settings"), {-0.175*2,-650/RG_MainSizeWindow,0},1,true, RG_GUI_LINK_RIGHT_TOP,true);

	RG_Text tx_exit;
	RG_CreateText(tx_exit, translation.getWstring(L"rinerest:exit"), {-0.175*2,-850/RG_MainSizeWindow,0},1,true, RG_GUI_LINK_RIGHT_TOP,true);
	tx_start.setColor({0,1,0,1});
	tx_settings.setColor({0,1,0,1});
	tx_exit.setColor({0,1,0,1});
	

	int major,minor,revision;
	glfwGetVersion(&major, &minor, &revision);

	RG_Text DriverVersion;
	RG_CreateText(DriverVersion,L"OpenGL: "+converter.from_bytes((char*)glGetString(GL_VERSION))+L" GLFW Version: "+to_wstring(major)+L"."+to_wstring(minor)+L"."+to_wstring(revision),{0,(float)RG_SIZEFONT/RG_MainSizeWindow*0.5},0.5,true,RG_GUI_LINK_LEFT_BOTTOM);
	DriverVersion.setColor({0,0,0,1});
	DriverVersion.setPos({0,(float)RG_SIZEFONT/RG_MainSizeWindow*0.5});
	DriverVersion.update();
	
	DriverVersion.setColor((COLOR4D<double>){0,0,0});
	
	RG_Text RINEGINE;
	RG_CreateText(RINEGINE,L"Powered by Rinegine",{-0,RG_SIZEFONT/RG_MainSizeWindow},0.5,true,RG_GUI_LINK_RIGHT_BOTTOM);
	RINEGINE.setColor({0,0,0,1});
	RINEGINE.setPos({-RINEGINE.getSizeWord(0)/RG_MainSizeWindow*0.5,RG_SIZEFONT/RG_MainSizeWindow*0.5});
	RINEGINE.update();




	RR_MainCamera.to2D();
	while(play){
		
		RG_PollEvents(RR_MainTimer);
		glfwGetCursorPos(RG_MainWindow->win(), &MPos.x, &MPos.y);

		

	//cout<<"if ex\n";
		if(glfwWindowShouldClose(RG_MainWindow->win())) {play = false;NowPlay = LOC_EXIT;}
		if(RG_KEYS[GLFW_KEY_ESCAPE] == GLFW_PRESS) {play = false;NowPlay = LOC_EXIT;RG_KEYS[GLFW_KEY_ESCAPE] = GLFW_RELEASE;}

		if(RG_KEYS[GLFW_KEY_ENTER] == GLFW_PRESS) {play = false;NowPlay = LOC_GAME;RG_KEYS[GLFW_KEY_ESCAPE] = GLFW_RELEASE;}
		
		if(DebugSetting)SHOW_FPS_RR.setString(L"FPS:"+to_wstring((int)RR_MainTimer.getFPS()));



		switch(RG_Action(bt_start))
		{
		case 0: tx_start.setColor({0,1,0,1}); break;
		case 1: tx_start.setColor({0,0.7,0,1}); break;
		case 2: play = false;NowPlay = LOC_GAME; break;
		}

		switch(RG_Action(bt_settings))
		{
		case 0: tx_settings.setColor({0,1,0,1}); break;
		case 1: tx_settings.setColor({0,0.7,0,1}); break;
		case 2: play = false;NowPlay = LOC_SETTINGS; break;
		}
		

		switch(RG_Action(bt_exit))
		{
		case 0: tx_exit.setColor({0,1,0,1}); break;
		case 1: tx_exit.setColor({0,0.7,0,1}); break;
		case 2: play = false;NowPlay = LOC_EXIT; break;
		}
		


	////////////////////////DRAWWWWWWWWWWW!!!!!!!!!!!!!!!!!!!!!!
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    RG_Draw(RR_BACKGROUND);
    RG_Draw(logoRinerest);
    RG_Draw(bt_start);
    RG_Draw(bt_settings);
    RG_Draw(bt_exit);
		tx_start.draw();
		tx_settings.draw();
		tx_exit.draw();

		DriverVersion.draw();
		RINEGINE.draw();

		if(DebugSetting)SHOW_FPS_RR.draw();


		RG_UpdateStates();//////////////////ВАЖНО! ОБНОВЛЕНИЕ СОСТОЯНИЯ ОКНА!!!!!!!!!!!!!!!!!
	}

	return NowPlay;
}


//////////////////////////////settings
int RR_Settings(){
	RR_MainCamera.reset();
  int NowPlay = LOC_MENU;
	//cout<<"loc\n";
	SetLocate(LOC_SETTINGS);
	//cout<<"setloc\n";
	bool play = true;
	
	

	RG_Text RINEGINE;
	RG_CreateText(RINEGINE,L"Powered by Rinegine",{-0,RG_SIZEFONT/RG_MainSizeWindow},0.5,true,RG_GUI_LINK_RIGHT_BOTTOM);
	RINEGINE.setColor({0,0,0,1});
	RINEGINE.setPos({-RINEGINE.getSizeWord(0)/RG_MainSizeWindow*0.5,RG_SIZEFONT/RG_MainSizeWindow*0.5});
	RINEGINE.update();



	RG_Object bt_game;
	RG_Object bt_graph;
	RG_Object bt_control;
	RG_Object bt_other;

	RG_CreateObject(bt_game,	{-1./3.,-1./16.*(2+4.1*0),0},	{1./3.,(1/8.),1},{0,0,0},{0,0,0,0.3},1,-1,true,RG_GUI_LINK_RIGHT_TOP);
	RG_CreateObject(bt_graph,		{-1./3.,-1./16.*(2+4.1*1),0},	{1./3.,(1/8.),1},{0,0,0},{0,0,0,0.3},1,-1,true,RG_GUI_LINK_RIGHT_TOP);
	RG_CreateObject(bt_control,	{-1./3.,-1./16.*(2+4.1*2),0},	{1./3.,(1/8.),1},{0,0,0},{0,0,0,0.3},1,-1,true,RG_GUI_LINK_RIGHT_TOP);
	RG_CreateObject(bt_other,	{-1./3.,-1./16.*(2+4.1*3),0},	{1./3.,(1/8.),1},{0,0,0},{0,0,0,0.3},1,-1,true,RG_GUI_LINK_RIGHT_TOP);

	RG_Text tx_game;
	RG_Text tx_graph;
	RG_Text tx_control;
	RG_Text tx_other;
	
	RG_CreateText(tx_game,translation.getWstring(L"rinerest:game"),bt_game);
	RG_CreateText(tx_graph, translation.getWstring(L"rinerest:graphics"),bt_graph);
	RG_CreateText(tx_control, translation.getWstring(L"rinerest:control"),bt_control);
	RG_CreateText(tx_other,  translation.getWstring(L"rinerest:other"),bt_other);
	tx_game.setColor({0,1,0,1});
	tx_graph.setColor({0,1,0,1});
	tx_control.setColor({0,1,0,1});
	tx_other.setColor({0,1,0,1});	
	uint set = 0;


	/////////////////set 0:
	//DEBUG SETTINGS
	RG_Text DebugSet;
	RG_Object DebugSwitch;
	int texturesSwitch[2] = {RG_GetTexture("SwitchOff"),RG_GetTexture("SwitchOn")};
	RG_CreateText(DebugSet,translation.getWstring(L"rinerest:debugsetting"),{3/RG_MainSizeWindow,-150/RG_MainSizeWindow},1,true,RG_GUI_LINK_LEFT_TOP);

	RG_CreateAnimObject(DebugSwitch,	{(DebugSet.getSizeWord(0)+100)/RG_MainSizeWindow,-150/RG_MainSizeWindow,0},	{0,0,0},{0,0,0},{1,1,1,1},6,RG_Array<int>(sizeof(texturesSwitch)/sizeof(int),texturesSwitch),true,RG_GUI_LINK_LEFT_TOP);
	
	//FLY SETTINGS
	RG_Text FlySet;
	RG_Object FlySwitch;

	RG_CreateText(FlySet,translation.getWstring(L"rinerest:flysetting"),{3/RG_MainSizeWindow,-250/RG_MainSizeWindow},1,true,RG_GUI_LINK_LEFT_TOP);

	RG_CreateAnimObject(FlySwitch,	{(FlySet.getSizeWord(0)+100)/RG_MainSizeWindow,-250/RG_MainSizeWindow,0},	{0,0,0},{0,0,0},{1,1,1,1},6,RG_Array<int>(sizeof(texturesSwitch)/sizeof(int),texturesSwitch),true,RG_GUI_LINK_LEFT_TOP);



	//MSAA SETTING

	RG_Text MSAASet;
	RG_Object MSAASwitch;
	RG_Object bt_apply;
	RG_Text tx_apply;
	RG_CreateText(MSAASet,translation.getWstring(L"rinerest:msaasetting"),{3/RG_MainSizeWindow,-150/RG_MainSizeWindow},1,true,RG_GUI_LINK_LEFT_TOP);

	RG_CreateAnimObject(MSAASwitch,	{(MSAASet.getSizeWord(0)+100)/RG_MainSizeWindow,-150/RG_MainSizeWindow,0},	{0,0,0},{0,0,0},{1,1,1,1},6,RG_Array<int>(sizeof(texturesSwitch)/sizeof(int),texturesSwitch),true,RG_GUI_LINK_LEFT_TOP);
	
	RG_CreateObject(bt_apply,	{1./4.,0.07,0},{1./4.,0.07,1},{0,0,0},{0,0,0,0.3},1.2,-1,true, RG_GUI_LINK_LEFT_BOTTOM);
	RG_CreateText(tx_apply,translation.getWstring(L"rinerest:apply"),bt_apply);
	tx_apply.setColor({0,1,0,1});
	//VSYN SETTING

	RG_Text VSynSet;
	RG_Text VSynCount;

	RG_Object bt_vsplus;
	RG_Object bt_vsminus;

	RG_CreateText(VSynSet,translation.getWstring(L"rinerest:vssetting"),{3/RG_MainSizeWindow,-250/RG_MainSizeWindow},1,true,RG_GUI_LINK_LEFT_TOP);
	RG_CreateText(VSynCount,{(VSynSet.getSizeWord(0)+70.)/RG_MainSizeWindow,-250/RG_MainSizeWindow},1,true,RG_GUI_LINK_LEFT_TOP);
	

	RG_CreateObject(bt_vsplus,{(VSynSet.getSizeWord(0)+170)/RG_MainSizeWindow,(-250)/RG_MainSizeWindow,0},	{0,0,0},{0,0,0},{1,1,1,1},6,RG_GetTexture("Plus"),true,RG_GUI_LINK_LEFT_TOP);
	RG_CreateObject(bt_vsminus,{(VSynSet.getSizeWord(0)+300)/RG_MainSizeWindow,(-250)/RG_MainSizeWindow,0},	{0,0,0},{0,0,0},{1,1,1,1},6,RG_GetTexture("Minus"),true,RG_GUI_LINK_LEFT_TOP);


	/////////////////set 2:


	/////////////////set 3:

	RG_Text indev;
	RG_CreateText(indev,translation.getWstring(L"rinerest:indev"),{0,0},2,true,RG_GUI_LINK_CENTER_CENTER); 
	indev.setPos({-indev.getSizeWord(0)/RG_MainSizeWindow/2.,0});
	indev.setColor({0.8,0,0});
	indev.update();

	RR_MainCamera.to2D();
	
	while(play)
	{
	//cout<<"event\n";
		RG_PollEvents(RR_MainTimer);
		glfwGetCursorPos(RG_MainWindow->win(), &MPos.x, &MPos.y);
	
	//cout<<"if ex\n";
		if(glfwWindowShouldClose(RG_MainWindow->win())) {play = false;NowPlay = LOC_EXIT;}

	//cout<<"if esc\n";
		if(RG_KEYS[GLFW_KEY_ESCAPE] == GLFW_PRESS) {play = false;NowPlay = LOC_MENU;RG_KEYS[GLFW_KEY_ESCAPE] = GLFW_RELEASE;}
		if(DebugSetting)SHOW_FPS_RR.setString(L"FPS:"+to_wstring((int)RR_MainTimer.getFPS()));

	//cout<<"update states\n";

		switch(RG_Action(bt_game))
		{
		case 0: tx_game.setColor({0,1,0,1}); break;
		case 1: tx_game.setColor({0,0.7,0,1}); break;
		case 2: set = 0; break;
		}
		switch(RG_Action(bt_graph))
		{
		case 0: tx_graph.setColor({0,1,0,1}); break;
		case 1: tx_graph.setColor({0,0.7,0,1}); break;
		case 2: set = 1; break;
		}
		switch(RG_Action(bt_control))
		{
		case 0: tx_control.setColor({0,1,0,1}); break;
		case 1: tx_control.setColor({0,0.7,0,1}); break;
		case 2: set = 2; break;
		}
		switch(RG_Action(bt_other))
		{
		case 0: tx_other.setColor({0,1,0,1}); break;
		case 1: tx_other.setColor({0,0.7,0,1}); break;
		case 2: set = 3; break;
		}




	////////////////////////DRAWWWWWWWWWWW!!!!!!!!!!!!!!!!!!!!!!
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    RG_Draw(RR_BACKGROUND);
		RG_Draw(bt_game);
		RG_Draw(bt_graph);
		RG_Draw(bt_control);
		RG_Draw(bt_other);
		tx_game.draw();
		tx_graph.draw();
		tx_control.draw();
		tx_other.draw();
		
		RINEGINE.draw();

		if(DebugSetting)SHOW_FPS_RR.draw();



	switch(set)
		{case 0: 
			
			
			RG_ActionSwitch(DebugSwitch,DebugSetting);

			RG_ActionSwitch(FlySwitch,FlySetting);


			//if((ActionBut(bt_distplus)==1&&ActionBut(bt_distminus)!=2)||(ActionBut(bt_distminus)==1&&ActionBut(bt_distplus)!=2))SpeenTemp = 0;
			

			if(RG_MOUSE[0]==GLFW_RELEASE)
			{
				//if(ActionBut(bt_distplus)!=2&&ActionBut(bt_distminus)!=2) 
				SpeenTemp = 1;
				SpeedSpeen = 1.6;
				StageSpeen = 0;
			}
			
			//if(ActionBut(bt_sptplus,true)==2&&SizePlat<9999)SizePlat+=15*timer.getBias();
			//if(ActionBut(bt_sptminus,true)==2&&SizePlat>1)SizePlat-=15*timer.getBias();


			RG_Draw(DebugSwitch);
			RG_Draw(FlySwitch);

		

			DebugSet.draw();
			FlySet.draw();



		break;case 1: 
			
			if(RG_Action(bt_vsplus)==2&&VSyn<9){VSyn++;}
			if(RG_Action(bt_vsminus)==2&&VSyn>0){VSyn--;}

			VSynCount.setString(to_wstring((uint)VSyn));

			RG_Draw(bt_apply);
			tx_apply.draw();
			RG_ActionSwitch(MSAASwitch,MSAASetting);
			RG_Draw(MSAASwitch);

			RG_Draw(bt_vsplus);
			RG_Draw(bt_vsminus);

			MSAASet.draw();

			VSynSet.draw();

			VSynCount.draw();

			switch(RG_Action(bt_apply))
			{
			case 0: tx_apply.setColor({0,1,0,1}); break;
			case 1: tx_apply.setColor({0,0.7,0,1}); break;
			case 2: if(MSAASetting){glEnable(GL_MULTISAMPLE); MSAASettingReal = true;}
					else {glDisable(GL_MULTISAMPLE);MSAASettingReal = false;} 
					VSynReal = VSyn; RG_MainWindow->setVsyn(VSynReal);
					break;
			}
			

			
		break;case 2: 
				
			indev.draw();
			
		break;case 3: 
			
			indev.draw();

		break;
		default:indev.draw();
		}




		
		RG_UpdateStates();//////////////////ВАЖНО! ОБНОВЛЕНИЕ СОСТОЯНИЯ ОКНА!!!!!!!!!!!!!!!!!
	}

	return NowPlay;
}


int RR_Game(){
		//cout<<"Menu\n";
	RR_MainCamera.reset();
	RG_Player Player1;

	RG_Text coordCam;
	RG_Text angleCam;
	RG_Text zoomCam;
	RG_Text colissionsPlayer;

	RG_CreateText(coordCam,{-0,-70/RG_MainSizeWindow,0},0.5,true,RG_GUI_LINK_LEFT_TOP,1);
	RG_CreateText(angleCam,{-0,-120/RG_MainSizeWindow,0},0.5,true,RG_GUI_LINK_LEFT_TOP,1);
	RG_CreateText(zoomCam,{-0,-170/RG_MainSizeWindow,0},0.5,true,RG_GUI_LINK_LEFT_TOP,1);
	RG_CreateText(colissionsPlayer,{-0,-220/RG_MainSizeWindow,0},0.5,true,RG_GUI_LINK_LEFT_TOP,1);

	coordCam.setColor((COLOR4D<double>){1,1,1});
	angleCam.setColor((COLOR4D<double>){1,1,1});
	zoomCam.setColor((COLOR4D<double>){1,1,1});
	colissionsPlayer.setColor((COLOR4D<double>){1,1,1});
  int NowPlay = LOC_MENU;
	//cout<<"loc\n";
	SetLocate(LOC_GAME);
	bool play = true;
	RG_World world;
	RG_Object cube;
	RG_ObjFile cube_file;
	RG_rgobjFileLoad(cube_file,"data/objects/cube.rgobj");
	int BlocksTextures[3] = {
      RG_GetTexture("Grass"),
      RG_GetTexture("Dirt"),
      RG_GetTexture("Stone")
	};
	RG_Create3DAnimObject(cube,{-100,-10,0},{1,1,1},{0,0,0},1,RG_Array<int>(3,BlocksTextures),cube_file);
	world.init(time(0));
	//exit(-2);
	//Player1.set_pos({-world.size().x*50./2.,-world.size().y*50.,-world.size().z*50./2.});
	double RealSpeed = 50*7;
	double speed = 0;

	POINT3D<double>AngleCam;
	//POINT3D<double>PosCam = {-world.size().x*50./2.,-world.size().y*50.,-world.size().z*50./2.};
	//Player1.set_pos(PosCam);
	Player1.ConectToWorld(world);
	Player1.set_pos({-world.size().x*50./2.,-world.size().y*50.,-world.size().z*50./2.});
	Player1.set_size({75,100,75});
	StandartCam.setRotate({50,30,-75});
	//StandartCam.setZoom({2});
	RR_MainCamera.to3D();
	if (glfwRawMouseMotionSupported())
   		{
   			glfwSetInputMode(RG_MainWindow->win(), GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
   		}
	glfwSetInputMode (RG_MainWindow->win(), GLFW_CURSOR , GLFW_CURSOR_DISABLED );//TODO
	glfwSetCursorPos(RG_MainWindow->win(),RG_MainWindow->set().resolution.x/2.,RG_MainWindow->set().resolution.y/2.);

	double impulsUp = 0;
	double strongDown = 9.8;
	//bool OnGround = false;
	glClearColor(0.7,0.86,0.99,0.1);
	//RG_Matrix<int>PlayerCollision(2,2);
	RG_Collisions PlayerColNow;
	//RG_Draw(cube);
	while(play)
	{
		POINT3D<double>PosCam;
		RG_PollEvents(RR_MainTimer);
		glfwGetCursorPos(RG_MainWindow->win(), &MPos.x, &MPos.y);

		if(glfwGetKey(RG_MainWindow->win(),GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS){
               RealSpeed = 50*25;
        }else if(glfwGetKey(RG_MainWindow->win(),GLFW_KEY_LEFT_ALT) == GLFW_PRESS){
               RealSpeed = 50*1;
        }else{
               RealSpeed = 50*7;
        }
		speed = RR_MainTimer.getBias() * RealSpeed;
	
		
		if(glfwWindowShouldClose(RG_MainWindow->win())) {play = false;NowPlay = LOC_EXIT;}
		if(RG_KEYS[GLFW_KEY_ESCAPE] == GLFW_PRESS) {play = false;NowPlay = LOC_MENU;RG_KEYS[GLFW_KEY_ESCAPE] = GLFW_RELEASE;}

		/*switch(){
			case -1:Player1.set_pos({-world.size().x*50./2.,-world.size().y*50.,-world.size().z*50./2.});break;
			case 0:Player1.move({0,speed,0});
			case 1:if(world.get_block((-Player1.get_pos().x+25)/50.,(-Player1.get_pos().y/50.)-3,(-Player1.get_pos().z+30)/50.)==1)Player1.move({0,-50,0});
		}*/
		
		if ( glfwGetWindowAttrib (RG_MainWindow->win(), GLFW_HOVERED ))
        {

    
            AngleCam.x+=((MPos.x-RG_MainWindow->set().resolution.x/2.)/3.)/(RR_MainCamera.getZoom()>=1?rg_max(1,(RR_MainCamera.getZoom()*(abs(AngleCam.y/90.)))):1);
            AngleCam.y+=((MPos.y-RG_MainWindow->set().resolution.y/2.)/3.)/(RR_MainCamera.getZoom()>=1?RR_MainCamera.getZoom():1);

            glfwSetCursorPos(RG_MainWindow->win(),RG_MainWindow->set().resolution.x/2.,RG_MainWindow->set().resolution.y/2.);

        }
        if(AngleCam.y>90)AngleCam.y=90;
        if(AngleCam.y<-90)AngleCam.y=-90;
        if(AngleCam.x>180)AngleCam.x-=360;
        if(AngleCam.x<-180)AngleCam.x+=360;



		if(impulsUp>0){
			PosCam.y-=impulsUp;	
			impulsUp-=strongDown/2.;
		}else if(impulsUp<0){
			impulsUp = 0;
		}



		if(glfwGetKey(RG_MainWindow->win(),GLFW_KEY_SPACE) == GLFW_PRESS){
			if(FlySetting){
				PosCam.y -= speed;
			}else{
				if(Player1.on_ground())
				impulsUp = 1.2*25;
			}
		}
		if(FlySetting){
			if(glfwGetKey(RG_MainWindow->win(),GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)PosCam.y += speed;
			//if(glfwGetKey(RG_MainWindow->win(),GLFW_KEY_SPACE) == GLFW_PRESS)	PosCam.y -= speed;
		}

		if(glfwGetKey(RG_MainWindow->win(),GLFW_KEY_W) == GLFW_PRESS||glfwGetKey(RG_MainWindow->win(),GLFW_KEY_UP) == GLFW_PRESS){
			/*Player1.move({
			-sin(AngleCam.x / 180. * M_PI)*speed*((AngleCam.x>180)?-1:1),
			0,
			cos(AngleCam.x / 180. * M_PI)*speed*((AngleCam.x>180)?-1:1)
			});*/
			PosCam.x-=sin(AngleCam.x / 180. * M_PI)*speed*((AngleCam.x>180)?-1:1);
			PosCam.z+=cos(AngleCam.x / 180. * M_PI)*speed*((AngleCam.x>180)?-1:1);
    }

    if(glfwGetKey(RG_MainWindow->win(),GLFW_KEY_S) == GLFW_PRESS||glfwGetKey(RG_MainWindow->win(),GLFW_KEY_DOWN) == GLFW_PRESS){
					/*Player1.move({
					sin(AngleCam.x / 180. * M_PI)*speed*((AngleCam.x>180)?-1:1),
					0,
					-cos(AngleCam.x / 180. * M_PI)*speed*((AngleCam.x>180)?-1:1)
					});*/
			PosCam.x+=sin(AngleCam.x / 180. * M_PI)*speed*((AngleCam.x>180)?-1:1);
			PosCam.z-=cos(AngleCam.x / 180. * M_PI)*speed*((AngleCam.x>180)?-1:1);
    }
    if(glfwGetKey(RG_MainWindow->win(),GLFW_KEY_A) == GLFW_PRESS||glfwGetKey(RG_MainWindow->win(),GLFW_KEY_LEFT) == GLFW_PRESS) {
					/*Player1.move({
					cos(AngleCam.x / 180. * M_PI)*speed*(AngleCam.x>180?-1:1),
					0,
					sin(AngleCam.x / 180. * M_PI)*speed*(AngleCam.x>180?-1:1)
					});*/
			PosCam.x+=cos(AngleCam.x / 180. * M_PI)*speed*(AngleCam.x>180?-1:1);
			PosCam.z+=sin(AngleCam.x / 180. * M_PI)*speed*(AngleCam.x>180?-1:1);
    }
    if(glfwGetKey(RG_MainWindow->win(),GLFW_KEY_D) == GLFW_PRESS||glfwGetKey(RG_MainWindow->win(),GLFW_KEY_RIGHT) == GLFW_PRESS){
				/*Player1.move({
					-cos(AngleCam.x / 180. * M_PI)*speed*(AngleCam.x>180?-1:1),
					0,
					-sin(AngleCam.x / 180. * M_PI)*speed*(AngleCam.x>180?-1:1)
					});*/
			PosCam.x-=cos(AngleCam.x / 180. * M_PI)*speed*(AngleCam.x>180?-1:1);
			PosCam.z-=sin(AngleCam.x / 180. * M_PI)*speed*(AngleCam.x>180?-1:1);
		}
		if(RG_KEYS[GLFW_KEY_1]==GLFW_PRESS){Player1.choise_block(RG_WBT_Grass);RG_KEYS[GLFW_KEY_1]=GLFW_RELEASE;}
		if(RG_KEYS[GLFW_KEY_2]==GLFW_PRESS){Player1.choise_block(RG_WBT_Dirt);RG_KEYS[GLFW_KEY_2]=GLFW_RELEASE;}
		if(RG_KEYS[GLFW_KEY_3]==GLFW_PRESS){Player1.choise_block(RG_WBT_Stone);RG_KEYS[GLFW_KEY_3]=GLFW_RELEASE;}

		Player1.aiming_block();
		if(RG_MOUSE[GLFW_MOUSE_BUTTON_LEFT]==GLFW_PRESS){Player1.break_block();RG_MOUSE[GLFW_MOUSE_BUTTON_LEFT]=GLFW_RELEASE;}
		if(RG_MOUSE[GLFW_MOUSE_BUTTON_RIGHT]==GLFW_PRESS){Player1.set_block();RG_MOUSE[GLFW_MOUSE_BUTTON_RIGHT]=GLFW_RELEASE;}
	/*if(PlayerColNow.Colmx>=0)PosCam = {(rg_min(PosCam.x,Player1.get_pos().x+PlayerColNow.Colmx*50)),PosCam.y,PosCam.z};
		if(PlayerColNow.Colx>=0)PosCam = {(rg_max(PosCam.x,Player1.get_pos().x-PlayerColNow.Colx*50)),PosCam.y,PosCam.z};
		
		if(PlayerColNow.Colmz>=0)PosCam = {(PosCam.x),PosCam.y,rg_min(Player1.get_pos().z+PlayerColNow.Colmz*50,PosCam.z)};
		if(PlayerColNow.Colz>=0)PosCam = {(PosCam.x),PosCam.y,rg_max(Player1.get_pos().z-PlayerColNow.Colz*50,PosCam.z)};*/
		
		if(!FlySetting)PosCam.y+=50*9.8*RR_MainTimer.getBias();
		//PlayerColNow = world.test_collision({75,100,75},{-PosCam.x,-PosCam.y,(-PosCam.z)},true);
		if(DebugSetting){
			SHOW_FPS_RR.setString(L"FPS:"+to_wstring((int)RR_MainTimer.getFPS()));
			coordCam.setString(L"Coord XYZ:"+to_wstring(-RR_MainCamera.getPos().x/50.)+L" "+to_wstring(-RR_MainCamera.getPos().y/50.)+L" "+to_wstring(-RR_MainCamera.getPos().z/50.));
			angleCam.setString(L"Angle XYZ:"+to_wstring(-(int)AngleCam.x)+L" "+to_wstring(-(int)AngleCam.y)+L" "+to_wstring(-(int)AngleCam.z));
			zoomCam.setString(L"Zoom: "+to_wstring(RR_MainCamera.getZoom()));
			colissionsPlayer.setString(L"Collions: x = "+to_wstring(PlayerColNow.Colx)+L" mx = "+to_wstring(PlayerColNow.Colmx)+L" y = "+to_wstring(PlayerColNow.Coly)+L" my = "+to_wstring(PlayerColNow.Colmy)+L"z = "+to_wstring(PlayerColNow.Colz)+L" zm = "+to_wstring(PlayerColNow.Colmz));
		}
		//cout<<"COLISSIONS!\nx = "<<PlayerColNow.Colx<<"\nmx = "<<PlayerColNow.Colmx<<"\ny = "<<PlayerColNow.Coly<<"\nmy = "<<PlayerColNow.Colmy<<"\nz = "<<PlayerColNow.Colz<<"\nzm = "<<PlayerColNow.Colmz<<endl<<endl;
		
		/*if(PlayerColNow.Colmy<0&&!FlySetting)PosCam.y+=speed;
		else{
			if(PlayerColNow.Colmy>0){
				PosCam.y-=PlayerColNow.Colmy*50;
			}
		}*/
		/*if(PlayerColNow.Colmy>0)PosCam.y -=PlayerColNow.Colmy*50;
		//if(PlayerColNow.Colmy>0)PosCam.y -=PlayerColNow.Colmy*50;

		if(PlayerColNow.Colx>=0)PosCam.x += PlayerColNow.Colx*50;
		if(PlayerColNow.Colmx>0)PosCam.x -=PlayerColNow.Colmx*50;

		if(PlayerColNow.Colz>=0)PosCam.z += PlayerColNow.Colz*50;
		if(PlayerColNow.Colmz>=0)PosCam.z -=PlayerColNow.Colmz*50;*/


		/*if(DebugSetting){
			PlayerColNow = world.test_collision({75,100,75},{-PosCam.x,-PosCam.y,(-PosCam.z)},true);
			colissionsPlayer.setString(L"Collions: x = "+to_wstring(PlayerColNow.Colx)+L" mx = "+to_wstring(PlayerColNow.Colmx)+L" y = "+to_wstring(PlayerColNow.Coly)+L" my = "+to_wstring(PlayerColNow.Colmy)+L"z = "+to_wstring(PlayerColNow.Colz)+L" zm = "+to_wstring(PlayerColNow.Colmz));
		}*/
		/*while(PlayerColNow.Colmy>0||PlayerColNow.Colz>0||PlayerColNow.Colmz>0||PlayerColNow.Colx>0||PlayerColNow.Colmx>0){
			if(PlayerColNow.Colmy>=0)PosCam.y -=PlayerColNow.Colmy*50;
	
			if(PlayerColNow.Colmx>=0)PosCam.x -=PlayerColNow.Colmx*50;
			if(PlayerColNow.Colx>=0)PosCam.x += PlayerColNow.Colx*50;

			if(PlayerColNow.Colmz>=0)PosCam.z -=PlayerColNow.Colmz*50;
			if(PlayerColNow.Colz>=0)PosCam.z += PlayerColNow.Colz*50;
			PlayerColNow = world.test_collision({75,100,75},{-PosCam.x,-PosCam.y,(-PosCam.z)},true);
			if(DebugSetting){
				colissionsPlayer.setString(L"Collions: x = "+to_wstring(PlayerColNow.Colx)+L" mx = "+to_wstring(PlayerColNow.Colmx)+L" y = "+to_wstring(PlayerColNow.Coly)+L" my = "+to_wstring(PlayerColNow.Colmy)+L"z = "+to_wstring(PlayerColNow.Colz)+L" zm = "+to_wstring(PlayerColNow.Colmz));
			}
		}*/
		


		/*
		if(PlayerColNow.Colx)PosCam = {(PosCam.x),PosCam.y,PosCam.z};
		if(PlayerColNow.Colmx)PosCam = {(PosCam.x),PosCam.y,PosCam.z};*/


		Player1.move({PosCam.x,PosCam.y,PosCam.z});
		RR_MainCamera.setRotate(AngleCam);
				
				RR_MainCamera.zoom(RG_ScrollMouse.y/16.*RR_MainCamera.getZoom());
        if(RG_MOUSE[2] == GLFW_PRESS){RR_MainCamera.setZoom(1);}


	////////////////////////DRAWWWWWWWWWWW!!!!!!!!!!!!!!!!!!!!!!
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		world.draw();
		if(DebugSetting){
			SHOW_FPS_RR.draw();
			coordCam.draw();
			angleCam.draw();
			zoomCam.draw();
			colissionsPlayer.draw();
		}

		//Player1.update();
		RG_UpdateStates();//////////////////ВАЖНО! ОБНОВЛЕНИЕ СОСТОЯНИЯ ОКНА!!!!!!!!!!!!!!!!!
	
	}

	glfwSetInputMode (RG_MainWindow->win(), GLFW_CURSOR , GLFW_CURSOR_NORMAL );



  if (glfwRawMouseMotionSupported())
	{
		glfwSetInputMode(RG_MainWindow->win(), GLFW_RAW_MOUSE_MOTION, GLFW_FALSE);
	}

	return NowPlay;
}