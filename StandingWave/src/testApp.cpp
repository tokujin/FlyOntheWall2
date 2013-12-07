#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    ofBackground(100);
    ofEnableBlendMode(OF_BLENDMODE_ADD);

    //sound related
    soundPlay = false;

    //load image
    particleImage.loadImage("particle.png");

    //these points are substituted by joints data
    //So, if you want to connect leftHand1(user 1) and leftHand2(user 2)
    //a = leftHand1, b = leftHand2
    a.set(ofGetWidth()/4, ofGetHeight()/4);
    b.set(ofGetWidth()*3/4, ofGetHeight()*3/4);

    Parameter_Set(a,b);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    c = ofVec2f(mouseX, mouseY);
    Vibration_Calc(a, b, c);

}

//--------------------------------------------------------------
void testApp::draw(){
    
    Vibration_Draw(a, b, c);

    if (soundPlay == 1) {
        //sound play
        //now instead of playing sound
        ofSetColor(255, 0,0);
        ofCircle(mouseX, mouseY, 40);
    }

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
