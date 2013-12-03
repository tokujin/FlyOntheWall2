#ifndef _TEST_APP
#define _TEST_APP

#include "ofxOpenNI.h"
#include "ofMain.h"
#include "ofxOsc.h"


class testApp : public ofBaseApp{

public:
    
    ofImage image;
    
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

    void userEvent(ofxOpenNIUserEvent & event);
    ofxOpenNI openNIDevice;
    int numUsers;
    ofTrueTypeFont verdana;
        
    ofVec2f leftHand;
    
    ofxOscSender mSender;

};

#endif
