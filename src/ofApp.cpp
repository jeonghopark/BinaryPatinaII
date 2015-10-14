#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    //    ofSetDataPathRoot("../Resources/data/");
    ofSetFrameRate( 60 );
    ofBackground( 0 );
    
    ofEnableAlphaBlending();
    //    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    
    mainOffSetXPos = (ofGetWidth() - (baseArch.fassadeCorner[0].x + baseArch.fassadeCorner[1].x)) * 0.5;
    mainOffSetYPos = (ofGetHeight() - (baseArch.fassadeCorner[0].y + baseArch.fassadeCorner[3].y)) * 0.5;
    
    baseArch.mainOffSetXPos = mainOffSetXPos;
    baseArch.mainOffSetYPos = mainOffSetYPos;
    
    
    int bufferSize = 256;
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter	= 0;
    drawCounter		= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    if (gui->audioInputOnOff) {
        if (scaledVol>0.2) {
            
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofPushMatrix();
    
    ofTranslate( mainOffSetXPos, mainOffSetYPos );
    
    baseArch.guideFrames();
    baseArch.drawEdgeCover();
    baseArch.guideLines();
    baseArch.guidePoints();
    
    ofPopMatrix();
    
    
    
}


//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    baseArch.keyInteraction(key);
    
    if (key == 'o') {
        baseArch.setupDefault();
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
    mainOffSetXPos = (ofGetWidth() - (baseArch.fassadeCorner[0].x + baseArch.fassadeCorner[1].x)) * 0.5;
    mainOffSetYPos = (ofGetHeight() - (baseArch.fassadeCorner[0].y + baseArch.fassadeCorner[3].y)) * 0.5;
    baseArch.mainOffSetXPos = mainOffSetXPos;
    baseArch.mainOffSetYPos = mainOffSetYPos;
    
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
