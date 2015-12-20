//
//  MakeChecker.hpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 20/12/15.
//
//
#pragma once

#ifndef MakeChecker_hpp
#define MakeChecker_hpp

#include "ofMain.h"
#include "ofxFontStash.h"

//#define COLUMN_SIZE 9
//#define ROW_SIZE 9
//#define FRAMEWEIGHT 10

//#define WINDOWS_COLUMN = 8;
//#define WINDOWS_Row = 8;

class MakeChecker {
    
    public :
    
    MakeChecker();
    ~MakeChecker();
    
    ofVec2f windowsOriginCenter[8][8];
    ofVec2f windowsCorner[64][4];
    ofVec2f framesCenter[9][9];
    ofVec2f fassadeCorner[4];
    
    vector<float> windowsCornerNumber;
    
    void setupDefault();
    
    void randomNumberGenerator();
    
    ofxFontStash * font;
    void inputFont(ofxFontStash & _f);
    
    
    void keyInteraction(int key);
    
    float mainOffSetXPos, mainOffSetYPos;
    
    void guideFrames(ofColor _c = ofColor(0, 150, 0, 180));
    void guideLines(ofColor _c = ofColor(0, 255, 0, 180));
    void guidePoints(ofColor _c = ofColor(0, 220, 0, 180));
    void drawEdgeCover(ofColor _c = ofColor(255, 30));
    void guideCrossPoints(ofColor _c = ofColor(0, 220, 0, 180), float _size = 6);
    void drawPointNumber( ofColor _c = ofColor(255, 255) );
    void drawWindows( ofColor _c = ofColor(255, 0) );
    void drawRandomWindows( ofColor _c = ofColor(255, 0) );
    void drawWindowNumber( ofColor _c = ofColor(255, 0) );
    
    bool oldOn;
    
    string alphabet[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };

    
};

#endif /* MakeChecker_hpp */
