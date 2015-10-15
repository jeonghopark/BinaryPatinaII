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
    mainG.add(OnOff_Windows.set("OnOff Windows", false));
    mainG.add(color_Windows.set("Color Windows", ofColor(255,0,0,0), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    
    glungeWinterG.setName("GlungeWinter");
    glungeWinterG.add( OnOff_GlungeWinter.set("On/Off", false) );

    liveCamGlitchG.setName("LiveCamGlitch");
    liveCamGlitchG.add( OnOff_LiveCamGlitch.set("On/Off", false) );

    labyrinthG.setName("Labyrinth");
    labyrinthG.add( OnOff_Labyrinth.set("On/Off", false) );

    calligraphyG.setName("Calligraphy");
    calligraphyG.add( OnOff_Calligraphy.set("On/Off", false) );

    plutoG.setName("Pluto");
    plutoG.add( OnOff_Pluto.set("On/Off", false) );

    indiaTowerG.setName("IndiaTower");
    indiaTowerG.add( OnOff_IndiaTower.set("On/Off", false) );

    trierFlyingCamG.setName("TrierFlyingCam");
    trierFlyingCamG.add( OnOff_TrierFlyingCam.set("On/Off", false) );

    cubicMapFlyingCamG.setName("CubicMapFlyingCam");
    cubicMapFlyingCamG.add( OnOff_CubicMapFlyingCam.set("On/Off", false) );

    moonCreatorG.setName("MoonCreator");
    moonCreatorG.add( OnOff_MoonCreator.set("On/Off", false) );
    
    lineVideoG.setName("LineVideo");
    lineVideoG.add( OnOff_LineVideo.set("On/Off", false) );

    movingObjectG.setName("MovingObject");
    movingObjectG.add( OnOff_MovingObject.set("On/Off", false) );

    droneAttackG.setName("DroneAttack");
    droneAttackG.add( OnOff_DroneAttack.set("On/Off", false) );

    webLiveCamG.setName("WebLiveCam");
    webLiveCamG.add( OnOff_WebLiveCam.set("On/Off", false) );

    
    
    
    
	main.setup(mainG);
    main.setPosition(10, 10);

    glungeWinter.setup(glungeWinterG);
    glungeWinter.setPosition(10, 200);
    
    liveCamGlitch.setup(liveCamGlitchG);
    liveCamGlitch.setPosition(10, 250);

    labyrinth.setup(labyrinthG);
    labyrinth.setPosition(10, 300);

    calligraphy.setup(calligraphyG);
    calligraphy.setPosition(10, 350);

    pluto.setup(plutoG);
    pluto.setPosition(10, 400);

    indiaTower.setup(indiaTowerG);
    indiaTower.setPosition(10, 450);

    trierFlyingCam.setup(trierFlyingCamG);
    trierFlyingCam.setPosition(10, 550);

    cubicMapFlyingCam.setup(cubicMapFlyingCamG);
    cubicMapFlyingCam.setPosition(10, 600);

    moonCreator.setup(moonCreatorG);
    moonCreator.setPosition(220, 10);

    lineVideo.setup(lineVideoG);
    lineVideo.setPosition(220, 60);

    movingObject.setup(movingObjectG);
    movingObject.setPosition(220, 110);

    droneAttack.setup(droneAttackG);
    droneAttack.setPosition(220, 160);

    webLiveCam.setup(webLiveCamG);
    webLiveCam.setPosition(220, 210);

    
    
    
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
    calligraphy.draw();
    pluto.draw();
    indiaTower.draw();
    trierFlyingCam.draw();
    cubicMapFlyingCam.draw();
    moonCreator.draw();
    lineVideo.draw();
    movingObject.draw();
    droneAttack.draw();
    webLiveCam.draw();
    
    
}







