#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class GuiApp: public ofBaseApp {

public:

    void setup();
	void update();
	void draw();

	
    ofParameterGroup mainG;
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
    
    ofParameterGroup moonCreatorG;
    ofParameter<bool> OnOff_MoonCreator;

    ofParameterGroup lineVideoG;
    ofParameter<bool> OnOff_LineVideo;
    
    ofParameterGroup movingObjectG;
    ofParameter<bool> OnOff_MovingObject;

    ofParameterGroup droneAttackG;
    ofParameter<bool> OnOff_DroneAttack;

    ofParameterGroup webLiveCamG;
    ofParameter<bool> OnOff_WebLiveCam;

    ofParameterGroup nightVisionG;
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




