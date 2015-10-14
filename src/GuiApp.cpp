/*
 * GuiApp.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: arturo
 */

#include "GuiApp.h"

void GuiApp::setup(){
	
    mainG.setName("parameters");
    mainG.add(FrameRate.set("FrameRate", ""));
    mainG.add(windowsAlpha.set("WindowsAlpha", 255, 0, 255));
    mainG.add(audioInputOnOff.set("AuioOnOff", false));
    
    glungeWinterG.setName("GlungeWinter");
    glungeWinterG.add( OnOff_GlungeWinter.set("On/Off", false) );

    liveCamGlitchG.setName("LiveCamGlitch");
    liveCamGlitchG.add( OnOff_LiveCamGlitch.set("On/Off", false) );

    labyrinthG.setName("Labyrinth");
    labyrinthG.add( OnOff_Labyrinth.set("On/Off", false) );

	main.setup(mainG);
    main.setPosition(10, 10);

    glungeWinter.setup(glungeWinterG);
    glungeWinter.setPosition(10, 100);
    
    liveCamGlitch.setup(liveCamGlitchG);
    liveCamGlitch.setPosition(10, 150);

    labyrinth.setup(labyrinthG);
    labyrinth.setPosition(10, 200);

    ofBackground(30);
	ofSetVerticalSync(false);
    
}

void GuiApp::update(){

    FrameRate = ofToString( ofGetFrameRate(), 2 );

}

void GuiApp::draw(){

    main.draw();
    glungeWinter.draw();
    liveCamGlitch.draw();
    labyrinth.draw();
    
}
