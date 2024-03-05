#pragma once

int RR_Game(int LastLoc){
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
  int NowPlay = LastLoc;
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
	if (glfwRawMouseMotionSupported()){
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
	//////////PAUSE
	bool is_pause = false;

	/*back_pause
	bt_continue
	bt_back_to_menu
	tx_continue
	tx_back_to_menu*/
	RG_Object back_pause;
	RG_Object bt_continue;
	RG_Object bt_back_to_menu;

	RG_Text tx_continue;
	RG_Text tx_back_to_menu;

	RG_CreateObject(back_pause,{},{2000,1},{},{0.1,0.1,0.1,0.6},1,-1,true,RG_GUI_LINK_CENTER_CENTER);
	RG_CreateObject(bt_continue,{0,0.15},{0.4,0.1},{},{0.1,0.1,0.1,0.6},1,-1,true,RG_GUI_LINK_CENTER_CENTER);
	RG_CreateObject(bt_back_to_menu,{0,-0.15},{0.4,0.1},{},{0.1,0.1,0.1,0.6},1,-1,true,RG_GUI_LINK_CENTER_CENTER);

	RG_CreateText(tx_continue,translation.getWstring(L"rinerest:continue"),bt_continue);
	tx_continue.setColor({0,1,0,1});

	RG_CreateText(tx_back_to_menu,translation.getWstring(L"rinerest:back_to_menu"),bt_back_to_menu);
	tx_back_to_menu.setColor({0,1,0,1});

	bool is_prepare_pause = false;



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
		if(RG_KEYS[GLFW_KEY_ESCAPE] == GLFW_PRESS) {is_pause = true; RG_KEYS[GLFW_KEY_ESCAPE] = GLFW_RELEASE;}

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

		while(is_pause){
		RG_PollEvents(RR_MainTimer);
			if(!is_prepare_pause){
				glfwSetInputMode (RG_MainWindow->win(), GLFW_CURSOR , GLFW_CURSOR_NORMAL );
				is_prepare_pause = true;
			}
			switch(RG_Action(bt_continue)){
				case 0: tx_continue.setColor({0,1,0,1});break;
				case 1: tx_continue.setColor({0,0.7,0,1});break;
				case 2: is_pause = false; is_prepare_pause = false; break;
			}

			switch(RG_Action(bt_back_to_menu)){
				case 0: tx_back_to_menu.setColor({0,1,0,1});break;
				case 1: tx_back_to_menu.setColor({0,0.7,0,1});break;
				case 2: is_pause = false; play = false; NowPlay = LOC_MENU; break;
			}

			if(RG_KEYS[GLFW_KEY_ENTER] == GLFW_PRESS) {
				is_pause = false; 
				RG_KEYS[GLFW_KEY_ENTER] = GLFW_RELEASE;
				is_prepare_pause = false;
			}


			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			world.draw();
			if(DebugSetting){
				SHOW_FPS_RR.draw();
				coordCam.draw();
				angleCam.draw();
				zoomCam.draw();
				colissionsPlayer.draw();
			}
			RG_Draw(back_pause);
			RG_Draw(bt_continue);
			RG_Draw(bt_back_to_menu);

			tx_continue.draw();
			tx_back_to_menu.draw();

			if(!is_prepare_pause){
				glfwSetInputMode (RG_MainWindow->win(), GLFW_CURSOR , GLFW_CURSOR_DISABLED );//TODO	
			}
		RG_UpdateStates();//////////////////ВАЖНО! ОБНОВЛЕНИЕ СОСТОЯНИЯ ОКНА!!!!!!!!!!!!!!!!!

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