#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(100);
    ofEnableBlendMode(OF_BLENDMODE_ADD);

    //load sound and image related
    collision = false;
    particleImage.loadImage("particle.png");

    //Standing Wave related
    /*these points are substituted by joints data
    So, if you want to connect leftHand1(user 1) and leftHand2(user 2)
    a = leftHand1, b = leftHand2*/
    a.set(ofGetWidth()/4, ofGetHeight()/4);
    b.set(ofGetWidth()*3/4, ofGetHeight()*3/4);

    //Particle related
    for (int i = 0; i < 100; i++){
		particle myParticle;
        float cirVal = ofRandom(TWO_PI);
		float vx = cos(cirVal) * ofRandom(0,4);
		float vy = sin(cirVal) * ofRandom(0,4);
        
		myParticle.setInitialCondition(300,300,vx, vy);
		// more interesting with diversity :)
		// uncomment this:
		myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
	}
    

}

//--------------------------------------------------------------
void testApp::update(){

    Parameter_Set(a,b); // set point a and b, subsequently generates Numpoints(=100) points between a and b
    
    //Standing Wave related
    c = ofVec2f(mouseX, mouseY);
    Vibration_Calc(a, b, c); // generate standing wave

    //particle related
    for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		particles[i].addForce(0,0.04);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}
    alp += 1;
    
    if(collision){
        ifCollision();
    }
    
    if (ofGetFrameRate() < 55) {
        pointsOnString.clear();
    }
    cout << ofGetFrameRate() << endl;
    cout << decay << endl;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    Vibration_Draw(a, b, c);

    if (collision == 1) {
        //sound play
        //now instead of playing sound
        ofSetColor(0, 0, 200, 100);
        ofCircle(mouseX, mouseY, 40);
    }
    
    for (int i = 0; i < particles.size(); i++){
//        ofSetColor(255, 0, 0, alp);
		particles[i].draw();
	}
    

}
//--------------------------------------------------------------
void testApp::ifCollision(){
    
        alp = 0;
        for (int i = 0; i < particles.size(); i++){
            float cirVal = ofRandom(TWO_PI);
            
            float vx = cos(cirVal) * ofRandom(0,4);
            float vy = sin(cirVal) * ofRandom(0,4);
            particles[i].setInitialCondition(mouseX,mouseY,vx, vy);
            
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
