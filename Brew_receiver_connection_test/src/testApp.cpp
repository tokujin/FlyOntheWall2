#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    ofEnableAlphaBlending();
    mReceiver.setup(12345);
    
    //--------------yuanjin edit---------------
    // init spacebrew
    string host = Spacebrew::SPACEBREW_CLOUD; // "localhost";
    string name = "of-noise-example";
    string description = "Super complex joints sender";
    Spacebrew::addListener(this, spacebrew);

    //------------send signal-----------
    spacebrew.addPublish("torsoX", "range");
    spacebrew.addPublish("torsoY", "range");
    spacebrew.addPublish("neckX", "range");
    spacebrew.addPublish("neckY", "range");
    spacebrew.addPublish("headX", "range");
    spacebrew.addPublish("headY", "range");
    
    spacebrew.addPublish("leftShoulderX", "range");
    spacebrew.addPublish("leftShoulderY", "range");
    spacebrew.addPublish("leftElbowX", "range");
    spacebrew.addPublish("leftElbowY", "range");
    spacebrew.addPublish("leftHandX", "range");
    spacebrew.addPublish("leftHandY", "range");
    
    spacebrew.addPublish("rightShoulderX", "range");
    spacebrew.addPublish("rightShoulderY", "range");
    spacebrew.addPublish("rightElbowX", "range");
    spacebrew.addPublish("rightElbowY", "range");
    spacebrew.addPublish("rightHandX", "range");
    spacebrew.addPublish("rightHandY", "range");
    
    spacebrew.addPublish("leftHipX", "range");
    spacebrew.addPublish("leftHipY", "range");
    spacebrew.addPublish("leftKneeX", "range");
    spacebrew.addPublish("leftKneeY", "range");
    spacebrew.addPublish("leftFootX", "range");
    spacebrew.addPublish("leftFootY", "range");
    
    spacebrew.addPublish("rightHipX", "range");
    spacebrew.addPublish("rightHipY", "range");
    spacebrew.addPublish("rightKneeX", "range");
    spacebrew.addPublish("rightKneeY", "range");
    spacebrew.addPublish("rightFootX", "range");
    spacebrew.addPublish("rightFootY", "range");
    
    //------------receive---------------------
    
    spacebrew.addSubscribe("torsoX", "range");
    spacebrew.addSubscribe("torsoY", "range");
    spacebrew.addSubscribe("neckX", "range");
    spacebrew.addSubscribe("neckY", "range");
    spacebrew.addSubscribe("headX", "range");
    spacebrew.addSubscribe("headY", "range");
    
    spacebrew.addSubscribe("leftShoulderX", "range");
    spacebrew.addSubscribe("leftShoulderY", "range");
    spacebrew.addSubscribe("leftElbowX", "range");
    spacebrew.addSubscribe("leftElbowY", "range");
    spacebrew.addSubscribe("leftHandX", "range");
    spacebrew.addSubscribe("leftHandY", "range");
    
    spacebrew.addSubscribe("rightShoulderX", "range");
    spacebrew.addSubscribe("rightShoulderY", "range");
    spacebrew.addSubscribe("rightElbowX", "range");
    spacebrew.addSubscribe("rightElbowY", "range");
    spacebrew.addSubscribe("rightHandX", "range");
    spacebrew.addSubscribe("rightHandY", "range");
    
    spacebrew.addSubscribe("leftHipX", "range");
    spacebrew.addSubscribe("leftHipY", "range");
    spacebrew.addSubscribe("leftKneeX", "range");
    spacebrew.addSubscribe("leftKneeY", "range");
    spacebrew.addSubscribe("leftFootX", "range");
    spacebrew.addSubscribe("leftFootY", "range");
    
    spacebrew.addSubscribe("rightHipX", "range");
    spacebrew.addSubscribe("rightHipY", "range");
    spacebrew.addSubscribe("rightKneeX", "range");
    spacebrew.addSubscribe("rightKneeY", "range");
    spacebrew.addSubscribe("rightFootX", "range");
    spacebrew.addSubscribe("rightFootY", "range");
    
    torsoX=0;
    torsoY=0;
    neckX=0;
    neckY=0;
    headX=0;
    headY=0;
    
    leftShoulderX=0;
    leftShoulderY=0;
    leftElbowX=0;
    leftElbowY=0;
    leftHandX=0;
    leftHandY=0;
    
    rightShoulderX=0;
    rightShoulderY=0;
    rightElbowX=0;
    rightElbowY=0;
    rightHandX=0;
    rightHandY=0;
    
    leftHipX=0;
    leftHipY=0;
    leftKneeX=0;
    leftKneeY=0;
    leftFootX=0;
    leftFootY=0;
    
    rightHipX=0;
    rightHipY=0;
    rightKneeX=0;
    rightKneeY=0;
    rightFootX=0;
    rightFootY=0;
    
    
    spacebrew.connect( host, name, description );
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
    
    //--------------yuanjin edit---------------
    // update spacebrew
    if ( spacebrew.isConnected() ){
        //        float noiseFast = ofNoise(ofGetElapsedTimeMillis() * .1) * 1024.0f;
        //        float noiseSlow = ofNoise(ofGetElapsedTimef() * .1) * 1024.0f;
        //        spacebrew.sendRange("noiseFast", (noiseFast) );
        //        spacebrew.sendRange("noiseSlow", (noiseSlow) );
        
        //yuanjin--------------
        spacebrew.sendRange("torsoX", (torso.x) );
        spacebrew.sendRange("torsoY", (torso.y) );
        spacebrew.sendRange("neckX", (neck.x) );
        spacebrew.sendRange("neckY", (neck.y) );
        spacebrew.sendRange("headX", (head.x) );
        spacebrew.sendRange("headY", (head.y) );
        
        spacebrew.sendRange("leftShoulderX", (leftShoulder.x) );
        spacebrew.sendRange("leftShoulderY", (leftShoulder.y) );
        spacebrew.sendRange("leftElbowX", (leftElbow.x) );
        spacebrew.sendRange("leftElbowY", (leftElbow.y) );
        spacebrew.sendRange("leftHandX", (leftHand.x) );
        spacebrew.sendRange("leftHandY", (leftHand.y) );
        
        spacebrew.sendRange("rightShoulderX", (rightShoulder.x) );
        spacebrew.sendRange("rightShoulderY", (rightShoulder.y) );
        spacebrew.sendRange("rightElbowX", (rightElbow.x) );
        spacebrew.sendRange("rightElbowY", (rightElbow.y) );
        spacebrew.sendRange("rightHandX", (rightHand.x) );
        spacebrew.sendRange("rightHandY", (rightHand.y) );
        
        spacebrew.sendRange("leftHipX", (leftHip.x) );
        spacebrew.sendRange("leftHipY", (leftHip.y) );
        spacebrew.sendRange("leftKneeX", (leftKnee.x) );
        spacebrew.sendRange("leftKneeY", (leftKnee.y) );
        spacebrew.sendRange("leftFootX", (leftFoot.x) );
        spacebrew.sendRange("leftFootY", (leftFoot.y) );
        
        spacebrew.sendRange("rightHipX", (rightHip.x) );
        spacebrew.sendRange("rightHipY", (rightHip.y) );
        spacebrew.sendRange("rightKneeX", (rightKnee.x) );
        spacebrew.sendRange("rightKneeY", (rightKnee.y) );
        spacebrew.sendRange("rightFootX", (rightFoot.x) );
        spacebrew.sendRange("rightFootY", (rightFoot.y) );
    }

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
    
    //--------------yuanjin edit---------------
    //---------------------second skeleton-------------------------
    ofCircle(torsoX, torsoY, 10);
    ofCircle(neckX, neckY, 10);
    ofCircle(headX, headY, 10);
    ofCircle(leftShoulderX, leftShoulderY, 10);
    ofCircle(leftElbowX, leftElbowY, 10);
    ofCircle(leftHandX, leftHandY, 10);
    ofCircle(rightShoulderX, rightShoulderY, 10);
    ofCircle(rightElbowX, rightElbowY, 10);
    ofCircle(rightHandX, rightHandY, 10);
    ofCircle(leftHipX, leftHipY, 10);
    ofCircle(leftKneeX, leftKneeY, 10);
    ofCircle(leftFootX, leftFootY, 10);
    ofCircle(rightHipX, rightHipY, 10);
    ofCircle(rightKneeX, rightKneeY, 10);
    ofCircle(rightFootX, rightFootY, 10);


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
void testApp::onMessage( Spacebrew::Message & m ){
    //----------------------------
    if (m.name=="torsoX") {
        torsoX=m.valueRange();
    }
    if (m.name=="torsoY") {
        torsoY=m.valueRange();
    }
    if (m.name=="neckX") {
        neckX=m.valueRange();
    }
    if (m.name=="neckY") {
        neckY=m.valueRange();
    }
    if (m.name=="headX") {
        headX=m.valueRange();
    }
    if (m.name=="headY") {
        headY=m.valueRange();
    }
    
    
    //----------------------------
    if (m.name=="leftShoulderX") {
        leftShoulderX=m.valueRange();
    }
    if (m.name=="leftShoulderY") {
        leftShoulderY=m.valueRange();
    }
    if (m.name=="leftElbowX") {
        leftElbowX=m.valueRange();
    }
    if (m.name=="leftElbowY") {
        leftElbowY=m.valueRange();
    }
    if (m.name=="leftHandX") {
        leftHandX=m.valueRange();
    }
    if (m.name=="leftHandY") {
        leftHandY=m.valueRange();
    }
    
    
    //----------------------------
    if (m.name=="rightShoulderX") {
        rightShoulderX=m.valueRange();
    }
    if (m.name=="rightShoulderY") {
        rightShoulderY=m.valueRange();
    }
    if (m.name=="rightElbowX") {
        rightElbowX=m.valueRange();
    }
    if (m.name=="rightElbowY") {
        rightElbowY=m.valueRange();
    }
    if (m.name=="rightHandX") {
        rightHandX=m.valueRange();
    }
    if (m.name=="rightHandY") {
        rightHandY=m.valueRange();
    }
    
    
    //----------------------------
    if (m.name=="leftHipX") {
        leftHipX=m.valueRange();
    }
    if (m.name=="leftHipY") {
        leftHipY=m.valueRange();
    }
    if (m.name=="leftKneeX") {
        leftKneeX=m.valueRange();
    }
    if (m.name=="leftKneeY") {
        leftKneeY=m.valueRange();
    }
    if (m.name=="leftFootX") {
        leftFootX=m.valueRange();
    }
    if (m.name=="leftFootY") {
        leftFootY=m.valueRange();
    }
    
    
    //----------------------------
    if (m.name=="rightHipX") {
        rightHipX=m.valueRange();
    }
    if (m.name=="rightHipY") {
        rightHipY=m.valueRange();
    }
    if (m.name=="rightKneeX") {
        rightKneeX=m.valueRange();
    }
    if (m.name=="rightKneeY") {
        rightKneeY=m.valueRange();
    }
    if (m.name=="rightFootX") {
        rightFootX=m.valueRange();
    }
    if (m.name=="rightFootY") {
        rightFootY=m.valueRange();
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
