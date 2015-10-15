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
void LiveCamGlitch::inputMidiInput(MidiInput & _midiInput){
    midiInput = & _midiInput;
}


//--------------------------------------------------------------
void LiveCamGlitch::inputCam(ofVideoGrabber & _c){
    webCam = & _c;
}



//--------------------------------------------------------------
void LiveCamGlitch::setup(){
    
    quality = OF_IMAGE_QUALITY_WORST;
    
    videoW = 1280;
    videoH = 720;
    
    liveVideoFbo.clear();
    liveVideoFbo.allocate(videoW, videoH);
    
    windowView.allocate(videoW, videoH);
    captureCam.allocate(videoW * 0.5, videoH);
    
    float _w = baseArchData->fassadeCorner[1].x - baseArchData->fassadeCorner[0].x;
    float _h = baseArchData->fassadeCorner[2].y - baseArchData->fassadeCorner[0].y;
    imgDirectGlitch.allocate(videoW, videoH, OF_IMAGE_COLOR);
    
    glitchEffect.setup(&liveVideoFbo);
    
    bDirectglitch = false;
    
}






//--------------------------------------------------------------
void LiveCamGlitch::update(){
    
    if (webCam->isFrameNew()){

        windowView.setFromPixels(webCam->getPixels());
        windowView.setROI(640, 0, videoW * 0.5, videoH);
        captureCam.setFromPixels( windowView.getRoiPixels() );

        liveVideoFbo.begin();
        ofColor(0,255);
        captureCam.draw(0, 0);
        liveVideoFbo.end();

    }
        
    glitchEffect.setFx(OFXPOSTGLITCH_CONVERGENCE, midiInput->drumPad[0]);
    glitchEffect.setFx(OFXPOSTGLITCH_GLOW, midiInput->drumPad[1]);
    glitchEffect.setFx(OFXPOSTGLITCH_SHAKER, midiInput->drumPad[2]);
    glitchEffect.setFx(OFXPOSTGLITCH_CUTSLIDER, midiInput->drumPad[3]);
    glitchEffect.setFx(OFXPOSTGLITCH_TWIST, midiInput->drumPad[4]);
    glitchEffect.setFx(OFXPOSTGLITCH_NOISE, midiInput->drumPad[5]);
    glitchEffect.setFx(OFXPOSTGLITCH_SLITSCAN, midiInput->drumPad[6]);
    glitchEffect.setFx(OFXPOSTGLITCH_SWELL, midiInput->drumPad[7]);

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
    imgDirectGlitch.setFromPixels(_c, videoW, videoH, OF_IMAGE_COLOR);
    
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
    
    
    webCam->draw(0, 0);
    glitchEffect.generateFx();
    liveVideoFbo.draw(640, 0);  // 640 : 960

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
    
//    if (key == '1') glitchEffect.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
//    if (key == '2') glitchEffect.setFx(OFXPOSTGLITCH_GLOW			, true);
//    if (key == '3') glitchEffect.setFx(OFXPOSTGLITCH_SHAKER			, true);
//    if (key == '4') glitchEffect.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
//    if (key == '5') glitchEffect.setFx(OFXPOSTGLITCH_TWIST			, true);
//    if (key == '6') bDirectglitch = true;
//    if (key == '7') glitchEffect.setFx(OFXPOSTGLITCH_NOISE			, true);
//    if (key == '8') glitchEffect.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
//    if (key == '9') glitchEffect.setFx(OFXPOSTGLITCH_SWELL			, true);
//    if (key == '0') glitchEffect.setFx(OFXPOSTGLITCH_INVERT			, true);
//    
//    if (key == 'q') glitchEffect.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
//    if (key == 'w') glitchEffect.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
//    if (key == 'e') glitchEffect.setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
//    if (key == 'r') glitchEffect.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
//    if (key == 't') glitchEffect.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
//    if (key == 'y') glitchEffect.setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
//    if (key == 'u') glitchEffect.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);
    
}

//--------------------------------------------------------------
void LiveCamGlitch::keyReleased(int key){
    
//    if (key == '1') glitchEffect.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
//    if (key == '2') glitchEffect.setFx(OFXPOSTGLITCH_GLOW			, false);
//    if (key == '3') glitchEffect.setFx(OFXPOSTGLITCH_SHAKER			, false);
//    if (key == '4') glitchEffect.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
//    if (key == '5') glitchEffect.setFx(OFXPOSTGLITCH_TWIST			, false);
//    if (key == '6') bDirectglitch = false;
//    if (key == '7') glitchEffect.setFx(OFXPOSTGLITCH_NOISE			, false);
//    if (key == '8') glitchEffect.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
//    if (key == '9') glitchEffect.setFx(OFXPOSTGLITCH_SWELL			, false);
//    if (key == '0') glitchEffect.setFx(OFXPOSTGLITCH_INVERT			, false);
//    
//    if (key == 'q') glitchEffect.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
//    if (key == 'w') glitchEffect.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
//    if (key == 'e') glitchEffect.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
//    if (key == 'r') glitchEffect.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
//    if (key == 't') glitchEffect.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
//    if (key == 'y') glitchEffect.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
//    if (key == 'u') glitchEffect.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);
//    
//    if (key == ' ') baseArchData->keyInteraction(' ');
    
}




