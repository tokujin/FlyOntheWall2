#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myVibration.a = ofVec2f(ofGetWidth()/4, ofGetHeight()/4);
    myVibration.b = ofVec2f(ofGetWidth()*3/4, ofGetHeight()*3/4);
    myVibration.set();
    myVibration.NumPoints = 50;
}

//--------------------------------------------------------------
void testApp::update(){
    c = ofVec2f(mouseX, mouseY);
    myVibration.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    myVibration.draw();
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
