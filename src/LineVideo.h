//
//  LineVideo.hpp
//  Abstract
//
//  Created by jeonghopark on 13/10/15.
//
//
#pragma once

#ifndef LineVideo_h
#define LineVideo_h

#include "ofMain.h"

#include "SceneSetup.hpp"

#include "ofxOpenCv.h"
#include "BaseArch.h"



class LineVideo: public SceneSetup {
    
    public :
    
    LineVideo();
    ~LineVideo();
    
    void setup();
    void update();
    void draw();
    void drawStartPoints();
    void drawLines();
    void drawColorNumber();
    
//    void setupBaseArch(BaseArch & _baseArch);
    void inputCam(ofVideoGrabber & _c);
    
    void drawWindows();
    
//    BaseArch * baseArch;
    ofVideoGrabber * webCam;
    
//    ofVideoGrabber cam;
    ofImage halfCam;

    ofxCvColorImage colorImg;
    
    vector<ofColor> startLineColors;
    vector<float> controlPosY;
};


#endif /* LineVideo_h */
