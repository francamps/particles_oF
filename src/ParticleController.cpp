//
//  ParticleController.cpp
//  Emergence02
//
//  Created by Franc Camps-Febrer on 10/21/14.
//
//

#include "Particle.h"
#include "ParticleController.h"

ParticleController::ParticleController(){

}

void ParticleController::addParticles(ofPoint p, ofVec2f v){
    for(unsigned int i = 0; i < 15; i++ ) {
        ofVec2f rand = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10));
        p = ofPoint(p.x + rand.x, p.y + rand.y);
        Particle pa = Particle( p, v );
        pa.reset();
        vp.push_back( pa );
    }
    
    /*// Make a grid
    for( int y=0; y < 60; y++ ){
        for( int x=0; x < 80; x++ ){
            Particle p = Particle(x*10, y*10);
            vp.push_back(p);
        }
    }*/

//    for (unsigned int i = 0; i < num; i++) {
//        Particle p = Particle();
//        vp.push_back(p);
//    }

    /*for (unsigned int i = 0; i < num; i++) {
     Particle p = Particle();
     mParticles.push_back(p);
   
    }*/
}

void ParticleController::removeParticles(){
    
}

void ParticleController::resetParticles(){
    for (unsigned int i = 0; i < vp.size(); i++) {
        vp[i].reset();
    }
//    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
//        p->reset();
//    }
}

void ParticleController::update(){
    for (unsigned int i = 0; i < vp.size(); i++) {
        if (vp[i].mIsDead) {
            vp.erase(vp.begin() + i);
        } else {
            vp[i].update();
        }
    }
//    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
//        p->update();
//    }
}

void ParticleController::draw(){
    for (unsigned int i = 0; i < vp.size(); i++) {
        vp[i].draw();
    }
//    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
//        p->draw();
//    }
}