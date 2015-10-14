#pragma once

#ifndef __binarypatina__sceneSketch2__
#define __binarypatina__sceneSketch2__


#include "ofMain.h"

#include "BaseArch.h"

class GlungeWinter : public ofBaseApp {
    
    
public:

    GlungeWinter();
    ~GlungeWinter();
    
    void setup();
    void update();
    void drawBackTexture();
    void drawBack();
    void drawFront();
    
    void drawVertical();
    void drawHorizon();
 
    void inputBaseArch(BaseArch &);

    BaseArch * baseArchData;
    
    ofImage grungeTexture;
    
};

#endif
