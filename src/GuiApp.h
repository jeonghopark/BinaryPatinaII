#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class GuiApp: public ofBaseApp {

public:

    void setup();
	void update();
	void draw();

	
    ofParameter<string> FrameRate;
	ofParameter<bool> OnOff_Windows;
    ofParameter<ofColor> color_Windows;
    ofParameter<bool> OnOff_Frames;
    ofParameter<ofColor> color_Frames;
    ofParameter<bool> OnOff_Lines;
    ofParameter<ofColor> color_Lines;
    ofParameter<bool> OnOff_Numbers;
    ofParameter<ofColor> color_Numbers;
    ofParameter<bool> OnOff_Cross;
    ofParameter<ofColor> color_Cross;
    ofParameter<bool> OnOff_Points;
    ofParameter<ofColor> color_Points;

    
    ofParameter<bool> OnOff_GlungeWinter;
    
    ofParameter<bool> OnOff_LiveCamGlitch;
    ofxButton ResetShader;
    
    ofParameter<bool> OnOff_Labyrinth;

    ofParameter<bool> OnOff_Calligraphy;

    ofParameter<bool> OnOff_Pluto;

    ofParameter<bool> OnOff_IndiaTower;

    ofParameter<bool> OnOff_TrierFlyingCam;

    ofParameter<bool> OnOff_CubicMapFlyingCam;
    
    ofParameter<bool> OnOff_MoonCreator;

    ofParameter<bool> OnOff_LineVideo;
    
    ofParameter<bool> OnOff_MovingObject;

    ofParameter<bool> OnOff_DroneAttack;

    ofParameter<bool> OnOff_WebLiveCam;

    ofParameter<bool> OnOff_NightVision;
    
    
    ofxPanel main;
    ofxPanel glungeWinter;
    ofxPanel liveCamGlitch;
    ofxPanel labyrinth;
    ofxPanel calligraphy;
    ofxPanel pluto;
    ofxPanel indiaTower;
    ofxPanel trierFlyingCam;
    ofxPanel cubicMapFlyingCam;
    ofxPanel moonCreator;
    ofxPanel lineVideo;
    ofxPanel movingObject;
    ofxPanel droneAttack;
    ofxPanel webLiveCam;
    ofxPanel nightVision;

    
    ofParameter<bool> audioInputOnOff;
    
};




