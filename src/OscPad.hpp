//
//  OscPad.hpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 16/10/15.
//
//
#pragma once


#ifndef OscPad_hpp
#define OscPad_hpp

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 8000

class OscPad : public ofBaseApp{
    
public:
    
    OscPad();
    ~OscPad();
    
    void setup();
    void update();
    void draw();
    
    ofxOscReceiver receiver;
    
    ofColor frameColor;
    float fFH, fFS, fFB, fFA;
    float fF[4] = {0, 0, 0, 0};
    bool bFB;

    ofColor lineColor;
    float fLH, fLS, fLB, fLA;
    float fL[4] = {0, 0, 0, 0};
    bool bLB;

    ofColor pointColor;
    float fPH, fPS, fPB, fPA;
    float fP[4] = {0, 0, 0, 0};
    bool bPB;

    ofColor crossColor;
    float fCH, fCS, fCB, fCA;
    float fC[4] = {0, 0, 0, 0};
    bool bCB;

    ofColor numberColor;
    float fNH, fNS, fNB, fNA;
    float fN[4] = {0, 0, 0, 0};
    bool bNB;
    
};


#endif /* OscPad_hpp */
