#pragma once

//////////////////////////////settings
int RR_Settings(int LastLoc){
	RR_MainCamera.reset();
  int NowPlay = LastLoc;
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
		if(RG_KEYS[GLFW_KEY_ESCAPE] == GLFW_PRESS) {play = false;NowPlay = LastLoc;RG_KEYS[GLFW_KEY_ESCAPE] = GLFW_RELEASE;}
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
