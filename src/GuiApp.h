#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class GuiApp: public ofBaseApp {

public:

    void setup();
	void update();
	void draw();

	ofParameterGroup mainG;
	ofParameter<float> windowsAlpha;
    ofParameter<string> FrameRate;

    ofParameterGroup glungeWinterG;
    ofParameter<bool> OnOff_GlungeWinter;
    
    ofParameterGroup liveCamGlitchG;
    ofParameter<bool> OnOff_LiveCamGlitch;

    ofParameterGroup labyrinthG;
    ofParameter<bool> OnOff_Labyrinth;

    ofParameterGroup calligraphyG;
    ofParameter<bool> OnOff_Calligraphy;

    
    ofxPanel main;
    ofxPanel glungeWinter;
    ofxPanel liveCamGlitch;
    ofxPanel labyrinth;
    ofxPanel calligraphy;
    
    ofParameter<bool> audioInputOnOff;
    
};

