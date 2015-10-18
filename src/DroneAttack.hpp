//
//  DroneAttack.hpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 15/10/15.
//
//
#pragma once


#ifndef DroneAttack_hpp
#define DroneAttack_hpp

#include "ofMain.h"

#include "SceneSetup.hpp"

#include "ofxImmediateModeInput.h"
#include "ofxFirstPersonCamera.h"

#include "ofxJSON.h"

struct DronData{
    
    ofVec3f coord;
    float deathMax;
    
};

class DroneAttack : public SceneSetup {
    
public:
    
    DroneAttack();
    ~DroneAttack();
    
    void setup();
    void update();
    void draw();
    
    void jsonDataSetup();
    
    vector<DronData> dronData;
    
    vector<ofPolyline> oceanLineCoord;

    ofxImmediateModeInput in;
    ofxFirstPersonCamera cam;
    vector<ofPolyline> paint;

    
    
};

#endif /* DroneAttack_hpp */
