#pragma once

int RR_Worlds(int LastLoc){
	if(LastLoc == LOC_GAME) return LOC_MENU;

  int NowPlay = 0;
	RR_MainCamera.reset();
  SetLocate(LOC_WORLDS);
  bool play = true;
	//RG_Object bt_exit_to_menu;
	//RG_Text tx_exit_to_menu;
	//RG_CreateObject(bt_exit_to_menu,{-0.175*2,-450/RG_MainSizeWindow,0},{0.175,0.02,1},{0,0,0},{0,0,0,0.3},2,-1,true,RG_GUI_LINK_LEFT_TOP);
	/*if(LastLoc == LOC_GAME){
		RG_CreateObject(bt_exit_to_menu,{0.26,-0.12,0},{0.26,0.12},{0},{0.1,0.1,0.1,0.6},1,-1,true,RG_GUI_LINK_LEFT_TOP);//RG_GUI_LINK_CENTER_CENTER);//
		RG_CreateText(tx_exit_to_menu,translation.getWstring(L"rinerest:back_to_menu"),bt_exit_to_menu);
	}else{*/
	//RG_CreateObject(bt_exit_to_menu,{0.2,-0.08,0},{0.2,0.08},{0},{0.1,0.1,0.1,0.6},1,-1,true,RG_GUI_LINK_LEFT_TOP);//RG_GUI_LINK_CENTER_CENTER);//
	//RG_CreateText(tx_exit_to_menu,translation.getWstring(L"rinerest:back"),bt_exit_to_menu);
	//tx_exit_to_menu.setColor({0,1,0,1});
	
	RG_Text tx_createWorld;
	RG_CreateText(tx_createWorld,translation.getWstring(L"rinerest:create_world"),{0,-0.09},2,true,RG_GUI_LINK_CENTER_TOP,1);
	tx_createWorld.setColor({0,1,0,1});
	RG_Object back_files_fon;
	RG_CreateObject(back_files_fon,{0,0,0},{2000,0.8,0},{0},{0.1,0.1,0.1,0.4},1,-1,true,RG_GUI_LINK_CENTER_CENTER);
	RG_Text tx_InDev;
	RG_CreateText(tx_InDev,translation.getWstring(L"rinerest:indev"),{0,0,0},3,true,RG_GUI_LINK_CENTER_CENTER,true);
	tx_InDev.setColor({0,1,0,1});

	RG_Text tx_create_now;
	RG_Object bt_create_now;
	RG_CreateObject(bt_create_now,{0.4,0.1},{0.36,0.08},{},{0.1,0.1,0.1,0.6},1,-1,true,RG_GUI_LINK_LEFT_BOTTOM);
	RG_CreateText(tx_create_now,translation.getWstring(L"rinerest:create_new_world"),bt_create_now);
	tx_create_now.setColor({0,1,0,1});
  while(play){
		RG_PollEvents(RR_MainTimer);
		if(glfwWindowShouldClose(RG_MainWindow->win())) {play = false;NowPlay = LOC_EXIT;}
		if(RG_KEYS[GLFW_KEY_ESCAPE] == GLFW_PRESS) {play = false;NowPlay = LastLoc;RG_KEYS[GLFW_KEY_ESCAPE] = GLFW_RELEASE;}
		if(RG_KEYS[GLFW_KEY_ENTER] == GLFW_PRESS) {play = false;NowPlay = LOC_GAME;RG_KEYS[GLFW_KEY_ENTER] = GLFW_RELEASE;}

		/*switch(RG_Action(bt_exit_to_menu)){
			case 0: tx_exit_to_menu.setColor({0,1,0,1}); break;
			case 1: tx_exit_to_menu.setColor({0,0.7,0,1}); break;
			case 2: play = false; NowPlay = LastLoc; break;
		}*/
		switch(RG_Action(bt_create_now)){
			case 0: tx_create_now.setColor({0,1,0,1}); break;
			case 1: tx_create_now.setColor({0,0.7,0,1}); break;
			case 2: play = false; NowPlay = LOC_GAME; break;
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    RG_Draw(RR_BACKGROUND);
		RG_Draw(back_files_fon);
		tx_createWorld.draw();
		tx_InDev.draw();
		RG_Draw(bt_create_now);
		tx_create_now.draw();
		//RG_Draw(bt_exit_to_menu);
		//tx_exit_to_menu.draw();
		RG_UpdateStates();
  }
  return NowPlay;
}