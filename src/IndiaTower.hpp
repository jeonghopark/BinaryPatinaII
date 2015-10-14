//
//  IndiaTower.hpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 15/10/15.
//
//

#pragma once

#ifndef IndiaTower_hpp
#define IndiaTower_hpp

#include "ofMain.h"
#include "ofxProcessFFT.h"

#include "BaseArch.h"

class IndiaTower : public ofBaseApp {
    
    public :
    
    IndiaTower();
    ~IndiaTower();
    
    void setup();
    void update();
    void draw();
    void inputBaseArch(BaseArch & _baseArch);
    void inputFFTP(ProcessFFT & _processFFT);
    
    void drawingRectColumn();
    void drawingNumber();
    void drawingBeziel();

    
    BaseArch * baseArchData;
    ProcessFFT * processFFT;

    ofTrueTypeFont spectrumNumbers;

    vector<ofVec2f> bezielStart;
    vector<ofVec2f> bezielEnd;

    
};


#endif /* IndiaTower_hpp */
