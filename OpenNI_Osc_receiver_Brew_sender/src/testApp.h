#pragma once

#include "ofMain.h"
#include "ofxOsc.h"


class testApp : public ofBaseApp{
    
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void checkOsc();
    ofxOscReceiver mReceiver;
    ofVec2f mousePos;
    ofVec2f ballPosL;
    ofVec2f ballPosR;
    
    ofVec2f torso;
    ofVec2f neck;
    ofVec2f head;
    
    ofVec2f leftShoulder;
    ofVec2f leftElbow;
    ofVec2f leftHand;
    ofVec2f rightShoulder;
    ofVec2f rightElbow;
    ofVec2f rightHand;
    
    ofVec2f leftHip;
    ofVec2f leftKnee;
    ofVec2f leftFoot;
    
    ofVec2f rightHip;
    ofVec2f rightKnee;
    ofVec2f rightFoot;
    
    //taichi related
    ofVec2f centerHand;
    deque<ofVec2f> pointsOnLine;

    bool hold;
    
};
