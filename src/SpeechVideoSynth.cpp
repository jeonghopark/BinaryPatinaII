//
//  SpeechVideoSynth.cpp
//  BinaryPatinaII
//
//  Created by Jeong-Ho on 20/10/15.
//
//

#include "SpeechVideoSynth.hpp"



//--------------------------------------------------------------
SpeechVideoSynth::SpeechVideoSynth(){
    
}


//--------------------------------------------------------------
SpeechVideoSynth::~SpeechVideoSynth(){
    
}


//--------------------------------------------------------------
void SpeechVideoSynth::movieLoad(){
    
    speech01_shell.load("02_shell_snowden.mp4");
    speech02_thingy.load("03_thingy_harvested.mp4");
    speech03_stringer.load("09_stringer_ericschmidt_fin.mp4");
    speech04_oddity.load("13_oddity_We kill people based on metadata-f.mp4");
    
    speechVideo[0].load("02_shell_snowden.mp4");
    speechVideo[1].load("03_thingy_harvested.mp4");
    speechVideo[2].load("09_stringer_ericschmidt_fin.mp4");
    speechVideo[3].load("13_oddity_We kill people based on metadata-f.mp4");
    
}


//--------------------------------------------------------------
void SpeechVideoSynth::setup(){
    
    movieLoad();
    
    windowView.allocate(960, 540);
    
    
//    windowView.allocate(speech01_shell.getWidth(), speech01_shell.getHeight());
//
//    float _w = baseArch->framesCenter[1][0].x - baseArch->framesCenter[0][0].x;
//    float _h = baseArch->framesCenter[0][1].y - baseArch->framesCenter[0][0].y;
//    
//    windowsNum = 20;
//    
//    windowMovies.resize(windowsNum);
//    for (int i=0; i<windowsNum; i++){
//        windowMovies[i].allocate(_w, _h);
//    }
    
//    randomWindowsPosition();
    
    indexMovie = 0;
    movieOn = false;
    
}



//--------------------------------------------------------------
void SpeechVideoSynth::update(){

    speechVideo[indexMovie].update();

    if (speechVideo[indexMovie].isFrameNew()) {
        windowView.setFromPixels(speechVideo[indexMovie].getPixels());
    }
    
    
    if ((indexMovie == 0)&&!movieOn) {
        speechVideo[0].play();
        speechVideo[1].stop();
        speechVideo[2].stop();
        speechVideo[3].stop();
        indexMovieOldNum = indexMovie;
        movieOn = true;
    } else if ((indexMovie == 1)&&!movieOn) {
        speechVideo[1].play();
        speechVideo[2].stop();
        speechVideo[3].stop();
        speechVideo[0].stop();
        indexMovieOldNum = indexMovie;
        movieOn = true;
    } else if ((indexMovie == 2)&&!movieOn) {
        speechVideo[2].play();
        speechVideo[0].stop();
        speechVideo[1].stop();
        speechVideo[3].stop();
        indexMovieOldNum = indexMovie;
        movieOn = true;
    } else if ((indexMovie == 3)&&!movieOn) {
        speechVideo[3].play();
        speechVideo[0].stop();
        speechVideo[1].stop();
        speechVideo[2].stop();
        indexMovieOldNum = indexMovie;
        movieOn = true;
    }
    
    if (indexMovie != indexMovieOldNum) {
        movieOn = false;
    }
    

    
    
}



//--------------------------------------------------------------
void SpeechVideoSynth::draw(){
    
    
    switch (indexMovie%2) {
            
        case 0:
            movieAllPlay( 0 );
            break;
            
        case 1:
            movieAllPlay( -1 );
            break;
            
        default:
            break;
            
    }
    
    
}


//--------------------------------------------------------------
void SpeechVideoSynth::movieAllPlay(int _pos){
    
    ofEnableAlphaBlending();
    
    float _mainX = baseArch->framesCenter[11][0].x + baseArch->framesCenter[11][0].x * _pos;
    float _mainY = baseArch->framesCenter[11][0].y;
    float _mainW = baseArch->framesCenter[22][0].x - baseArch->framesCenter[11][0].x;
    float _mainH = baseArch->framesCenter[11][5].y - baseArch->framesCenter[11][0].y;
    
    windowView.draw(_mainX, _mainY, _mainW, _mainH);
    
//    for (int i=0; i<windowsNum; i++){
//        ofVec2f _posROIMovies = baseArch->framesCenter[indexX[i]][indexY[i]] + ofVec2f(baseArch->framesCenter[11][0].x * -_pos, 0);
//        windowMovies[i].draw( _posROIMovies );
//    }
    
    ofDisableAlphaBlending();
    
}


//--------------------------------------------------------------
void SpeechVideoSynth::randomWindowsPosition(){
    
//    indexX.resize(windowsNum);
//    indexY.resize(windowsNum);
//    captureIndexX.resize(windowsNum);
//    captureIndexY.resize(windowsNum);
//    for (int i=0; i<windowMovies.size(); i++){
//        indexX[i] = floor( ofRandom(10) );
//        indexY[i] = floor( ofRandom(5) );
//        captureIndexX[i] = floor( ofRandom(10) );
//        captureIndexY[i] = floor( ofRandom(5) );
//    }
    
}


//--------------------------------------------------------------
void SpeechVideoSynth::keyReleased(int key){
    
//    randomWindowsPosition();
    
}



