//
//  WebLiveCam.cpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 15/10/15.
//
//

#include "WebLiveCam.hpp"


//--------------------------------------------------------------
WebLiveCam::WebLiveCam(){
    
}


//--------------------------------------------------------------
WebLiveCam::~WebLiveCam(){
    
}


//--------------------------------------------------------------
void WebLiveCam::setup(){
    
    webCam01.load("Asakusa Traffic Cam - japan - 1151 - 1410 - 2015.mp4");
    webCam01.play();
    windowView.allocate(webCam01.getWidth(), webCam01.getHeight());
    
    float _w = baseArch->framesCenter[1][0].x - baseArch->framesCenter[0][0].x;
    float _h = baseArch->framesCenter[0][1].y - baseArch->framesCenter[0][0].y;
    
    windowsNum = 20;
    
    windowMovies.resize(windowsNum);
    for (int i=0; i<windowsNum; i++){
        windowMovies[i].allocate(_w, _h);
    }
    
    randomWindowsPosition();
    

    
}



//--------------------------------------------------------------
void WebLiveCam::update(){

    webCam01.update();
    
    if (webCam01.isFrameNew()) {
        
        windowView.setFromPixels(webCam01.getPixels());
        
        float _w = baseArch->framesCenter[1][0].x - baseArch->framesCenter[0][0].x;
        float _h = baseArch->framesCenter[0][1].y - baseArch->framesCenter[0][0].y;
        
        for (int i=0; i<windowsNum; i++){
            float _x = captureIndexX[i] * _w;
            float _y = captureIndexY[i] * _h;
            windowView.setROI(_x, _y, _w, _h);
            windowMovies[i].setFromPixels( windowView.getRoiPixels() );
        }
        
    }

    
}



//--------------------------------------------------------------
void WebLiveCam::draw(){
    
    for (int i=0; i<windowsNum; i++){
        windowMovies[i].draw( baseArch->framesCenter[indexX[i]][indexY[i]] );
    }
    
    float _mainX = baseArch->framesCenter[11][0].x;
    float _mainY = baseArch->framesCenter[11][0].y;
    float _mainW = baseArch->framesCenter[22][0].x - baseArch->framesCenter[11][0].x;
    float _mainH = baseArch->framesCenter[11][5].y - baseArch->framesCenter[11][0].y;
    windowView.draw(_mainX, _mainY, _mainW, _mainH);

}


//--------------------------------------------------------------
void WebLiveCam::randomWindowsPosition(){
    
    indexX.resize(windowsNum);
    indexY.resize(windowsNum);
    captureIndexX.resize(windowsNum);
    captureIndexY.resize(windowsNum);
    for (int i=0; i<windowMovies.size(); i++){
        indexX[i] = floor( ofRandom(10) );
        indexY[i] = floor( ofRandom(5) );
        captureIndexX[i] = floor( ofRandom(10) );
        captureIndexY[i] = floor( ofRandom(5) );
    }

}

//--------------------------------------------------------------
void WebLiveCam::keyReleased(int key){
    
    randomWindowsPosition();
    
}



