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
    

}


//--------------------------------------------------------------
Pluto::~Pluto(){
    
    
}


//--------------------------------------------------------------
void Pluto::setup(){
    
    loadImages();
    
    speedFactor = 0.3;
    
}


//--------------------------------------------------------------
void Pluto::update(){
    
    yPosMoon = yPosMoon + 1 * speedFactor;
    
    if (yPosMoon > -180) {
        yPosMoon = -180;
        
        xyScaleMoon = xyScaleMoon - 2.5 * speedFactor;
        
        cout << xyScaleMoon << endl;

        if (xyScaleMoon < 1800) {
            yPosEarth = yPosEarth + 1 * speedFactor;
        }
        
        if (yPosEarth > 400) {
            yPosEarth = 400;
        }
        
        
        if (xyScaleMoon < 0) {
            xyScaleMoon = 0;
        }
        
        
    }
    
    
    
    
}


//--------------------------------------------------------------
void Pluto::draw(){
    
    moon.draw( ofGetWidth() * 0.5 - xyScaleMoon * 0.5, ofGetHeight() * 0.5 + yPosMoon - xyScaleMoon * 0.5, xyScaleMoon, xyScaleMoon );
    
    earthBlur.draw(ofGetWidth() * 0.5 - xyScaleEarth * 0.5, ofGetHeight() * 0.5 + yPosEarth- xyScaleEarth * 0.5, xyScaleEarth, xyScaleEarth );
    

}



//--------------------------------------------------------------
void Pluto::loadImages(){

    moon.clear();
    earthBlur.clear();
    
    moon.load("MoonHRfull.png");
    earthBlur.load("earthBlur.png");
    
    xyScaleMoon = moon.getWidth();
    xyScaleEarth = earthBlur.getWidth();
    
    yPosMoon = -moon.getWidth() * 0.5 - 350;
    yPosEarth = -earthBlur.getWidth() * 0.5 - 350;

}


