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

#include "BaseArch.h"


class Pluto : public ofBaseApp {
    
    public :
    
    Pluto();
    ~Pluto();
    
    void setup();
    void update();
    void draw();
    
    void inputBaseArch(BaseArch & _baseArch);

    BaseArch * baseArchData;
    
    ofImage pluto;
    
    float xyScale;

};

#endif /* Pluto_hpp */
