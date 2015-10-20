//
//  SpeechVideoSynth.hpp
//  BinaryPatinaII
//
//  Created by Jeong-Ho on 20/10/15.
//
//

#pragma once


#ifndef SpeechVideoSynth_hpp
#define SpeechVideoSynth_hpp

#include "ofMain.h"

#include "SceneSetup.hpp"

#include "ofxOpenCv.h"

class SpeechVideoSynth : public SceneSetup {
    
public:
    
    SpeechVideoSynth();
    ~SpeechVideoSynth();
    
    void setup();
    void update();
    void draw();
    
    void randomWindowsPosition();
    
    void movieLoad();
    void keyReleased(int key);
    
    void movieAllPlay(int _pos);
    
    ofVideoPlayer speech01_shell;
    ofVideoPlayer speech02_thingy;
    ofVideoPlayer speech03_stringer;
    ofVideoPlayer speech04_oddity;
    
    ofVideoPlayer speechVideo[4];
    
    ofxCvColorImage windowView;
    vector<ofxCvColorImage> windowMovies;
    vector<int> indexX;
    vector<int> indexY;
    vector<int> captureIndexX;
    vector<int> captureIndexY;
    
    int windowsNum;
    
    int indexMovie;
    int indexMovieOldNum;
    bool movieOn;
    
    int movieFrame[4];
    
    
};


#endif /* SpeechVideoSynth_hpp */




