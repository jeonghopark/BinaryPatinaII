//
//  WebLiveCam.hpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 15/10/15.
//
//
#pragma once


#ifndef WebLiveCam_hpp
#define WebLiveCam_hpp

#include "ofMain.h"

#include "SceneSetup.hpp"

#include "ofxOpenCv.h"

class WebLiveCam : public SceneSetup {
    
public:
    
    WebLiveCam();
    ~WebLiveCam();
    
    void setup();
    void update();
    void draw();
    
    void randomWindowsPosition();
    
    void keyReleased(int key);
    
    ofVideoPlayer webCam01;

    ofxCvColorImage windowView;
    vector<ofxCvColorImage> windowMovies;
    vector<int> indexX;
    vector<int> indexY;
    vector<int> captureIndexX;
    vector<int> captureIndexY;
    
    int windowsNum;
    
    

};




#endif /* WebLiveCam_hpp */




