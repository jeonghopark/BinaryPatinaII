#pragma once

#include "ofMain.h"
#include "GuiApp.h"
#include "BaseArch.h"

#include "GlungeWinter.h"
#include "LiveCamGlitch.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void audioIn(float * input, int bufferSize, int nChannels);
    
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int 	bufferCounter;
    int 	drawCounter;
    
    float smoothedVol;
    float scaledVol;
    
    ofSoundStream soundStream;
    
    
    shared_ptr<GuiApp> gui;
    BaseArch baseArch;
    
    //    void drawEdgeCover();
    
    ofImage originArchBase;
    //    void drawOriginArchBase();
    
    float mainOffSetXPos, mainOffSetYPos;
    
    
    GlungeWinter glungeWinter;
    LiveCamGlitch liveCamGlitch;

    
};
