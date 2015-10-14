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
    

    nBandsToGet = 32 * 2;
    
    fft.fft.stream.setDeviceID(2);
    fft.setup();
    fft.fft.setup(16384);
    fft.setNumFFTBins(nBandsToGet);
    fft.setFFTpercentage(0.9);
    


    glungeWinter.inputBaseArch(baseArch);

    liveCamGlitch.inputBaseArch(baseArch);
    liveCamGlitch.setup();
    
    labyrinth.inputBaseArch(baseArch);
    labyrinth.setup();
    
    calligraphy.inputBaseArch( baseArch );
    calligraphy.inputFFTP( fft );
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    if (gui->OnOff_LiveCamGlitch) {
        liveCamGlitch.update();
    }
    
    if (gui->OnOff_Labyrinth) {
        labyrinth.update();
    }
    

    if (gui->OnOff_Calligraphy) {

        fft.update();
        calligraphy.update();

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


    if (gui->OnOff_Calligraphy) {

        calligraphy.draw();

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
