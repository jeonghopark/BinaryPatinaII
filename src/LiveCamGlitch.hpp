//
//  LiveCamGlitch.hpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 14/10/15.
//
//

#pragma once

#ifndef LiveCamGlitch_hpp
#define LiveCamGlitch_hpp

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxPostGlitch.h"
#include "BaseArch.h"

//#include "MidiInput.hpp"


class LiveCamGlitch {
    
    public :
    
    LiveCamGlitch();
    ~LiveCamGlitch();
    
    
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);

    void inputBaseArch(BaseArch &);
//    void inputMidiInput(MidiInput &);
    
    BaseArch * baseArchData;
//    MidiInput * midiInput;
    
    ofVideoGrabber webCam;
    ofxPostGlitch glitchEffect;
    ofFbo liveVideoFbo;

    void glitchUpdate(ofPixels _p);
    
    bool bDirectglitch;
    ofImage imgDirectGlitch;
    ofImageQualityType quality;

    
    ofxCvColorImage windowView;
    ofxCvColorImage captureCam;
    
    
};


#endif /* LiveCamGlitch_hpp */
