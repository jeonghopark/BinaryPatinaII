/*
 * GuiApp.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: arturo
 */

#include "GuiApp.h"

void GuiApp::setup(){
	
    main.setup();
    main.setName("Main - Windows");
    main.setPosition(10, 10);
    main.add(FrameRate.set("FrameRate", ""));
    main.add(FullScreen.setup("FullScreen", false));
    main.add(webcamOn.setup("Web Cam On / Off", false));
    main.add(CanonView.setup("Canon On / Off", false));
    main.add(SyphonSearch.setup("SyphonSearch", false));
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
    glungeWinter.setName("01-Glunge Winter");
    glungeWinter.setPosition(220, 260);
    glungeWinter.add( OnOff_GlungeWinter.set("On/Off", false) );
    
    liveCamGlitch.setup();
    liveCamGlitch.setName("02-Shell LiveCamGlitch");
    liveCamGlitch.setPosition(220, 310);
    liveCamGlitch.add( OnOff_LiveCamGlitch.set("On/Off", false) );
    liveCamGlitch.add( ResetShader.setup("Reset Shader"));
    

    labyrinth.setup();
    labyrinth.setName("03-Thingy Labyrinth");
    labyrinth.setPosition(430, 110);
    labyrinth.add( OnOff_Labyrinth.set("On/Off", false) );
    labyrinth.add( LineType.setup("Line Type", false) );
    labyrinth.add( NumParticles.setup("Number Particles", 100, 1, 400));
    labyrinth.add( UpdateRandom.setup("Update Random", false) );
    labyrinth.add( Speed.setup("Speed", 1, 0, 10));
    labyrinth.add( ParticleSize.setup("Particle Size", 1, 0.1, 100));
    labyrinth.add( ParticleColor.setup("Particles Color", ofColor(255,255,255,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    labyrinth.add( PathColor.setup("Path Color", ofColor(255,255,255,20), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    labyrinth.add( ConnectionColor.setup("Connection Color", ofColor(255,255,255,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));

    
    calligraphy.setup();
    calligraphy.setName("04-Dub Calligraphy");
    calligraphy.setPosition(220, 390);
    calligraphy.add( OnOff_Calligraphy.set("On/Off", false) );
    calligraphy.add( fftSize.setup("FFT Size", 1, 0, 2));

    pluto.setup();
    pluto.setName("05-Fiona Pluto");
    pluto.setPosition(220, 470);
    pluto.add( OnOff_Pluto.set("On/Off", false) );

    indiaTower.setup();
    indiaTower.setName("06-India IndiaTower");
    indiaTower.setPosition(220, 520);
    indiaTower.add( OnOff_IndiaTower.set("On/Off", false) );

    trierFlyingCam.setup();
    trierFlyingCam.setName("07-MIdinight Trier");
    trierFlyingCam.setPosition(220, 570);
    trierFlyingCam.add( OnOff_TrierFlyingCam.set("On/Off", false) );

    cubicMapFlyingCam.setup();
    cubicMapFlyingCam.setName("08-Glass CubicMap");
    cubicMapFlyingCam.setPosition(430, 10);
    cubicMapFlyingCam.add( OnOff_CubicMapFlyingCam.set("On/Off", false) );
    

    moonCreator.setup();
    moonCreator.setName("09-Stringer Moon");
    moonCreator.setPosition(220, 10);
    moonCreator.add( OnOff_MoonCreator.set("On/Off", false) );

    lineVideo.setup();
    lineVideo.setName("10-BlowFiles LineVideo");
    lineVideo.setPosition(220, 60);
    lineVideo.add( OnOff_LineVideo.set("On/Off", false) );

    movingObject.setup();
    movingObject.setName("11-Granu MovingObject");
    movingObject.setPosition(640, 350);
    movingObject.add( OnOff_MovingObject.set("On/Off", false) );
    movingObject.add( ColorText.setup("Text Color", ofColor(255,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    movingObject.add( ColorRect.setup("Rect Color", ofColor(255,255,255,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));


    
    droneAttack.setup();
    droneAttack.setName("12-Patina DroneAttack");
    droneAttack.setPosition(640, 10);
    droneAttack.add( OnOff_DroneAttack.set("On/Off", false) );
    droneAttack.add( DrawEarth.setup("On/Off", true) );
    droneAttack.add( DrawAttack.setup("On/Off", true) );
    droneAttack.add( DrawEarthTexture.setup("On/Off", false) );
    
    droneAttack.add( DroneSpeedFactor.setup("Drone Speed : 7", 7, 0.02, 14) );
    droneAttack.add( AttackColor.setup("Attack Color", ofColor(255,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    droneAttack.add( EarthColor.setup("Earth Color", ofColor(255,255,255,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    droneAttack.add( LoadImage.setup("LoadImage", false));

    

    webLiveCam.setup();
    webLiveCam.setName("13-Oddity WebLiveCam");
    webLiveCam.setPosition(220, 120);
    webLiveCam.add( OnOff_WebLiveCam.set("On/Off", false) );
    webLiveCam.add( LoadMovies.setup("Load", false) );
    webLiveCam.add( IndexMovie.setup("Index Movie", 0, 0, 2) );
    webLiveCam.add( RandomPosition.setup("Random", false) );
    
    
    
    nightVision.setup();
    nightVision.setName("NightVision");
    nightVision.setPosition(430, 60);
    nightVision.add( OnOff_NightVision.set("On/Off", false) );

    
    speechVideo.setup();
    speechVideo.setName("Speech Video");
    speechVideo.setPosition(850, 10);
    speechVideo.add( OnOFf_SpeechVideo.set("On/Off", false) );
    speechVideo.add( LoadSpeechVideos.setup("Load Video", false ));
    speechVideo.add( IndexSpeechMovie.setup("Index Movie", 0, 0, 3 ));

    
    glitchMain.setup();
    glitchMain.setName("Glitch Main");
    glitchMain.setPosition(850, 160);
    glitchMain.add( plutoGlitch.setup("Pluto", false ));

    
    
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
    
    speechVideo.draw();
    
    glitchMain.draw();
    
}





