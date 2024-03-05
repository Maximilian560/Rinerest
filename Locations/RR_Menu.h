#pragma ocnce
///////////////////////////////menu
int RR_Menu(int LastLoc){
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
	//RG_CreateText(tx_start, translation.getWstring(L"rinerest:start"), {-0.175*2,-450/RG_MainSizeWindow,0},1,true, RG_GUI_LINK_RIGHT_TOP,true);
	RG_CreateText(tx_start, translation.getWstring(L"rinerest:start"),bt_start,(1/2.));
	RG_Text tx_settings;
	//RG_CreateText(tx_settings, translation.getWstring(L"rinerest:settings"), {-0.175*2,-650/RG_MainSizeWindow,0},1,true, RG_GUI_LINK_RIGHT_TOP,true);
	RG_CreateText(tx_settings, translation.getWstring(L"rinerest:settings"),bt_settings,(1/2.));

	RG_Text tx_exit;
	//RG_CreateText(tx_exit, translation.getWstring(L"rinerest:exit"), {-0.175*2,-850/RG_MainSizeWindow,0},1,true, RG_GUI_LINK_RIGHT_TOP,true);
	RG_CreateText(tx_exit, translation.getWstring(L"rinerest:exit"),bt_exit,(1/2.));
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
	int RGMajor,RGMinor,RGPatch;
	RG_GetVersion(RGMajor,RGMinor,RGPatch);

	RG_Text RINEGINE;
	RG_CreateText(RINEGINE,L"Powered by Rinegine v"+to_wstring(RGMajor)+L'.'+to_wstring(RGMinor)+L'.'+to_wstring(RGPatch),{-0,RG_SIZEFONT/RG_MainSizeWindow},0.5,true,RG_GUI_LINK_RIGHT_BOTTOM);
	RINEGINE.setColor({0,0,0,1});
	RINEGINE.setPos({-RINEGINE.getSizeWord(0)/RG_MainSizeWindow*0.5,RG_SIZEFONT/RG_MainSizeWindow*0.5});
	RINEGINE.update();




	RR_MainCamera.to2D();
	while(play){
		
		RG_PollEvents(RR_MainTimer);


		if(glfwWindowShouldClose(RG_MainWindow->win())) {play = false;NowPlay = LOC_EXIT;}
		if(RG_KEYS[GLFW_KEY_ESCAPE] == GLFW_PRESS) {play = false;NowPlay = LOC_EXIT;RG_KEYS[GLFW_KEY_ESCAPE] = GLFW_RELEASE;}

		if(RG_KEYS[GLFW_KEY_ENTER] == GLFW_PRESS) {play = false;NowPlay = LOC_WORLDS;RG_KEYS[GLFW_KEY_ENTER] = GLFW_RELEASE;}
		
		if(DebugSetting)SHOW_FPS_RR.setString(L"FPS:"+to_wstring((int)RR_MainTimer.getFPS()));



		switch(RG_Action(bt_start))
		{
		case 0: tx_start.setColor({0,1,0,1}); break;
		case 1: tx_start.setColor({0,0.7,0,1}); break;
		case 2: play = false;NowPlay = LOC_WORLDS; break;
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
