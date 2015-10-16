//
//  Labyrinth.cpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 14/10/15.
//
//

#include "Labyrinth.hpp"


//--------------------------------------------------------------
Labyrinth::Labyrinth(){
    
}



//--------------------------------------------------------------
Labyrinth::~Labyrinth(){
    
}


//--------------------------------------------------------------
void Labyrinth::inputBaseArch(BaseArch & _baseArch){
    baseArchData = & _baseArch;
}


//--------------------------------------------------------------
void Labyrinth::setup(){
    
    initParticles(LABYRINTH_LINE_TYPE::CURVE);
    
    _oldType = LABYRINTH_LINE_TYPE::CURVE;
    
}


//--------------------------------------------------------------
void Labyrinth::update(){
    
    for (int i=0; i<particles.size(); i++) {
        particles[i].movingFactor = particles[i].movingFactor + particles[i].movingSpeed *  particles[i].direction;
        
        if ((particles[i].movingFactor < 0.0)||(particles[i].movingFactor > 1.0)) {
            particles[i].direction = -particles[i].direction;
        }
    }
    
}



//--------------------------------------------------------------
void Labyrinth::draw(){
    
    drawParticles();

    
}




//--------------------------------------------------------------
void Labyrinth::initParticles(int _i){
    
    if ((_oldType-_i)!=0) {

        int _numParticles = 120;
        particles.resize(_numParticles);
        
        for (int j=0; j<_numParticles; j++) {
            
            int _xIndex = floor(ofRandom(23));
            int _yIndex = floor(ofRandom(6));
            
            
            ofPolyline _p;
            for (int i=0; i<10; i++) {
                
                int _directionXY = floor(ofRandom(6));
                
                switch (_directionXY) {
                    case 0:
                        _xIndex = _xIndex - 1;
                        _yIndex = _yIndex + 0;
                        break;
                    case 1:
                        _xIndex = _xIndex + 0;
                        _yIndex = _yIndex - 23;
                        break;
                    case 2:
                        _xIndex = _xIndex + 1;
                        _yIndex = _yIndex + 0;
                        break;
                    case 3:
                        _xIndex = _xIndex + 0;
                        _yIndex = _yIndex + 23;
                        break;
                    case 4:
                        _xIndex = _xIndex - 1;
                        _yIndex = _yIndex + 0;
                        break;
                    case 5:
                        _xIndex = _xIndex + 1;
                        _yIndex = _yIndex + 0;
                        break;
                        
                    default:
                        break;
                }
                
                
                if (_i == LABYRINTH_LINE_TYPE::LINE) {
                    ofVec2f _vD = baseArchData->framesCenter[abs(_xIndex)%23][abs(_yIndex)%6];
                    _p.addVertex( _vD );
                } else if (_i == LABYRINTH_LINE_TYPE::CURVE) {
                    ofVec2f _vC = baseArchData->framesCenter[abs(_xIndex)%21+1][abs(_yIndex)%4+1];
                    _p.curveTo(_vC);
                }
                
                
            }
            
            particles[j].pathPolyLine = _p;
            
        }
        
        _oldType = _i;
    
    }

    
}


//--------------------------------------------------------------
void Labyrinth::drawParticles(){
    
    ofPushMatrix();
    
    ofPushStyle();
    
    ofSetColor(255, 20);
    for (int i=0; i<particles.size(); i++) {
        particles[i].pathPolyLine.draw();
    }
    
    ofPushStyle();
    
    ofSetColor( 255, 255 );
    
    for (int i=0; i<particles.size(); i++) {
        
        float _percent = particles[i].movingFactor;
        ofVec2f _v = particles[i].pathPolyLine.getPointAtPercent( _percent );
        ofDrawCircle( _v, particles[i].size );
        
    }
    ofPopStyle();
    
    
    ofSetColor(255, 120);
    
    for (int i=0; i<particles.size(); i++) {
        float _percentS = particles[i].movingFactor;
        ofVec2f _vS = particles[i].pathPolyLine.getPointAtPercent( _percentS );
        
        for (int j=0; j<particles.size(); j++) {
            
            if (i != j) {
                float _percentE = particles[j].movingFactor;
                ofVec2f _vE = particles[j].pathPolyLine.getPointAtPercent( _percentE );
                
                float _dist = _vE.distance(_vS);
                if ( abs(75 - _dist) < 25 ){
                    ofDrawLine( _vS, _vE );
                }
            }
            
        }
        
    }
    
    
    ofPopStyle();
    
    ofPopMatrix();
    
}



//--------------------------------------------------------------
void Labyrinth::keyReleased(int key){
    
}