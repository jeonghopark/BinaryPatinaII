//
//  Pluto.hpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 15/10/15.
//
//

#pragma once

#ifndef Pluto_hpp
#define Pluto_hpp

#include "ofMain.h"
#include "SceneSetup.hpp"


class Pluto : public SceneSetup{
    
    public :
    
    Pluto();
    ~Pluto();
    
    void setup();
    void update();
    void draw();
        
    ofImage pluto;
    
    float xyScale;

};

#endif /* Pluto_hpp */
