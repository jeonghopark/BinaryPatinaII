#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class GuiApp : public ofBaseApp {

public:

    void setup();
	void update();
	void draw();

    ofParameter<string> FrameRate;
    ofxButton webcamOn;
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
    ofxToggle LineType;
    ofxButton UpdateRandom;
    ofxIntSlider NumParticles;
    ofxFloatSlider Speed;
    ofxFloatSlider ParticleSize;
    ofxColorSlider ParticleColor;
    ofxColorSlider PathColor;
    ofxColorSlider ConnectionColor;


    ofParameter<bool> OnOff_Calligraphy;
    ofxFloatSlider fftSize;
    
    ofParameter<bool> OnOff_Pluto;

    ofParameter<bool> OnOff_IndiaTower;

    ofParameter<bool> OnOff_TrierFlyingCam;

    ofParameter<bool> OnOff_CubicMapFlyingCam;
    
    ofParameter<bool> OnOff_MoonCreator;

    ofParameter<bool> OnOff_LineVideo;
    
    
    ofParameter<bool> OnOff_MovingObject;
    ofxColorSlider ColorText;
    ofxColorSlider ColorRect;


    ofParameter<bool> OnOff_DroneAttack;
    ofxFloatSlider DroneSpeedFactor;
    ofxColorSlider EarthColor;
    ofxColorSlider AttackColor;
    

    ofParameter<bool> OnOff_WebLiveCam;
    ofxButton LoadMovies;
    ofxButton RandomPosition;
    ofxIntSlider IndexMovie;
    

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




