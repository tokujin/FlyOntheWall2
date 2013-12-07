#ifndef _TEST_APP
#define _TEST_APP

#include "ofxOpenNI.h"
#include "ofMain.h"
#include "ofxOsc.h"


class testApp : public ofBaseApp{
    
public:
    
	void setup();
	void update();
	void draw();
    void exit();
    
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
    
    //OpenNI related
    void userEvent(ofxOpenNIUserEvent & event);
	ofxOpenNI openNIDevice;
    
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
    
    ofVec2f centerHand;
    
    float squareDistance;
    deque<ofVec2f> pointsOnLine;
    
    //Osc related
    ofxOscSender mSender;
    ofVec2f mousePos;
    ofVec2f pos,vel;

    //others
    ofTrueTypeFont verdana;
        
};

#endif