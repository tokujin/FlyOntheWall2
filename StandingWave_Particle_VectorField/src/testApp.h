#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "vectorField.h"


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
    
    //load image and sound
    ofImage particleImage;
    
    //Standing Wave related
    ofVec2f a,b,c;
    float L; //Distance
    float A; //magnitude
    deque<ofVec2f> pointsOnString;
    int NumPoints;
    float decay;
    int n; // viblation mode
    float sigma;
    void Parameter_Set(ofVec2f a, ofVec2f b);
    void Vibration_Calc(ofVec2f a, ofVec2f b, ofVec2f c);
    void Vibration_Draw(ofVec2f a, ofVec2f b, ofVec2f c);
    float minimum_distance_Squared(ofVec2f v, ofVec2f w, ofVec2f p);

    //Collision
    bool collision;
    void ifCollision();


    
    int alp;
    float rad;

    // particle & vector field-related
	void addParticle(float x, float y, float vx, float vy);
	vector <particle> particles;
	vectorField field;
	ofVec2f vectorFieldScale;
    
    // optical flow solver & scale
//    ofxOpticalFlowLK flowSolver;
	ofVec2f flowSolverScale;
    
    // program related
	bool drawFlowSolver;
	bool drawFlowSolverFullscreen;
	bool drawVectorField;
	bool drawParticles;
	bool particleColorBasedOnDirection;
	bool particleFade;
	float particleSaturation;
	float minimumVelocity;


};
