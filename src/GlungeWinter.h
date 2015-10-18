#pragma once

#ifndef __GlungeWinter__
#define __GlungeWinter__


#include "ofMain.h"

#include "SceneSetup.hpp"

class GlungeWinter : public SceneSetup {
    
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
 
    
    ofImage grungeTexture;
    
};

#endif
