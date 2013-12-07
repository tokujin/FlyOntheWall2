#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(100);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    myVibration.a = ofVec2f(ofGetWidth()/4, ofGetHeight()/4);
    myVibration.b = ofVec2f(ofGetWidth()*3/4, ofGetHeight()*3/4);
    myVibration.set();

}

//--------------------------------------------------------------
void testApp::update(){
    
    c = ofVec2f(mouseX, mouseY);
    myVibration.c;
    myVibration.update();
    myVibration.decay;

    cout << myVibration.decay <<endl;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    myVibration.draw();
    ofCircle(c, 20);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
