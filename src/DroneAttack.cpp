//
//  DroneAttack.cpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 15/10/15.
//
//

#include "DroneAttack.hpp"


//--------------------------------------------------------------
DroneAttack::DroneAttack(){
    
    
}


//--------------------------------------------------------------
DroneAttack::~DroneAttack(){
    
    
}


//--------------------------------------------------------------
void DroneAttack::jsonDataSetup(){
    
    ofxJSONElement _drondata;
    _drondata.open("dropAttack_08102015_edit.json");
    
    ofxJSONElement _dronStrike = _drondata["strike"];
    
    float _radiusEarth = 700;
    
    dronData.resize(_dronStrike.size());
    for (int i=0; i<_dronStrike.size(); i++){
        
        float _lon = ofToFloat(_dronStrike[i]["lon"].asString());
        float _lat = ofToFloat(_dronStrike[i]["lat"].asString());
        
        float _d = ofToFloat(_dronStrike[i]["deaths_max"].asString());
        
        ofVec3f _v;
        _v.x = _radiusEarth * cos(ofDegToRad(_lat)) * cos(ofDegToRad(_lon));
        _v.y = _radiusEarth * cos(ofDegToRad(_lat)) * sin(ofDegToRad(_lon));
        _v.z = _radiusEarth * sin(ofDegToRad(_lat));
        
        dronData[i].deathMax = _d;
        dronData[i].coord = _v;
        
    }
    
    
    
    
    ofxJSONElement _jsonData;
    _jsonData.open("ne_110m_coastline.geojson");
    
    ofxJSONElement _jsonDataChild = _jsonData["features"];
    for (int i=0; i<_jsonDataChild.size(); i++) {
        ofxJSONElement _jsonGeoData = _jsonDataChild[i]["geometry"]["coordinates"];
        
        ofPolyline _p;
        
        for (int j=0; j<_jsonGeoData.size(); j++) {
            
            float _lon = _jsonGeoData[j][0].asFloat();
            float _lat = _jsonGeoData[j][1].asFloat();
            
            ofVec3f _v;
            _v.x = _radiusEarth * cos(ofDegToRad(_lat)) * cos(ofDegToRad(_lon));
            _v.y = _radiusEarth * cos(ofDegToRad(_lat)) * sin(ofDegToRad(_lon));
            _v.z = _radiusEarth * sin(ofDegToRad(_lat));
            
            
            _p.addVertex( _v );
            
        }
        
        oceanLineCoord.push_back( _p );
        
    }
    

}


//--------------------------------------------------------------
void DroneAttack::setup(){
    
    cam.setNearClip(0.0001f);
    cam.setFarClip(10000.0f);
    cam.toggleControl();

    jsonDataSetup();
    
    
}



//--------------------------------------------------------------
void DroneAttack::update(){
    

    auto pushed = in.keyPushed;
    auto holded = in.keyHolded;
    auto pulled = in.keyPulled;
    
    if( pushed[GLFW_KEY_LEFT_SHIFT] ) cam.movespeed = 7.0f;
    if( pulled[GLFW_KEY_LEFT_SHIFT] ) cam.movespeed = 1.0f;
    
    if( pushed[GLFW_MOUSE_BUTTON_LEFT] ) paint.push_back( ofPolyline() );
    if( holded[GLFW_MOUSE_BUTTON_LEFT] ) paint.back().addVertex( cam.getPosition() + (cam.getLookAtDir() * 50.0f) );
    
    if( pushed[GLFW_MOUSE_BUTTON_RIGHT] ) cam.toggleControl();

    
}



//--------------------------------------------------------------
void DroneAttack::draw(){
    
    cam.begin();
    
    ofPushStyle();
    ofSetColor(255, 0, 0);
    for (int i=0; i<dronData.size(); i++) {
        ofVec3f _v = dronData[i].coord;
        
        float _ratio = ofMap(dronData[i].deathMax, 1, 30, 1.1, 1.2);
        
        ofDrawLine( _v, _v * _ratio );
    }
    
    ofPopStyle();
    
    
    ofPushStyle();
    ofSetColor(255);
    for (int i=0; i<oceanLineCoord.size(); i++) {
        oceanLineCoord[i].draw();
    }
    ofPopStyle();
    
    
    cam.end();



    
}

