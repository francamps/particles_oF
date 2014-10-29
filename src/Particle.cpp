//
//  particle.cpp
//  Emergence02
//
//  Created by Franc Camps-Febrer on 10/21/14.
//
//

#include "Particle.h"


//------------------------------------------------------------------
Particle::Particle(ofPoint p, ofVec2f v){
    pos.x = p.x;
    pos.y = p.y;
    
    ofVec2f velOffset = ofVec2f(ofRandom(-2, 2), ofRandom(-2, 2));
    
    vel.x = v.x*.25 + velOffset.x;
    vel.y = v.y*.25 + velOffset.y;
}

//------------------------------------------------------------------
void Particle::update() {
    mAge++;
    if (mAge > mLifespan || radius < 0.01){
        mIsDead = true;
    }
    noise = ofNoise(pos.x*0.005, pos.y*0.005, ofGetElapsedTimef()*0.1f) * 15;
    
    float agePer = 1.0f - ( mAge / (float)mLifespan );
    
    vel += ofVec2f(cos(noise), sin(noise)) * 1.5f * (1.0f - agePer);
    vel += acc;
    pos += vel;
    vel *= decay;
    acc.set(0, 0);

    radius = radius*agePer;
}

//------------------------------------------------------------------
void Particle::draw() {
    ofSetColor(160, 195, 242, 190);
    ofFill();
    ofCircle(pos.x, pos.y, radius);
}

//------------------------------------------------------------------
void Particle::reset() {
    mAge = 0;
    mLifespan = 1200;
    mIsDead = false;
    
    //the unique val allows us to set properties slightly differently for each particle
    // This is used as a seed for other stuff
    seed = ofRandom(-10000, 10000);
    
    // Random velocity to start with limited range
    decay = ofRandom(0.97, 0.999);
    
    // Force vector, defined by a Point object (I know, confusing)
    acc   = ofPoint(0,0);
    
    radius0 = ofRandom(4, 5);//sin(pos.x*0.1)*2*cos(pos.y*0.1 + 0.1)*4;//ofRandom(2, 5);
    radius = radius0;
    
    mass = radius * radius * 0.5f;
}