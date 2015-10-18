//
//  SceneSetup.hpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 18/10/15.
//
//
#pragma once


#ifndef SceneSetup_hpp
#define SceneSetup_hpp

#include "ofMain.h"

#include "BaseArch.h"
#include "ofxProcessFFT.h"


class SceneSetup {
    
public:
    
    void inputBaseArch(BaseArch & _baseArch);
    void inputFFTP(ProcessFFT & _processFFT);
    void inputWebCam(ofVideoGrabber & _webCamHD);

    BaseArch * baseArch;
    ProcessFFT * processFFT;
    ofVideoGrabber * webCamHD;
    
};


#endif /* SceneSetup_hpp */
