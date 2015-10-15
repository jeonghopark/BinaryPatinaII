#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class GuiApp: public ofBaseApp {

public:

    void setup();
	void update();
	void draw();

	ofParameterGroup mainG;
	ofParameter<bool> OnOff_Windows;
    ofParameter<ofColor> color_Windows;
    ofParameter<string> FrameRate;

    ofParameterGroup glungeWinterG;
    ofParameter<bool> OnOff_GlungeWinter;
    
    ofParameterGroup liveCamGlitchG;
    ofParameter<bool> OnOff_LiveCamGlitch;

    ofParameterGroup labyrinthG;
    ofParameter<bool> OnOff_Labyrinth;

    ofParameterGroup calligraphyG;
    ofParameter<bool> OnOff_Calligraphy;

    ofParameterGroup plutoG;
    ofParameter<bool> OnOff_Pluto;

    ofParameterGroup indiaTowerG;
    ofParameter<bool> OnOff_IndiaTower;

    ofParameterGroup trierFlyingCamG;
    ofParameter<bool> OnOff_TrierFlyingCam;

    ofParameterGroup cubicMapFlyingCamG;
    ofParameter<bool> OnOff_CubicMapFlyingCam;
    

    
    ofxPanel main;
    ofxPanel glungeWinter;
    ofxPanel liveCamGlitch;
    ofxPanel labyrinth;
    ofxPanel calligraphy;
    ofxPanel pluto;
    ofxPanel indiaTower;
    ofxPanel trierFlyingCam;
    ofxPanel cubicMapFlyingCam;
    
    ofParameter<bool> audioInputOnOff;
    
};

