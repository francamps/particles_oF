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
    pos.x = p.x; //ofRandom(ofGetWidth());
    pos.y = p.y; //ofRandom(ofGetHeight());
    
    ofVec2f velOffset = ofVec2f(ofRandom(1, 3), ofRandom(1, 3));
    
    vel.x = v.x*.25 + velOffset.x;
    vel.y = v.y*.25 + velOffset.y;
}

//------------------------------------------------------------------
void Particle::update() {
    mAge++;
    if (mAge > mLifespan){
        mIsDead = true;
    }
    noise = ofNoise(pos.x, pos.y, ofGetElapsedTimef()*0.1f);
    
    vel += ofVec2f(cos(noise), sin(noise));
    pos += vel;
    vel *= decay;

    radius = radius*(1.0f - ( mAge / (float)mLifespan ));
    
/*    float d = ofDist(ofGetMouseX(), ofGetMouseY(), pos.x, pos.y);
    if ( d < 150 ) {
        radius = (float)ofMap(d, 0.0, 150.0, 0.0, float(radius0));
    } else {
        radius = radius0;
    }*/
    
//    pos.x = ofNoise(ofGetElapsedTimef()*.25 + seed) * ofGetWidth();
  //  pos.y = ofNoise(ofGetElapsedTimef()*.4 + 10 + seed) * ofGetHeight();
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
    mLifespan = 600;
    mIsDead = false;
    
    //the unique val allows us to set properties slightly differently for each particle
    // This is used as a seed for other stuff
    seed = ofRandom(-10000, 10000);
    
    // Random position to start
//    pos.x = ofRandomWidth();
//    pos.y = ofRandomHeight();
    
    // Random velocity to start with limited range
    //vel.x = ofRandom(-2.9, 2.9);
    //vel.y = ofRandom(-2.9, 2.9);
    decay = ofRandom(0, 1);
    
    // Force vector, defined by a Point object (I know, confusing)
    frc   = ofPoint(0,0,0);
    
    radius0 = sin(pos.x*0.1)*2*cos(pos.y*0.1 + 0.1)*4;//ofRandom(2, 5);
    radius = radius0;
    
}