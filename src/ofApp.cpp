#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    ofSetFrameRate(60);
    
    int num = 15000;
//    vp.assign(num, Particle());
//    mParticleController.addParticles();
    
    mParticleController.resetParticles();
}

//--------------------------------------------------------------
void ofApp::update(){
    mouseVel = ofVec2f(ofGetMouseX() - mouseLoc.x, ofGetMouseY() - mouseLoc.y);
    mouseLoc = ofPoint(ofGetMouseX(), ofGetMouseY());
    if (mIsPressed) {
        mParticleController.addParticles(mouseLoc, mouseVel);
    }
    mParticleController.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(60,60,60), ofColor(10,10,10));
    
    mParticleController.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mIsPressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mIsPressed = false;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
