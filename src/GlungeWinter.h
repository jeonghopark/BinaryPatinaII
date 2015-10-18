#pragma once

#ifndef __GlungeWinter__
#define __GlungeWinter__


#include "ofMain.h"

#include "SceneSetup.hpp"
#include "BaseArch.h"

class GlungeWinter : public ofBaseApp, public SceneSetup {
    
    
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
 
//    void inputBaseArch(BaseArch &);
    BaseArch * baseArchData;
    
    ofImage grungeTexture;
    
};

#endif
