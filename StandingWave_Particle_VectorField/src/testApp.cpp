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
    Parameter_Set(a,b);
    
    //Particle related
    for (int i = 0; i < 150; i++){
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
    
    // set program defaults
	drawFlowSolver = false;
	drawFlowSolverFullscreen = false;
	drawVectorField = false;
	drawParticles = true;
	particleColorBasedOnDirection = true;
	particleSaturation = 225.0;
	particleFade = true;
	minimumVelocity = 1.0;
    
    //Vector Field related
    // set up scaling factors for flow solver & vector field
	flowSolverScale.set(0.5, 0.5);
	vectorFieldScale.set(0.1, 0.1);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    //Standing Wave related
    c = ofVec2f(mouseX, mouseY);
    Vibration_Calc(a, b, c);

    //particle related
    for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		particles[i].addForce(0,0.04);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}
    
    //collision draw
    if(collision){
        ifCollision();
    }
    
    // update vector field from optical flow solver
	// there's some scaling going on between the sizes of the video, flow solver, and vector field
	ofPoint vel;
	int res = 1/vectorFieldScale.x;
	
//	for(int x=0; x<ofGetWidth(); x+=res) {
//		for(int y=0; y<ofGetHeight(); y+=res) {
//			vel = flowSolver.getVelAtNorm(x /ofGetWidth(), y / ofGetHeight());
//			
//			// skip if the values are too small
//			if(vel.length() < minimumVelocity) {
//				continue;
//            }
//			
//			// add vel value to the field
//			int pos = (y*vectorFieldScale.y) * field.fieldWidth + (x*vectorFieldScale.x);
//			field.field[pos] += vel;
//			
//		}
//	}
    
    
    
    
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
    
//    for (int i = 0; i < particles.size(); i++){
//        float hue, bri;
//        
//        // calculate the particle's color either based on its direction or
//        // based on its position on the screen
//        if (particleColorBasedOnDirection) {
//            hue = ofMap(atan2(particles[i].vel.y, particles[i].vel.x), -PI, PI, 0, 255);
//        } else {
//            hue = ofMap(particles[i].pos.x * particles[i].pos.y, 0, ofGetWidth() * ofGetHeight(), 0, 255);
//        }
//        // calculate the particle's brightness as either fully bright or fading based on
//        // its age. for fading, a percentage of its age vs. its lifespan is calculated and
//        // then squared so it stays brighter for longer, and then fades quicker instead of
//        // gradually across its entire life
//        if (particleFade) {
//            bri = (1 - powf(particles[i].age / (float) particles[i].lifespan, 2)) * 255;
//        } else {
//            bri = 255;
//        }
//        
//        ofSetColor(ofColor::fromHsb(hue, particleSaturation, bri));
//        particles[i].draw();
    
        
        
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
