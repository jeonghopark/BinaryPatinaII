//
//  SceneSetup.hpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 18/10/15.
//
//
#pragma once


#ifndef SceneSetup_hpp
#define SceneSetup_hpp

#include "ofMain.h"

#include "BaseArch.h"
#include "MakeChecker.hpp"

#include "ofxProcessFFT.h"
#include "ofxLeapMotion2.h"
#include "ofxFontStash.h"
#include "MidiInput.hpp"

class SceneSetup {
    
public:
    
    void inputBaseArch(MakeChecker & _baseArch);
    void inputFFTP(ProcessFFT & _processFFT);
    void inputWebCam(ofVideoGrabber & _webCamHD);
    void inputLeapMotion(ofxLeapMotion & _leapMotion);
    void inputFont(ofxFontStash & _f);
    void inputMIDI(MidiInput & _m);
    
    
    MakeChecker * baseArch;
    ProcessFFT * processFFT;
    ofVideoGrabber * webCamHD;
    ofxFontStash * font;
    MidiInput * midi;
    
    ofxLeapMotion * leapMotion;
    vector <ofxLeapMotionSimpleHand> simpleHands;
    bool leapMotionPause;

    
};


#endif /* SceneSetup_hpp */
