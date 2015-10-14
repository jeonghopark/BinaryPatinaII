#include "GlungeWinter.h"

//--------------------------------------------------------------
GlungeWinter::GlungeWinter() {

    grungeTexture.load("free-grunge-textures-backgrounds-12.jpg");

}


//--------------------------------------------------------------
GlungeWinter::~GlungeWinter() {

}


//--------------------------------------------------------------
void GlungeWinter::setup(){

    
    
}


//--------------------------------------------------------------
void GlungeWinter::inputBaseArch(BaseArch & _baseArch){
    
    baseArchData = & _baseArch;
    
}



//--------------------------------------------------------------
void GlungeWinter::update() {


}



//--------------------------------------------------------------
void GlungeWinter::drawBackTexture() {

    ofPushMatrix();
    
    ofPushStyle();
    
    ofSetColor(255, 30);
    
    float _w = baseArchData->fassadeCorner[1].x - baseArchData->fassadeCorner[0].x;
    float _h = baseArchData->fassadeCorner[3].y - baseArchData->fassadeCorner[0].y;
    float _x = baseArchData->fassadeCorner[0].x;
    
    grungeTexture.draw(_x, 0, _w, _h);
    
    ofPopStyle();

    ofPopMatrix();
    
}



//--------------------------------------------------------------
void GlungeWinter::drawBack() {
    
    ofPushMatrix();
    
    ofPushStyle();
    
    for (int j=0; j<4; j++) {
        for (int i=0; i<15; i++) {
            ofBeginShape();
            ofSetColor( ofColor::fromHsb(ofRandom(255), ofRandom(255), ofRandom(255), 50) );
            
            float _centerX = baseArchData->framesCenter[11][1].x;
            float _centerY = (baseArchData->windowsCorner[10+22*j][2].y + baseArchData->windowsCorner[10+22*(j+1)][0].y) * 0.5;
            
            float _xL = _centerX - i * 40;
            float _xR = _centerX + i * 40;
            float _yU = _centerY - 6;
            float _yD = _centerY + 6;
            
            
            ofVertex( _xL, _yD);
            ofVertex( _xL, _yU);
            ofVertex( _xR, _yU);
            ofVertex( _xR, _yD);
            
            ofEndShape();
        }
    }
    
    ofPopStyle();
    
    ofPopMatrix();
    
    
}



//--------------------------------------------------------------
void GlungeWinter::drawFront() {
    

    ofPushMatrix();
    ofPushStyle();
    
//        ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofEnableBlendMode( OF_BLENDMODE_MULTIPLY );
    

    drawVertical();
    
    drawHorizon();
    
    
    ofDisableBlendMode();
    ofPopStyle();
    ofPopMatrix();
    

    
}


//--------------------------------------------------------------
void GlungeWinter::drawVertical(){
    
    ofPushStyle();
    
    for (int i=0; i<15; i++) {
        ofBeginShape();
        ofSetColor( ofColor::fromHsb(15, 183, 120, 50) );
        
        float _centerX = baseArchData->framesCenter[11][0].x;
        float _centerY = (baseArchData->windowsCorner[10][0].y + baseArchData->fassadeCorner[0].y) * 0.5;
        
        float _xL = _centerX - i * 40;
        float _xR = _centerX + i * 40;
        float _yU = _centerY - 9;
        float _yD = _centerY + 9;
        
        
        ofVertex( _xL, _yD);
        ofVertex( _xL, _yU);
        ofVertex( _xR, _yU);
        ofVertex( _xR, _yD);
        
        ofEndShape();
    }
    
    ofPopStyle();
    
    
    ofPushStyle();
    
    for (int j=0; j<4; j++) {
        for (int i=0; i<15; i++) {
            ofBeginShape();
            ofSetColor( ofColor::fromHsb(15, 183, 120, 50) );
            
            float _centerX = baseArchData->framesCenter[11][1].x;
            float _centerY = (baseArchData->windowsCorner[10+22*j][2].y + baseArchData->windowsCorner[10+22*(j+1)][0].y) * 0.5;
            
            float _xL = _centerX - i * 40;
            float _xR = _centerX + i * 40;
            float _yU = _centerY - 6;
            float _yD = _centerY + 6;
            
            
            ofVertex( _xL, _yD);
            ofVertex( _xL, _yU);
            ofVertex( _xR, _yU);
            ofVertex( _xR, _yD);
            
            ofEndShape();
        }
    }
    
    
    ofPopStyle();
    
    
    
    ofPushStyle();
    
    for (int i=0; i<15; i++) {
        ofBeginShape();
        ofSetColor( ofColor::fromHsb(15, 183, 120, 50) );
        
        float _centerX = baseArchData->framesCenter[11][0].x;
        float _centerY = (baseArchData->windowsCorner[10+22*4][3].y + baseArchData->fassadeCorner[2].y) * 0.5;
        
        float _xL = _centerX - i * 40;
        float _xR = _centerX + i * 40;
        float _yU = _centerY - 6;
        float _yD = _centerY + 6;
        
        
        ofVertex( _xL, _yD);
        ofVertex( _xL, _yU);
        ofVertex( _xR, _yU);
        ofVertex( _xR, _yD);
        
        ofEndShape();
    }
    
    ofPopStyle();

}

//--------------------------------------------------------------
void GlungeWinter::drawHorizon(){
    
    
    ofPushStyle();
    

    for (int i=0; i<10; i++) {
        
        ofBeginShape();
        ofSetColor( ofColor::fromHsb(15, 183, 120, 50) );
        
        float _centerX = (baseArchData->fassadeCorner[0].x + baseArchData->windowsCorner[0][0].x) * 0.5;
        float _centerY = baseArchData->windowsOriginCenter[10][2].y;
        
        float _xL = _centerX - 6;
        float _xR = _centerX + 6;
        float _yU = _centerY - i * 40;
        float _yD = _centerY + i * 40;
        
        
        ofVertex( _xL, _yD);
        ofVertex( _xL, _yU);
        ofVertex( _xR, _yU);
        ofVertex( _xR, _yD);
        
        ofEndShape();
        
    }

    
    for (int j=0; j<22-1; j++) {
        for (int i=0; i<10; i++) {

            ofBeginShape();
            ofSetColor( ofColor::fromHsb(15 * i, 183, 120, 50) );
            
            float _centerX = (baseArchData->windowsCorner[j][1].x + baseArchData->windowsCorner[j+1][0].x) * 0.5;
            float _centerY = baseArchData->windowsOriginCenter[10][2].y;
            
            float _xL = _centerX - 6;
            float _xR = _centerX + 6;
            float _yU = _centerY - i * 40;
            float _yD = _centerY + i * 40;
            
            
            ofVertex( _xL, _yD);
            ofVertex( _xL, _yU);
            ofVertex( _xR, _yU);
            ofVertex( _xR, _yD);
            
            ofEndShape();
            
        }
    }
    
    
    for (int i=0; i<10; i++) {
        
        ofBeginShape();
        ofSetColor( ofColor::fromHsb(15, 183, 120, 50) );
        
        float _centerX = (baseArchData->fassadeCorner[1].x + baseArchData->windowsCorner[21][1].x) * 0.5;
        float _centerY = baseArchData->windowsOriginCenter[10][2].y;
        
        float _xL = _centerX - 6;
        float _xR = _centerX + 6;
        float _yU = _centerY - i * 40;
        float _yD = _centerY + i * 40;
        
        
        ofVertex( _xL, _yD);
        ofVertex( _xL, _yU);
        ofVertex( _xR, _yU);
        ofVertex( _xR, _yD);
        
        ofEndShape();
        
    }

    
    ofPopStyle();
    
    
}







