//
//  particle.h
//  Emergence02
//
//  Created by Franc Camps-Febrer on 10/21/14.
//
//

#ifndef __Emergence02__particle__
#define __Emergence02__particle__

#endif

#pragma once
#include "ofMain.h"

class Particle {
    
    public:
        Particle(ofPoint pos, ofVec2f vel);
    
        void setAttractPoints( vector <ofPoint> * attract );
    
        void reset();
        void update();
        void draw();
    
        // Position x,y
        ofPoint pos;
        // Velocity x,y
        ofPoint vel;
        // Force x,y?
        ofPoint acc;
        float mass;
    
        float decay;
    
        float radius0;
        float radius;
    
        float seed;
        float noise;

        int mAge;
        int mLifespan;
        bool mIsDead;
};