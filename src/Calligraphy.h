//
//  Calligraphy.h
//  MusicFFT_score
//
//  Created by JeongHo Park on 09/07/15.
//
//

#pragma once

#ifndef __MusicFFT_score__Calligraphy__
#define __MusicFFT_score__Calligraphy__

#include "ofMain.h"
#include "SceneSetup.hpp"

#include "ofxProcessFFT.h"

#include "BaseArch.h"

class Calligraphy: public ofBaseApp, public SceneSetup {
    
    vector<float> captureFFTSmoothed;
    vector<int> captureFFTIndex;
    
    vector<Calligraphy> calligraphies;
    vector<ofVec2f> calliPos;

    
public :

    Calligraphy();
    ~Calligraphy();
    
    void setup();
    void update();
//    void inputBaseArch(BaseArch & _baseArch);
//    void inputFFTP(ProcessFFT & _processFFT);
    
    void inputFftSmoothed(vector<float> );
    void draw();
    void drawElement(float _xPos, float _yPos, int _h, float _size);
    
    BaseArch * baseArch;
    ProcessFFT * processFFT;
    
    int calliSize;
    
    int calliYShift;
    bool bClliXPosChange;
    int calliIndex;
    
    float fftValue;

    
    
};


#endif /* defined(__MusicFFT_score__Calligraphy__) */
