#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofEnableAlphaBlending();
    ofSetFrameRate( 60 );
    ofBackground( 0 );
    
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
    
    

    glungeWinter.inputBaseArch(baseArch);
    liveCamGlitch.inputBaseArch(baseArch);
    liveCamGlitch.setup();
    
    labyrinth.inputBaseArch(baseArch);
    labyrinth.setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (gui->OnOff_LiveCamGlitch) {
        liveCamGlitch.update();
    }
    
    if (gui->OnOff_Labyrinth) {
        labyrinth.update();
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofPushMatrix();
    
    ofTranslate( mainOffSetXPos, mainOffSetYPos );
    
    if (gui->OnOff_LiveCamGlitch) {
        liveCamGlitch.draw();
    }
    
    if (gui->OnOff_GlungeWinter) {
        glungeWinter.drawBackTexture();
        glungeWinter.drawBack();
    }
    
    if (gui->OnOff_Labyrinth) {
        labyrinth.draw();
    }
    

    
    //    baseArch.guideFrames();
    baseArch.drawEdgeCover( ofColor(0) );
    //    baseArch.guideLines( ofColor(255) );
    //    baseArch.guidePoints( ofColor(255) );
    
    baseArch.drawWindows( ofColor(255, 0, 0, 80) );

    if (gui->OnOff_GlungeWinter) {
        glungeWinter.drawFront();
    }
    
    
    ofPopMatrix();
    
    
    
}


//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    liveCamGlitch.keyPressed(key);
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    baseArch.keyInteraction(key);
    
    liveCamGlitch.keyReleased(key);
    liveCamGlitch.keyReleased(key);
    
    labyrinth.keyReleased(key);

    
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
