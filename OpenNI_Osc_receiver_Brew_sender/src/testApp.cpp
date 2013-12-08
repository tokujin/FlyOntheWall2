#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    ofEnableAlphaBlending();
    mReceiver.setup(12345);
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
}

//--------------------------------------------------------------
void testApp::draw(){

    ofPushMatrix();
    ofScale(1.6,1.6,1);
    
    //joints
    ofSetColor(200);
    ofCircle(torso, 10);
    ofCircle(neck, 10);
    ofCircle(head, 10);
    ofCircle(leftShoulder, 10);
    ofCircle(leftElbow, 10);
    ofCircle(leftHand, 10);
    ofCircle(rightShoulder, 10);
    ofCircle(rightElbow, 10);
    ofCircle(rightHand, 10);
    ofCircle(leftHip, 10);
    ofCircle(leftKnee, 10);
    ofCircle(leftFoot, 10);
    ofCircle(rightHip, 10);
    ofCircle(rightKnee, 10);
    ofCircle(rightFoot, 10);
    //left hand
    ofSetColor(0,150,255,200);
    ofCircle(leftHand.x, leftHand.y, 20);
    //right hand
    ofSetColor(255,0,150,200);
    ofCircle(rightHand.x, rightHand.y, 20);

    ofPopMatrix();
    

}

//--------------------------------------------------------------
void testApp::checkOsc(){
    while (mReceiver.hasWaitingMessages()) {
        ofxOscMessage m;
        mReceiver.getNextMessage(&m);
        string addr=m.getAddress();
        
        int xtorso=m.getArgAsInt32(0);
        int ytorso=m.getArgAsInt32(1);
        int xneck=m.getArgAsInt32(2);
        int yneck=m.getArgAsInt32(3);
        int xhead=m.getArgAsInt32(4);
        int yhead=m.getArgAsInt32(5);
        
        int xleftShoulder=m.getArgAsInt32(6);
        int yleftShoulder=m.getArgAsInt32(7);
        int xleftElbow=m.getArgAsInt32(8);
        int yleftElbow=m.getArgAsInt32(9);
        int xleftHand=m.getArgAsInt32(10);
        int yleftHand=m.getArgAsInt32(11);
        
        int xrightShoulder=m.getArgAsInt32(12);
        int yrightShoulder=m.getArgAsInt32(13);
        int xrightElbow=m.getArgAsInt32(14);
        int yrightElbow=m.getArgAsInt32(15);
        int xrightHand=m.getArgAsInt32(16);
        int yrightHand=m.getArgAsInt32(17);
        
        int xleftHip=m.getArgAsInt32(18);
        int yleftHip=m.getArgAsInt32(19);
        int xleftKnee=m.getArgAsInt32(20);
        int yleftKnee=m.getArgAsInt32(21);
        int xleftFoot=m.getArgAsInt32(22);
        int yleftFoot=m.getArgAsInt32(23);
        
        int xrightHip=m.getArgAsInt32(24);
        int yrightHip=m.getArgAsInt32(25);
        int xrightKnee=m.getArgAsInt32(26);
        int yrightKnee=m.getArgAsInt32(27);
        int xrightFoot=m.getArgAsInt32(28);
        int yrightFoot=m.getArgAsInt32(29);
        
        
        torso.set(xtorso,ytorso);
        neck.set(xneck,yneck);
        head.set(xhead,yhead);
        
        leftShoulder.set(xleftShoulder,yleftShoulder);
        leftElbow.set(xleftElbow,yleftElbow);
        leftHand.set(xleftHand, yleftHand);
        rightShoulder.set(xrightShoulder,yrightShoulder);
        rightElbow.set(xrightElbow,yrightElbow);
        rightHand.set(xrightHand, yrightHand);
        
        leftHip.set(xleftHip,yleftHip);
        leftKnee.set(xleftKnee,yleftKnee);
        leftFoot.set(xleftFoot,yleftFoot);
        rightHip.set(xrightHip,yrightHip);
        rightKnee.set(xrightKnee,yrightKnee);
        rightFoot.set(xrightFoot,yrightFoot);
        
        
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
