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
#include "ofxOpenCv.h"

#include "BaseArch.h"

class WebLiveCam : public ofBaseApp{
    
public:
    
    WebLiveCam();
    ~WebLiveCam();
    
    void setup();
    void update();
    void draw();
    
    void keyReleased(int key);
    
    void inputBaseArch(BaseArch &);
    
    BaseArch * baseArchData;

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




