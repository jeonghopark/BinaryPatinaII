//
//  LiveCamGlitch.cpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 14/10/15.
//
//

#include "LiveCamGlitch.hpp"


//--------------------------------------------------------------
LiveCamGlitch::LiveCamGlitch(){
    
    
}


//--------------------------------------------------------------
LiveCamGlitch::~LiveCamGlitch(){
    
    
}


//--------------------------------------------------------------
void LiveCamGlitch::inputBaseArch(BaseArch & _baseArch){
    
    baseArchData = & _baseArch;
    
}


//--------------------------------------------------------------
void LiveCamGlitch::setup(){
    
    
    quality = OF_IMAGE_QUALITY_WORST;
    
    
    webCam.setDeviceID(0);
    webCam.setup(1280, 720);
    
    liveVideoFbo.allocate(webCam.getWidth(), webCam.getHeight());
    
    float _w = baseArchData->fassadeCorner[1].x - baseArchData->fassadeCorner[0].x;
    float _h = baseArchData->fassadeCorner[2].y - baseArchData->fassadeCorner[0].y;
    imgDirectGlitch.allocate(webCam.getWidth(), webCam.getHeight(), OF_IMAGE_COLOR);
    
    
    glitchEffect.setup(&liveVideoFbo);
    
    bDirectglitch = false;
    
}



//--------------------------------------------------------------
void LiveCamGlitch::update(){
    
    webCam.update();
    
    if (bDirectglitch) {
        glitchUpdate(webCam.getPixels());
    }
    
    
    liveVideoFbo.begin();
    ofColor(0,255);
    webCam.setAnchorPercent(0.5, 0);
    webCam.draw(0, 0);
    
    liveVideoFbo.end();

    
}



//--------------------------------------------------------------
void LiveCamGlitch::glitchUpdate(ofPixels _p) {
    
    string compressedFilename = "compressed.jpg";
    
    unsigned char * _c = _p.getData();
    
    float coin = ofRandom(100);
    if (coin > 95) {
        _c = _p.getData() + (int)ofRandom(100);
    }
    
    imgDirectGlitch.setImageType(OF_IMAGE_COLOR);
    
    float _w = baseArchData->fassadeCorner[1].x - baseArchData->fassadeCorner[0].x;
    float _h = baseArchData->fassadeCorner[2].y - baseArchData->fassadeCorner[0].y;
    imgDirectGlitch.setFromPixels(_c, webCam.getWidth(), webCam.getHeight(), OF_IMAGE_COLOR);
    
    imgDirectGlitch.save(compressedFilename, quality);
    
    ofBuffer file = ofBufferFromFile(compressedFilename);
    int fileSize = file.size();
    char * buffer = file.getData();
    
    int whichByte = (int) ofRandom(fileSize);
    
    int whichBit = ofRandom(8);
    
    
    char bitMask;
    if ( whichBit >4 ) {
        bitMask = 1 << whichBit;
    } else {
        bitMask = 7 << whichBit;
    }
    
    buffer[whichByte] |= bitMask;
    
    ofBufferToFile(compressedFilename, file);
    imgDirectGlitch.load(compressedFilename);
    
    //    float coin = ofRandom(100);
    //    if (coin > 95) {
    //        reset();
    //    }
    
}



//--------------------------------------------------------------
void LiveCamGlitch::draw(){
    
    
    webCam.setAnchorPercent(0, 0);
    webCam.draw(0, 0);
    glitchEffect.generateFx();
    liveVideoFbo.draw(640, 0);

    
    if (bDirectglitch) {
        float _w = baseArchData->fassadeCorner[1].x - baseArchData->fassadeCorner[0].x;
        float _h = baseArchData->fassadeCorner[2].y - baseArchData->fassadeCorner[0].y;
        float _x = baseArchData->fassadeCorner[0].x;
        float _y = baseArchData->fassadeCorner[0].y;
        
        imgDirectGlitch.draw(_x, _y, _w, _h);
    }

    
}


//--------------------------------------------------------------
void LiveCamGlitch::keyPressed(int key){
    
    if (key == '1') glitchEffect.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
    if (key == '2') glitchEffect.setFx(OFXPOSTGLITCH_GLOW			, true);
    if (key == '3') glitchEffect.setFx(OFXPOSTGLITCH_SHAKER			, true);
    if (key == '4') glitchEffect.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
    if (key == '5') glitchEffect.setFx(OFXPOSTGLITCH_TWIST			, true);
    if (key == '6') bDirectglitch = true;
    if (key == '7') glitchEffect.setFx(OFXPOSTGLITCH_NOISE			, true);
    if (key == '8') glitchEffect.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
    if (key == '9') glitchEffect.setFx(OFXPOSTGLITCH_SWELL			, true);
    if (key == '0') glitchEffect.setFx(OFXPOSTGLITCH_INVERT			, true);
    
    if (key == 'q') glitchEffect.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
    if (key == 'w') glitchEffect.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
    if (key == 'e') glitchEffect.setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
    if (key == 'r') glitchEffect.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
    if (key == 't') glitchEffect.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
    if (key == 'y') glitchEffect.setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
    if (key == 'u') glitchEffect.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);
    
}

//--------------------------------------------------------------
void LiveCamGlitch::keyReleased(int key){
    
    if (key == '1') glitchEffect.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
    if (key == '2') glitchEffect.setFx(OFXPOSTGLITCH_GLOW			, false);
    if (key == '3') glitchEffect.setFx(OFXPOSTGLITCH_SHAKER			, false);
    if (key == '4') glitchEffect.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
    if (key == '5') glitchEffect.setFx(OFXPOSTGLITCH_TWIST			, false);
    if (key == '6') bDirectglitch = false;
    if (key == '7') glitchEffect.setFx(OFXPOSTGLITCH_NOISE			, false);
    if (key == '8') glitchEffect.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
    if (key == '9') glitchEffect.setFx(OFXPOSTGLITCH_SWELL			, false);
    if (key == '0') glitchEffect.setFx(OFXPOSTGLITCH_INVERT			, false);
    
    if (key == 'q') glitchEffect.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
    if (key == 'w') glitchEffect.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
    if (key == 'e') glitchEffect.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
    if (key == 'r') glitchEffect.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
    if (key == 't') glitchEffect.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
    if (key == 'y') glitchEffect.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
    if (key == 'u') glitchEffect.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);
    
    if (key == ' ') baseArchData->keyInteraction(' ');
    
}



