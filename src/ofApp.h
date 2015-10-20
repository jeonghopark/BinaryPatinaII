#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"
#include "ofxPostGlitch.h"

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
#include "NightVision.hpp"
#include "SpeechVideoSynth.hpp"

#define WEBCAM_WIDTH 640
#define WEBCAM_HEIGHT 480
#define WEBCAM_ID 2


class ofApp : public ofBaseApp {
    
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
    
    shared_ptr<GuiApp> gui;

    ofxFontStash font;
    MidiInput midiInput;
    ofVideoGrabber webCamHD;

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

    NightVision nightVision;    
    SpeechVideoSynth speechVideoSynth;

    
    int nBandsToGet;

    float mainOffSetXPos, mainOffSetYPos;
    
    vector<float> captureFFTSmoothed;
    vector<int> captureFFTIndex;


    void drawBaseArch();
    
    int labyrinthOldNumParticle;
    int labyrinthOldType;
    bool labyrinthChangeNum;

    
    int speechVideoOldNum;

    
    bool fullScreen;
    
    
    void serverAnnounced(ofxSyphonServerDirectoryEventArgs &arg);
    void serverUpdated(ofxSyphonServerDirectoryEventArgs &args);
    void serverRetired(ofxSyphonServerDirectoryEventArgs &arg);
    
    ofxSyphonServerDirectory dir;
    ofxSyphonClient client;
    int dirIdx;

    
    ofFbo			backFBO;
    ofFbo			frontFBO;
    ofxPostGlitch	backGlitch;
    ofxPostGlitch	frontGlitch;
    
    ofFbo			mainFBO;
    ofxPostGlitch	mainGlitch;
    
};



