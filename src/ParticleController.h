//
//  ParticleController.h
//  Emergence02
//
//  Created by Franc Camps-Febrer on 10/21/14.
//
//

#ifndef __Emergence02__ParticleController__
#define __Emergence02__ParticleController__

#include <stdio.h>

#endif /* defined(__Emergence02__ParticleController__) */

#pragma once
#include "ofMain.h"
#include <list>

class ParticleController {
    public:
        ParticleController();
    
        void update();
        void draw();
    
        void addParticles(ofPoint p, ofVec2f mv);
        void removeParticles();
    
        void resetParticles();
    
        void repulseParticles();
    
        std::list<Particle> mParticles;
//        vector <Particle> vp;
};