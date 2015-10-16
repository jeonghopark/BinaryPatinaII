//
//  Labyrinth.hpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 14/10/15.
//
//

#pragma once

#ifndef Labyrinth_hpp
#define Labyrinth_hpp

#include "ofMain.h"
#include "BaseArch.h"

namespace LABYRINTH_LINE_TYPE {
    enum TYPE {
        LINE,
        CURVE
    };
}

struct Particle : public ofBaseApp {
    
    ofPolyline pathPolyLine;
    float movingFactor = 0;
    float movingSpeed = ofRandom(0.1, 0.6) * 0.01;
    float direction = 1;
    int size = ofRandom(2, 5);
    
};



class Labyrinth {
    
    public :
    
    Labyrinth();
    ~Labyrinth();
    
    void setup();
    void update();
    void draw();

    void keyReleased(int key);


    void inputBaseArch(BaseArch &);
    
    BaseArch * baseArchData;

    void initParticles(int _i);
    void drawParticles();

    vector<Particle> particles;

    int _oldType;
    
    
};


#endif /* Labyrinth_hpp */
