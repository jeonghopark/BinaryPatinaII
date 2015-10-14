//
//  Pluto.cpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 15/10/15.
//
//

#include "Pluto.hpp"


//--------------------------------------------------------------
Pluto::Pluto(){
    
    pluto.load("crop_p_color2_enhanced_release.png");
    xyScale = pluto.getWidth();

}


//--------------------------------------------------------------
Pluto::~Pluto(){
    
    
}



//--------------------------------------------------------------
void Pluto::inputBaseArch(BaseArch & _baseArch){
    
    baseArchData = & _baseArch;
    
}



//--------------------------------------------------------------
void Pluto::setup(){
    

}


//--------------------------------------------------------------
void Pluto::update(){
    
    xyScale = xyScale - 1;
    
    if (xyScale < 0) {
        xyScale = 0;
    }
    
}


//--------------------------------------------------------------
void Pluto::draw(){
    
    pluto.draw( ofGetWidth() * 0.5 - xyScale * 0.5, ofGetHeight() * 0.5 - xyScale * 0.5, xyScale, xyScale );

}





