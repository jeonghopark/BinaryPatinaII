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
    
    indiaTower.inputBaseArch( baseArch );
    indiaTower.inputFFTP( fft );
    
    trierFlyingCam.setup();
    
    cubicMapFlyingCam.setup();
    
    moonCreator.setup();
    
    lineVideo.inputBaseArch(baseArch);

    movingObjects.inputBaseArch( baseArch );
    movingObjects.setup();
    
    droneAttack.setup();

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

    if (gui->OnOff_Pluto) {
        pluto.update();
    }

    if (gui->OnOff_IndiaTower) {
        fft.update();
    }
    
    if (gui->OnOff_TrierFlyingCam) {
        trierFlyingCam.update();
    }

    if (gui->OnOff_CubicMapFlyingCam) {
        cubicMapFlyingCam.update();
    }
    
    if (gui->OnOff_MoonCreator) {
        moonCreator.update();
    }

    if (gui->OnOff_LineVideo) {
        lineVideo.update();
    }

    if (gui->OnOff_MovingObject) {
        movingObjects.update();
    }

    if (gui->OnOff_DroneAttack) {
        droneAttack.update();
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

    if (gui->OnOff_Pluto) {
        pluto.draw();
    }


    if (gui->OnOff_TrierFlyingCam) {
        trierFlyingCam.draw();
    }

    if (gui->OnOff_CubicMapFlyingCam) {
        cubicMapFlyingCam.draw();
    }

    
    if (gui->OnOff_MoonCreator) {
        moonCreator.draw();
    }
    
    if (gui->OnOff_DroneAttack) {
        droneAttack.draw();
    }



    if (gui->OnOff_LineVideo) {
        lineVideo.draw();
        lineVideo.drawStartPoints();
        lineVideo.drawLines();
        lineVideo.drawColorNumber();
    }

    
    baseArch.guideFrames( ofColor(255, 0, 0) );
    //    baseArch.guideLines( ofColor(255) );
    //    baseArch.guidePoints( ofColor(255) );
    
    
    if (gui->OnOff_Windows) {
        ofColor _c = gui->color_Windows;
        baseArch.drawWindows( _c );
    }

    if (gui->OnOff_GlungeWinter) {
        glungeWinter.drawFront();
    }
    
    
    if (gui->OnOff_IndiaTower) {
        indiaTower.drawingRectColumn();
        indiaTower.drawingNumber();
        indiaTower.drawingBeziel();
    }

    if (gui->OnOff_MovingObject) {
        movingObjects.draw();
    }

    
    baseArch.drawEdgeCover( ofColor(0) );

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

