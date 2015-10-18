//
//  IndiaTower.cpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 15/10/15.
//
//

#include "IndiaTower.hpp"


//--------------------------------------------------------------
IndiaTower::IndiaTower(){
    
}


//--------------------------------------------------------------
IndiaTower::~IndiaTower(){
    
}


//--------------------------------------------------------------
void IndiaTower::setup(){
    
    spectrumNumbers.setGlobalDpi(72);
    
    spectrumNumbers.load("verdana.ttf", 12);
    //    spectrumNumbers.setSpaceSize(40);
    spectrumNumbers.setLineHeight(15.0f);
    spectrumNumbers.setLetterSpacing(1.2);

}


//--------------------------------------------------------------
void IndiaTower::update(){
    
}


//--------------------------------------------------------------
void IndiaTower::draw(){
    
}


//--------------------------------------------------------------
void IndiaTower::drawingRectColumn(){
    
    //    float _moveFactor = 10;
    //    float _tX = ofMap(kaosPadHorizon, 0, 127, -_moveFactor, _moveFactor);
    //    float _tY = ofMap(kaosPadVertical, 0, 127, 1, _moveFactor);
    
    float _tX = 1;
    float _tY = 1;
    
    vector<float> _inputBins = processFFT->fft.getBins();

    if (processFFT->fft.getBins().size()>0) {
        
        
        float _numberIndex = _inputBins.size();
        float _heightFassade = baseArch->fassadeCorner[3].y - baseArch->fassadeCorner[0].y;
        float _rectHeight = _heightFassade / _numberIndex * _tY;
        
        ofPushStyle();
        
        ofNoFill();
        
        for (int i=0; i<_numberIndex; i++) {
            
            float _hue = ofMap( i, 0, _numberIndex, 0, 255 );
            ofSetColor( ofColor::fromHsb(_hue, 255, 255, 60));
            
            float _center = baseArch->framesCenter[11][0].x;
            float _widthRightRect = _inputBins[i] * 10000;
            float _widthLeftRect = -_inputBins[i] * 10000;
            float _indexPosY = baseArch->fassadeCorner[3].y - _rectHeight * i - _rectHeight;
            
            ofDrawLine( _center, _indexPosY, _center + _widthRightRect, _indexPosY );
            ofDrawLine( _center, _indexPosY, _center + _widthLeftRect, _indexPosY );
            
        }
        
        ofPopStyle();
        
        
        if (processFFT->getSpectrum().size()>0) {
            bezielStart.resize(processFFT->getSpectrum().size());
            
            float _center = baseArch->framesCenter[11][0].x;
            
            for (int i=0; i<bezielStart.size(); i++) {
                
                int _indexShift = 30;
                
                float _widthRightRect = _inputBins[i*_indexShift] * 10000;
                float _widthLeftRect = -_inputBins[i*_indexShift] * 10000;
                float _indexPosY = baseArch->fassadeCorner[3].y - _rectHeight * i *_indexShift - _rectHeight;
                
                ofVec2f _v = ofVec2f(_widthLeftRect + _center, _indexPosY);
                bezielStart[i] = _v;
                
            }
        }


    }
    
    
}

//--------------------------------------------------------------
void IndiaTower::drawingNumber(){
    
    
    if (processFFT->getSpectrum().size()>0) {
        
        vector<float> _inputSpectrum = processFFT->getSpectrum();
        
        float _numberIndex = _inputSpectrum.size();
        float _heightFassade = baseArch->fassadeCorner[3].y - baseArch->fassadeCorner[0].y;
        float _rectHeight = _heightFassade / _numberIndex;
        
        bezielEnd.resize(processFFT->getSpectrum().size());
        
        
        ofEnableAlphaBlending();

        ofPushStyle();
        
        
        float _center = baseArch->framesCenter[11][0].x;
        
        for (int i=0; i<_numberIndex; i++) {
            
            float _widthRightRect = _inputSpectrum[i] * 1;
            float _widthLeftRect = -_inputSpectrum[i] * 1;
            float _indexPosY = baseArch->fassadeCorner[3].y - _rectHeight * i;
            float _indexPosLeftX = baseArch->fassadeCorner[0].x;
            float _indexPosRightX = baseArch->fassadeCorner[1].x;
            
            float _hue = ofMap( i, 0, _numberIndex, 0, 255 );
            ofSetColor( ofColor::fromHsb(_hue, 255, 255, 180));
            
            float _fftMap = ofMap( _inputSpectrum[i], 0.00001, 1.5, 0, 8 );
            string _typeStr = ofToString( _fftMap, 28 );
            
            spectrumNumbers.drawString( _typeStr, _indexPosLeftX, _indexPosY );
            
            float _w = spectrumNumbers.getStringBoundingBox(_typeStr, _indexPosLeftX, _indexPosY).getWidth();
            spectrumNumbers.drawString( _typeStr, _indexPosRightX - _w, _indexPosY );
            
            ofVec2f _v = ofVec2f(_indexPosLeftX + _w, _indexPosY);
            bezielEnd[i] = _v;
    
        }
        
        ofPopStyle();

        ofDisableAlphaBlending();

    }
    
    
    
    
}


//--------------------------------------------------------------
void IndiaTower::drawingBeziel(){
    
    vector<float> _inputBins = processFFT->fft.getBins();
    float _numberIndexBins = _inputBins.size();
    float _heightFassadeBins = baseArch->fassadeCorner[3].y - baseArch->fassadeCorner[0].y;
    float _rectHeightBins = _heightFassadeBins / _numberIndexBins;
    
    vector<float> _inputSpectrum = processFFT->getSpectrum();
    float _numberIndexSpectrum = _inputSpectrum.size();
    float _heightFassadeSpectrum = baseArch->fassadeCorner[3].y - baseArch->fassadeCorner[0].y;
    float _rectHeightSpectrum = _heightFassadeSpectrum / _numberIndexSpectrum;
    
    
    ofPushStyle();
    
    ofNoFill();
    
    float _center = baseArch->framesCenter[11][0].x;
    
    if (bezielStart.size()>0) {
        for (int i=0; i<bezielStart.size(); i++) {
            
            ofDrawBezier(bezielStart[i].x, bezielStart[i].y,
                         bezielStart[i].x - 100, bezielStart[i].y,
                         bezielEnd[i].x + 100, bezielEnd[i].y,
                         bezielEnd[i].x, bezielEnd[i].y);
            
            ofDrawBezier(_center * 2 - bezielStart[i].x, bezielStart[i].y,
                         _center * 2 - bezielStart[i].x + 100, bezielStart[i].y,
                         _center * 2 - bezielEnd[i].x - 100, bezielEnd[i].y,
                         _center * 2 - bezielEnd[i].x, bezielEnd[i].y);
            
        }
    }
    
    ofPopStyle();
    
    
    
}


