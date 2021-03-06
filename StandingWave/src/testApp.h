#pragma once

#include "ofMain.h"

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
    
    //minumum distance
    float minimum_distance_Squared(ofVec2f v, ofVec2f w, ofVec2f p);
    
    ofVec2f a,b,c;
    float L; //Distance
    float A; //magnitude
    deque<ofVec2f> pointsOnString;
    int NumPoints;
    float decay;
    int n; // viblation mode
    float sigma;
    
    ofImage particleImage;
    bool soundPlay;
    
    void Parameter_Set(ofVec2f a, ofVec2f b);
    void Vibration_Calc(ofVec2f a, ofVec2f b, ofVec2f c);
    void Vibration_Draw(ofVec2f a, ofVec2f b, ofVec2f c);

    
        

};
