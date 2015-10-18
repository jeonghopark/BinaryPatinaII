/*
 * GuiApp.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: arturo
 */

#include "GuiApp.h"

void GuiApp::setup(){
	
    main.setup();
    main.setName("parameters");
    main.setPosition(10, 10);
    main.add(FrameRate.set("FrameRate", ""));
    main.add(webcamOn.setup("Web Cam On / Off", false));
    main.add(color_Windows.set("Color Windows", ofColor(255,0,0,1), ofColor(0,0,0,1), ofColor(255,255,255,255)));
    main.add(OnOff_Windows.set("OnOff Windows", false));
    main.add(color_Frames.set("Color Frames", ofColor(255,0,0,1), ofColor(0,0,0,1), ofColor(255,255,255,255)));
    main.add(OnOff_Frames.set("OnOff Frames", false));
    main.add(color_Lines.set("Color Lines", ofColor(255,0,0,1), ofColor(0,0,0,1), ofColor(255,255,255,255)));
    main.add(OnOff_Lines.set("OnOff Lines", false));
    main.add(color_Points.set("Color Points", ofColor(255,0,0,1), ofColor(0,0,0,1), ofColor(255,255,255,255)));
    main.add(OnOff_Points.set("OnOff Points", false));
    main.add(color_Cross.set("Color Cross", ofColor(255,0,0,1), ofColor(0,0,0,1), ofColor(255,255,255,255)));
    main.add(OnOff_Cross.set("OnOff Cross", false));
    main.add(color_Numbers.set("Color Numbers", ofColor(255,0,0,1), ofColor(0,0,0,1), ofColor(255,255,255,255)));
    main.add(OnOff_Numbers.set("OnOff Numbers", false));

    glungeWinter.setup();
    glungeWinter.setName("GlungeWinter");
    glungeWinter.setPosition(220, 260);
    glungeWinter.add( OnOff_GlungeWinter.set("On/Off", false) );
    
    liveCamGlitch.setup();
    liveCamGlitch.setName("LiveCamGlitch");
    liveCamGlitch.setPosition(220, 310);
    liveCamGlitch.add( OnOff_LiveCamGlitch.set("On/Off", false) );
    liveCamGlitch.add( ResetShader.setup("Reset Shader"));

    labyrinth.setup();
    labyrinth.setName("Labyrinth");
    labyrinth.setPosition(220, 370);
    labyrinth.add( OnOff_Labyrinth.set("On/Off", false) );
    labyrinth.add( LineType.setup("Line Type", false) );
    
    calligraphy.setup();
    calligraphy.setName("Calligraphy");
    calligraphy.setPosition(220, 420);
    calligraphy.add( OnOff_Calligraphy.set("On/Off", false) );
    calligraphy.add( fftSize.setup("FFT Size", 1, 0, 2));

    pluto.setup();
    pluto.setName("Pluto");
    pluto.setPosition(220, 470);
    pluto.add( OnOff_Pluto.set("On/Off", false) );

    indiaTower.setup();
    indiaTower.setName("IndiaTower");
    indiaTower.setPosition(220, 520);
    indiaTower.add( OnOff_IndiaTower.set("On/Off", false) );

    trierFlyingCam.setup();
    trierFlyingCam.setName("TrierFlyingCam");
    trierFlyingCam.setPosition(220, 570);
    trierFlyingCam.add( OnOff_TrierFlyingCam.set("On/Off", false) );

    cubicMapFlyingCam.setup();
    cubicMapFlyingCam.setName("CubicMapFlyingCam");
    cubicMapFlyingCam.setPosition(430, 10);
    cubicMapFlyingCam.add( OnOff_CubicMapFlyingCam.set("On/Off", false) );
    

    moonCreator.setup();
    moonCreator.setName("MoonCreator");
    moonCreator.setPosition(220, 10);
    moonCreator.add( OnOff_MoonCreator.set("On/Off", false) );

    lineVideo.setup();
    lineVideo.setName("LineVideo");
    lineVideo.setPosition(220, 60);
    lineVideo.add( OnOff_LineVideo.set("On/Off", false) );

    movingObject.setup();
    movingObject.setName("MovingObject");
    movingObject.setPosition(220, 110);
    movingObject.add( OnOff_MovingObject.set("On/Off", false) );

    droneAttack.setup();
    droneAttack.setName("DroneAttack");
    droneAttack.setPosition(220, 160);
    droneAttack.add( OnOff_DroneAttack.set("On/Off", false) );

    webLiveCam.setup();
    webLiveCam.setName("WebLiveCam");
    webLiveCam.setPosition(220, 210);
    webLiveCam.add( OnOff_WebLiveCam.set("On/Off", false) );

    
    nightVision.setup();
    nightVision.setName("NightVision");
    nightVision.setPosition(430, 60);
    nightVision.add( OnOff_NightVision.set("On/Off", false) );

    
    
    
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
    nightVision.draw();
    
}







