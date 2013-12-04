#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    mSender.setup("172.20.10.2", 12345); //149.31.196.84
    //"127.0.1.1" home
    
    
    ofBackground(255);
    
    pos = ofGetWindowSize()/2;
    vel = ofVec2f(11,15);
    
    leftEye.pos = ofPoint( ofGetWindowWidth()/2 - 75, ofGetWindowHeight() * 0.7 );
    rightEye.pos = ofPoint( ofGetWindowWidth()/2 + 75, ofGetWindowHeight() * 0.7 );
    
    
    leftEye2.pos = ofPoint( ofGetWindowWidth()/4 - 75, ofGetWindowHeight() * 0.4 );
    rightEye2.pos = ofPoint( ofGetWindowWidth()/4 + 75, ofGetWindowHeight() * 0.4 );
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    pos += vel;
    
    if (pos.x<0||pos.x>ofGetWindowWidth()*2) {
        vel.x *= -1;
    }
    if (pos.y<0||pos.y>ofGetWindowHeight()) {
        vel.y *= -1;
    }
    ofxOscMessage m2;
    m2.setAddress("/ball/pos");
    m2.addIntArg(pos.x);
    m2.addIntArg(pos.y);
    mSender.sendMessage(m2);
    
    leftEye.mousePos = pos;
    rightEye.mousePos = pos;
    
    leftEye2.mousePos = pos;
    rightEye2.mousePos = pos;
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();
    ofTranslate(-ofGetWindowWidth(), 0);
    ofSetColor(255, 0, 0);
    ofCircle(pos,20);
    ofPopMatrix();
    
    
    
    leftEye.draw();
    rightEye.draw();
    
    leftEye2.draw();
    rightEye2.draw();
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    mousePos.set(x,y);
    ofxOscMessage m;
    m.setAddress("/mouse/pos");
    m.addIntArg(mousePos.x);
    m.addIntArg(mousePos.y);
    mSender.sendMessage(m);
    
    
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
