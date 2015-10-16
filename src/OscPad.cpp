//
//  OscPad.cpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 16/10/15.
//
//

#include "OscPad.hpp"

//--------------------------------------------------------------
OscPad::OscPad(){
    
}


//--------------------------------------------------------------
OscPad::~OscPad(){
    
}




//--------------------------------------------------------------
void OscPad::setup(){

    receiver.setup(PORT);
    
}


//--------------------------------------------------------------
void OscPad::update(){

    ofxOscMessage m;
    receiver.getNextMessage(m);
    
    if (m.getAddress() == "/1/multifaderframe/1") {
        fF[0] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifaderframe/2") {
        fF[1] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifaderframe/3") {
        fF[2] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifaderframe/4") {
        fF[3] = m.getArgAsFloat(0);
    }

    if (m.getAddress() == "/1/toggleframe") {
        bFB = m.getArgAsBool(0);
    }

    frameColor = ofColor::fromHsb(fF[0], fF[1], fF[2], fF[3]);

    
    if (m.getAddress() == "/1/multifaderline/1") {
        fL[0] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifaderline/2") {
        fL[1] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifaderline/3") {
        fL[2] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifaderline/4") {
        fL[3] = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/1/toggleline") {
        bLB = m.getArgAsBool(0);
    }
    
    lineColor = ofColor::fromHsb(fL[0], fL[1], fL[2], fL[3]);

    
    if (m.getAddress() == "/1/multifaderpoint/1") {
        fP[0] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifaderpoint/2") {
        fP[1] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifaderpoint/3") {
        fP[2] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifaderpoint/4") {
        fP[3] = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/1/togglepoint") {
        bPB = m.getArgAsBool(0);
    }
    
    pointColor = ofColor::fromHsb(fP[0], fP[1], fP[2], fP[3]);

    
    if (m.getAddress() == "/1/multifadercross/1") {
        fC[0] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifadercross/2") {
        fC[1] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifadercross/3") {
        fC[2] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifadercross/4") {
        fC[3] = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/1/togglecross") {
        bCB = m.getArgAsBool(0);
    }
    
    crossColor = ofColor::fromHsb(fC[0], fC[1], fC[2], fC[3]);


    if (m.getAddress() == "/1/multifadernumber/1") {
        fN[0] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifadernumber/2") {
        fN[1] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifadernumber/3") {
        fN[2] = m.getArgAsFloat(0);
    }
    if (m.getAddress() == "/1/multifadernumber/4") {
        fN[3] = m.getArgAsFloat(0);
    }
    
    if (m.getAddress() == "/1/togglenumber") {
        bNB = m.getArgAsBool(0);
    }
    
    numberColor = ofColor::fromHsb(fN[0], fN[1], fN[2], fN[3]);
    

    
    
}


//--------------------------------------------------------------
void OscPad::draw(){
    
    
}
