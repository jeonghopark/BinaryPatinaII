//
//  MakeChecker.cpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 20/12/15.
//
//

#include "MakeChecker.hpp"


MakeChecker::MakeChecker(){
    
    setupDefault();
    randomNumberGenerator();

}


MakeChecker::~MakeChecker(){
    
}


//--------------------------------------------------------------
void MakeChecker::inputFont(ofxFontStash & _f){
    font = & _f;
}

//--------------------------------------------------------------
void MakeChecker::setupDefault(){
    
    
    //    font.setup("Vera.ttf", 1.0, 1024, true, 8, 1.0);
    //    font.addFont("VeraMono-Bold.ttf");
    
    float _sizeRatio = 1; // 1.5 : 1
    
    float _boxW = 90;
    float _boxH = 90;
    float _frameS = 10;

    ofPoint _topLeft = ofPoint(280 - _frameS * 0.5, 0);
    ofPoint _topRight = ofPoint(1000 + _frameS * 0.5, 0);
    ofPoint _bottomLeft = ofPoint(280 - _frameS * 0.5, 720);
    ofPoint _bottomRight = ofPoint(1000 + _frameS * 0.5, 720);
    
    fassadeCorner[0] = _topLeft;
    fassadeCorner[1] = _topRight;
    fassadeCorner[2] = _bottomRight;
    fassadeCorner[3] = _bottomLeft;
    
    
    for (int k=0; k<8; k++) {
        for (int j=0; j<8; j++) {
            for (int i=0; i<4; i++) {
                
                float _x;
                float _y;
                
                if (i==0) {
                    _x = j * _boxW + _frameS * 0.5;
                    _y = k * _boxH + _frameS * 0.5;
                    windowsCorner[j+k*8][i] = ofVec2f( _x, _y );
                } else if (i==1) {
                    _x = j * _boxW - _frameS * 0.5 + _boxW;
                    _y = k * _boxH + _frameS * 0.5;
                    windowsCorner[j+k*8][i] = ofVec2f( _x, _y );
                } else if (i==2) {
                    _x = j * _boxW - _frameS * 0.5 + _boxW;
                    _y = k * _boxH - _frameS * 0.5 + _boxH;
                    windowsCorner[j+k*8][i] = ofVec2f( _x, _y );
                } else if (i==3) {
                    _x = j * _boxW + _frameS * 0.5;
                    _y = k * _boxH - _frameS * 0.5 + _boxH;
                    windowsCorner[j+k*8][i] = ofVec2f( _x, _y );
                }
                
                
            }
        }
    }
    
    
    for (int j=0; j<8; j++) {
        for (int i=0; i<8; i++) {
            int _index = i + j * 8;
            float _x = (windowsCorner[_index][1].x + windowsCorner[_index][0].x) * 0.5;
            float _y = (windowsCorner[_index][3].y + windowsCorner[_index][0].y) * 0.5;
            windowsOriginCenter[i][j] = ofVec2f( _x, _y );
        }
    }
    
    
//    for (int i=1; i<9; i++) {
//        float _x = _boxW * i + _frameS * 0.5;
//        float _y = _boxH * i + _frameS * 0.5;
//        framesCenter[i][0] = ofVec2f( _x, _y );
//    }
//    
//    for (int i=1; i<23; i++) {
//        float _x = ofToFloat(csv.data[i+31][0]) * _sizeRatio;
//        float _y = abs(windowsCorner[i+88][3].y + ofToFloat(csv.data[i+31][1]) * _sizeRatio) * 0.5;
//        framesCenter[i][5] = ofVec2f( _x, _y );
//    }
    
    for (int j=0; j<9; j++) {
        for (int i=0; i<9; i++) {
            float _x = _boxW * i + _frameS * 0.5;
            float _y = _boxH * j + _frameS * 0.5;
            framesCenter[i][j] = ofVec2f( _x, _y );
        }
    }
    
//    for (int j=1; j<5; j++) {
//        float _x = abs(ofToFloat(csv.data[(j-1)+23][0]) * _sizeRatio + windowsCorner[j*22][0].x) * 0.5;
//        float _y = ofToFloat(csv.data[j-1+23][1]) * _sizeRatio;
//        framesCenter[0][j] = ofVec2f( _x, _y );
//    }
//    
//    
//    for (int j=1; j<5; j++) {
//        float _x = abs(ofToFloat(csv.data[(j-1)+27][0]) * _sizeRatio + windowsCorner[(j-1)*22+21][1].x) * 0.5;
//        float _y = ofToFloat(csv.data[j-1+23][1]) * _sizeRatio;
//        framesCenter[22][j] = ofVec2f( _x, _y );
//    }
    
//    framesCenter[0][0] = (windowsCorner[0][0] + fassadeCorner[0]) * 0.5;
//    framesCenter[9][0] = (windowsCorner[21][1] + fassadeCorner[1]) * 0.5;
//    framesCenter[9][9] = (windowsCorner[109][2] + fassadeCorner[2]) * 0.5;
//    framesCenter[0][9] = (windowsCorner[88][3] + fassadeCorner[3]) * 0.5;
    
    
    mainOffSetXPos = (ofGetWidth() - (fassadeCorner[0].x + fassadeCorner[1].x)) * 0.5;
    mainOffSetYPos = (ofGetHeight() - (fassadeCorner[0].y + fassadeCorner[3].y)) * 0.5;
    
    
    
    oldOn = false;
    
}


//--------------------------------------------------------------
void MakeChecker::guideFrames(ofColor _c){
    
    ofPushMatrix();
    ofPushStyle();
    
    ofSetColor(_c);
    
    float _xRS = fassadeCorner[0].x;
    float _yRS = fassadeCorner[0].y;
    float _wRS = windowsCorner[0][0].x - fassadeCorner[0].x;
    float _hRS = fassadeCorner[3].y;
    ofDrawRectangle( _xRS, _yRS, _wRS, _hRS );
    
    for (int i=0; i<8; i++) {
        float _x = windowsCorner[i][1].x;
        float _y = fassadeCorner[0].y;
        float _w = windowsCorner[i+1][0].x - windowsCorner[i][1].x;
        float _h = fassadeCorner[3].y;
        ofDrawRectangle( _x, _y, _w, _h );
    }
    
    float _xRE = windowsCorner[8][1].x;
    float _yRE = fassadeCorner[0].y;
    float _wRE = fassadeCorner[1].x - windowsCorner[8][1].x;
    float _hRE = fassadeCorner[3].y;
    ofDrawRectangle( _xRE, _yRE, _wRE, _hRE );
    
    
    float _xCS = fassadeCorner[0].x;
    float _yCS = windowsCorner[0][0].y;
    float _wCS = fassadeCorner[1].x - fassadeCorner[0].x;
    float _hCS = fassadeCorner[0].y - windowsCorner[0][0].y;
    ofDrawRectangle( _xCS, _yCS, _wCS, _hCS );
    
    for (int i=0; i<4; i++) {
        float _x = fassadeCorner[0].x;
        float _y = windowsCorner[i*8][3].y;
        float _w = fassadeCorner[1].x - fassadeCorner[0].x;
        float _h = windowsCorner[(i+1)*8][0].y - windowsCorner[i*8][3].y;
        ofDrawRectangle( _x, _y, _w, _h );
    }
    
//    float _xCE = fassadeCorner[0].x;
//    float _yCE = windowsCorner[88][3].y;
//    float _wCE = fassadeCorner[1].x - fassadeCorner[0].x;
//    float _hCE = fassadeCorner[3].y - windowsCorner[88][3].y;
//    ofDrawRectangle( _xCE, _yCE, _wCE, _hCE );
    
    
    ofPopStyle();
    ofPopMatrix();
    
}


//--------------------------------------------------------------
void MakeChecker::guideLines(ofColor _c){
    
    ofEnableAlphaBlending();
    
    ofPushMatrix();
    
    ofPushStyle();
    
    ofSetColor(_c);
    
    for (int i=0; i<8-1; i++) {
        for (int j=0; j<8; j++) {
            ofDrawLine( windowsOriginCenter[i][j].x, windowsOriginCenter[i][j].y, windowsOriginCenter[i+1][j].x, windowsOriginCenter[i+1][j].y );
        }
    }
    
    for (int i=0; i<8; i++) {
        for (int j=0; j<8-1; j++) {
            ofDrawLine( windowsOriginCenter[i][j].x, windowsOriginCenter[i][j].y, windowsOriginCenter[i][j+1].x, windowsOriginCenter[i][j+1].y );
        }
    }
    
    
    ofSetColor(_c);
    
    
    for (int i=0; i<9-1; i++) {
        for (int j=0; j<9; j++) {
            ofDrawLine( framesCenter[i][j].x, framesCenter[i][j].y, framesCenter[i+1][j].x, framesCenter[i+1][j].y );
        }
    }
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9-1; j++) {
            ofDrawLine( framesCenter[i][j].x, framesCenter[i][j].y, framesCenter[i][j+1].x, framesCenter[i][j+1].y );
        }
    }
    
    
    ofPopStyle();
    
    ofPopMatrix();
    
    ofDisableAlphaBlending();
    
    
}


//--------------------------------------------------------------
void MakeChecker::guidePoints(ofColor _c){
    
    int _size = 3;
    
    ofEnableAlphaBlending();
    
    
    ofPushMatrix();
    
    ofPushStyle();
    
    ofSetColor(_c);
    
    for (int i=0; i<64; i++) {
        for (int j=0; j<4; j++) {
            float _xS = windowsCorner[i][j].x;
            float _yS = windowsCorner[i][j].y;
            ofDrawCircle( _xS, _yS, _size );
        }
    }
    
    ofSetColor(_c, 120);
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            float _xS = framesCenter[i][j].x;
            float _yS = framesCenter[i][j].y;
            ofDrawCircle( _xS, _yS, _size );
        }
    }
    
    ofSetColor(_c);
    
    for (int i=0; i<4; i++) {
        ofDrawCircle( fassadeCorner[i], _size );
    }
    
    ofPopStyle();
    
    ofPopMatrix();
    
    ofDisableAlphaBlending();
    
    
}


//--------------------------------------------------------------
void MakeChecker::guideCrossPoints(ofColor _c, float _size){
    
    ofEnableAlphaBlending();
    
    
    ofPushMatrix();
    
    ofPushStyle();
    
    ofSetColor(_c);
    
    for (int i=0; i<64; i++) {
        for (int j=0; j<4; j++) {
            float _xS = windowsCorner[i][j].x;
            float _yS = windowsCorner[i][j].y;
            ofDrawLine( _xS - _size, _yS, _xS + _size, _yS );
            ofDrawLine( _xS, _yS - _size, _xS, _yS + _size );
        }
    }
    
    ofSetColor(_c, 120);
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            float _xS = framesCenter[i][j].x;
            float _yS = framesCenter[i][j].y;
            ofDrawLine( _xS - _size, _yS, _xS + _size, _yS );
            ofDrawLine( _xS, _yS - _size, _xS, _yS + _size );
        }
    }
    
    
    for (int i=0; i<4; i++) {
        float _xS = fassadeCorner[i].x;
        float _yS = fassadeCorner[i].y;
        ofDrawLine( _xS - _size, _yS, _xS + _size, _yS );
        ofDrawLine( _xS, _yS - _size, _xS, _yS + _size );
    }
    
    ofPopStyle();
    
    ofPopMatrix();
    
    
    ofDisableAlphaBlending();
    
    
}


//--------------------------------------------------------------
void MakeChecker::drawEdgeCover(ofColor _c){
    
    ofEnableAlphaBlending();
    
    
    ofPushStyle();
    
    ofSetColor(_c);
    
    ofBeginShape();
    ofVertex(-mainOffSetXPos, -mainOffSetYPos);
    ofVertex(ofGetWidth()-mainOffSetXPos, -mainOffSetYPos);
    ofVertex(fassadeCorner[0].x, fassadeCorner[0].y);
    ofVertex(fassadeCorner[3].x, fassadeCorner[3].y);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(ofGetWidth()-mainOffSetXPos, -mainOffSetYPos);
    ofVertex(ofGetWidth()-mainOffSetXPos, ofGetHeight()-mainOffSetYPos);
    ofVertex(fassadeCorner[1].x, fassadeCorner[1].y);
    ofVertex(fassadeCorner[0].x, fassadeCorner[0].y);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(ofGetWidth()-mainOffSetXPos, ofGetHeight()-mainOffSetYPos);
    ofVertex(-mainOffSetXPos, ofGetHeight()-mainOffSetYPos);
    ofVertex(fassadeCorner[2].x, fassadeCorner[2].y);
    ofVertex(fassadeCorner[1].x, fassadeCorner[1].y);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(-mainOffSetXPos, ofGetHeight()-mainOffSetYPos);
    ofVertex(-mainOffSetXPos, -mainOffSetYPos);
    ofVertex(fassadeCorner[3].x, fassadeCorner[3].y);
    ofVertex(fassadeCorner[2].x, fassadeCorner[2].y);
    ofEndShape();
    
    ofPopStyle();
    
    ofDisableAlphaBlending();
    
    
}



//--------------------------------------------------------------
void MakeChecker::drawPointNumber( ofColor _c ){
    
    ofEnableAlphaBlending();
    
    ofPushMatrix();
    
    
    ofPushStyle();
    
    
    ofSetColor(_c);
    
    //    for (int i=0; i<110; i++) {
    //        for (int j=0; j<5; j++) {
    //
    //            float _xS = windowsCorner[i][j].x;
    //            float _yS = windowsCorner[i][j].y;
    //
    //            ofDrawBitmapString(ofToString(windowsCornerNumber[i][j],0), _xS, _yS);
    //
    //        }
    //    }
    
    ofSetColor(_c);
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            float _xS = framesCenter[i][j].x;
            float _yS = framesCenter[i][j].y;
            string _s = ofToHex(&windowsCornerNumber[i+j]);
            string _sS = ofToString(windowsCornerNumber[i+j], 4);
            font->draw(ofToString(windowsCornerNumber[i+j]), 14, _xS, _yS + 6);
        }
    }
    
    
    //    for (int i=0; i<4; i++) {
    //        float _xS = fassadeCorner[i].x;
    //        float _yS = fassadeCorner[i].y;
    //
    //        ofDrawBitmapString(ofToString(windowsCornerNumber[i],0), _xS, _yS);
    //
    //    }
    
    
    ofPopStyle();
    
    
    ofPopMatrix();
    
    ofDisableAlphaBlending();
    
    
}


//--------------------------------------------------------------
void MakeChecker::drawWindows( ofColor _c ){
    
    ofEnableAlphaBlending();
    
    
    ofPushMatrix();
    ofPushStyle();
    
    
    ofSetColor(_c);
    
    float _w = windowsCorner[0][1].x - windowsCorner[0][0].x;
    float _h = windowsCorner[0][0].y - windowsCorner[0][3].y;
    
    
    for (int i=0; i<22; i++) {
        for (int j=0; j<5; j++) {
            float _x = windowsOriginCenter[i][j].x - _w * 0.5;
            float _y = windowsOriginCenter[i][j].y - _h * 0.5;
            
            ofDrawRectangle( _x, _y, _w, _h );
        }
    }
    
    
    ofPopStyle();
    ofPopMatrix();
    
    ofDisableAlphaBlending();
    
    
}


//--------------------------------------------------------------
void MakeChecker::drawRandomWindows( ofColor _c ){
    
    
    int _windowsVerticalOn[4];
    int _windowsHorizomOn[2];
    for (int i=0; i<4; i++) {
        _windowsVerticalOn[i] = (int)ofRandom(21);
    }
    for (int i=0; i<2; i++) {
        _windowsHorizomOn[i] = (int)ofRandom(4);
    }
    
    ofEnableAlphaBlending();
    
    
    ofPushMatrix();
    ofPushStyle();
    
    
    ofSetColor(_c);
    
    float _w = windowsCorner[0][1].x - windowsCorner[0][0].x;
    float _h = windowsCorner[0][0].y - windowsCorner[0][3].y;
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<2; j++) {
            
            int _i = _windowsVerticalOn[i];
            int _j = _windowsHorizomOn[j];
            
            float _x = windowsOriginCenter[_i][_j].x - _w * 0.5;
            float _y = windowsOriginCenter[_i][_j].y - _h * 0.5;
            
            ofDrawRectangle( _x, _y, _w, _h );
            
        }
    }
    
    
    ofPopStyle();
    ofPopMatrix();
    
    ofDisableAlphaBlending();
    
    
}



//--------------------------------------------------------------
void MakeChecker::drawWindowNumber( ofColor _c ){
    
    
    int _windowsVerticalOn[4];
    int _windowsHorizomOn[2];
    int _windowsNumbers[26];
    
    for (int i=0; i<4; i++) {
        _windowsVerticalOn[i] = floor(ofRandom(22));
    }
    for (int i=0; i<2; i++) {
        _windowsHorizomOn[i] = floor(ofRandom(5));
    }
    for (int i=0; i<8; i++) {
        _windowsNumbers[i] = (int)ofRandom(26);
    }
    
    ofEnableAlphaBlending();
    
    
    ofPushMatrix();
    ofPushStyle();
    
    
    ofSetColor(_c);
    
    float _w = windowsCorner[0][1].x - windowsCorner[0][0].x;
    float _h = windowsCorner[0][0].y - windowsCorner[0][3].y;
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<2; j++) {
            
            int _i = _windowsVerticalOn[i];
            int _j = _windowsHorizomOn[j];
            
            float _x = windowsOriginCenter[_i][_j].x - _w * 0.5;
            float _y = windowsOriginCenter[_i][_j].y - _h * 0.5;
            
            int _index = i + j * 4;
            string _s = alphabet[_windowsNumbers[_index]];
            font->draw(_s, 100, _x, _y - 30 );
        }
    }
    
    
    ofPopStyle();
    ofPopMatrix();
    
    ofDisableAlphaBlending();
    
    
}


//--------------------------------------------------------------
void MakeChecker::randomNumberGenerator(){
    
    windowsCornerNumber.resize(64*4);
    for (int j=0; j<256; j++) {
        float _r = ofRandom(256);
        windowsCornerNumber[j] = _r;
    }
    
    
}



//--------------------------------------------------------------
void MakeChecker::keyInteraction(int key){
    
    if (key == ' ') {
        randomNumberGenerator();
    }
    
}

