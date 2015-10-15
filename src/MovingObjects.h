//
//  MovingObjects.hpp
//  FrameMoving
//
//  Created by jeonghopark on 04/10/15.
//
//
#pragma once

#ifndef MovingObjects_hpp
#define MovingObjects_hpp

#include "ofMain.h"
#include "ofxJSON.h"
#include "BaseArch.h"


struct GuidID{
    
    float hTextMoving;
    float hTextMovingFactor;
    float hTextMovingXPos;
    float hTextMovingYPos;
    
    string quid_string;
};


class MovingObjects : public ofBaseApp{
    
    public:
    
    MovingObjects();
    ~MovingObjects();
    
    BaseArch * baseArchData;

    
    void inputBaseArch(BaseArch &);
    void setup();
    void update();
    void draw(ofColor _c = ofColor(255));
        
    vector< ofPolyline > hFrames;
    vector< ofPolyline > vFrames;
    vector< ofPolyline > hCenterFrames;
    
    vector< float > hMoving;
    vector< float > hMovingFactor;
    vector< float > hMovingXPos;

    vector< GuidID > guidID;
    int guidIDNumber[72];
    
    float mainOffSetXPos, mainOffSetYPos;
    
    
};




#endif /* MovingObjects_hpp */
