#pragma once

#include "ofMain.h"
#include "GuiApp.h"

#include "BaseArch.h"

#include "ofxFontStash.h"

#include "ofxProcessFFT.h"
#include "MidiInput.hpp"

#include "GlungeWinter.h"
#include "LiveCamGlitch.hpp"
#include "Labyrinth.hpp"
#include "Calligraphy.h"
#include "Pluto.hpp"
#include "IndiaTower.hpp"
#include "TrierFlyingCam.hpp"
#include "CubicMapFlyingCam.hpp"
#include "MoonCreator.hpp"
#include "LineVideo.h"
#include "MovingObjects.h"
#include "DroneAttack.hpp"
#include "WebLiveCam.hpp"
#include "KinectView.hpp"


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
    
    
    ofxFontStash font;
    
    MidiInput midiInput;

    ofVideoGrabber webCamHD;

    shared_ptr<GuiApp> gui;

    BaseArch baseArch;
    
    GlungeWinter glungeWinter;
    LiveCamGlitch liveCamGlitch;
    Labyrinth labyrinth;
    ProcessFFT fft;
    Calligraphy calligraphy;
    Pluto pluto;
    IndiaTower indiaTower;
    TrierFlyingCam trierFlyingCam;
    CubicMapFlyingCam cubicMapFlyingCam;
    MoonCreator moonCreator;
    LineVideo lineVideo;
    MovingObjects movingObjects;
    DroneAttack droneAttack;
    WebLiveCam webLiveCam;
    KinectView kinectView;

    
    int nBandsToGet;

    float mainOffSetXPos, mainOffSetYPos;
    
    vector<float> captureFFTSmoothed;
    vector<int> captureFFTIndex;


    void drawBaseArch();
    
};



