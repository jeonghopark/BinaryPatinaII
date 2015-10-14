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
#include "ofxPostGlitch.h"
#include "BaseArch.h"


class LiveCamGlitch : public ofBaseApp {
    
    public :
    
    LiveCamGlitch();
    ~LiveCamGlitch();
    
    
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);

    void inputBaseArch(BaseArch &);
    
    BaseArch * baseArchData;

    ofVideoGrabber webCam;
    ofxPostGlitch glitchEffect;
    ofFbo liveVideoFbo;

    void glitchUpdate(ofPixels _p);
    
    bool bDirectglitch;
    ofImage imgDirectGlitch;
    ofImageQualityType quality;

    
    
};


#endif /* LiveCamGlitch_hpp */
