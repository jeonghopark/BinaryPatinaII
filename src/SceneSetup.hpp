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
#include "ofxProcessFFT.h"
#include "ofxLeapMotion2.h"


class SceneSetup {
    
public:
    
    void inputBaseArch(BaseArch & _baseArch);
    void inputFFTP(ProcessFFT & _processFFT);
    void inputWebCam(ofVideoGrabber & _webCamHD);
    void inputLeapMotion(ofxLeapMotion & _leapMotion);

    BaseArch * baseArch;
    ProcessFFT * processFFT;
    ofVideoGrabber * webCamHD;
    
    ofxLeapMotion * leapMotion;
    vector <ofxLeapMotionSimpleHand> simpleHands;
    bool leapMotionPause;

    
};


#endif /* SceneSetup_hpp */
