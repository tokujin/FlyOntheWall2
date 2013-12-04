#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	// listen on the given port
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup(PORT);
    // open an outgoing connection to HOST:PORT
	sender.setup(HOST, PORT);
    ofSetFrameRate(12);
    array_size = 200;
    ofSetLogLevel(OF_LOG_VERBOSE);

    openNIDevice.setup();
    openNIDevice.addImageGenerator();
    openNIDevice.addDepthGenerator();
    openNIDevice.setRegister(true);
    openNIDevice.setMirror(true);
    openNIDevice.addUserGenerator();
    openNIDevice.setMaxNumUsers(2);
    openNIDevice.start();
    
    re.loadSound("sounds/re.mp3");
    so.loadSound("sounds/so.mp3");
    la.loadSound("sounds/la.mp3");
    Do.loadSound("sounds/Do.mp3");
    Do2.loadSound("sounds/Do2.mp3");
    Mi.loadSound("sounds/Mi.mp3");
    
    bg.loadImage("pic/background.png");
    
    CX1=80;
    CY1=0;
    CX2=240;
    CY2=0;
    
    // set properties for all user masks and point clouds
    //openNIDevice.setUseMaskPixelsAllUsers(true); // if you just want pixels, use this set to true
    openNIDevice.setUseMaskTextureAllUsers(true); // this turns on mask pixels internally AND creates mask textures efficiently
    openNIDevice.setUsePointCloudsAllUsers(true);
    openNIDevice.setPointCloudDrawSizeAllUsers(2); // size of each 'point' in the point cloud
    openNIDevice.setPointCloudResolutionAllUsers(2); // resolution of the mesh created for the point cloud eg., this will use every second depth pixel
    
    // you can alternatively create a 'base' user class
//    ofxOpenNIUser user;
//    user.setUseMaskTexture(true);
//    user.setUsePointCloud(true);
//    user.setPointCloudDrawSize(2);
//    user.setPointCloudResolution(2);
//    openNIDevice.setBaseUserClass(user);
      
    verdana.loadFont(ofToDataPath("verdana.ttf"), 24);
}

//--------------------------------------------------------------
void testApp::update(){
    openNIDevice.update();
    CX1+=1;
    CY1+=2.5;
    if (CY1>400) {
        CY1=0;
        CX1=60;
    }
	while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);	
		if(m.getAddress() == "/nodes"){
	// OSC stuff
			//	m.setAddress("/nodes");
			m.addIntArg(head.x);
			m.addIntArg(head.y);
			m.addIntArg(leftHand.x);
			m.addIntArg(leftHand.y);
			m.addIntArg(rightHand.x);
			m.addIntArg(rightHand.y);
			m.addIntArg(leftFoot.x);
			m.addIntArg(leftFoot.y);
			m.addIntArg(rightFoot.x);
			m.addIntArg(rightFoot.y);
			sender.sendMessage(m);
			cout<<"head x: "<<head.x<<"head y: " <<head.y << endl;
		}
		else{
		cout<<"not /nodes"<<endl;
		cout << m.getAddress() << endl;
	}
	}   
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255, 255, 255);
    
    ofPushMatrix();
    // draw debug (ie., image, depth, skeleton)
    openNIDevice.drawDebug();
    ofPopMatrix();
    
    ofPushMatrix();
    // use a blend mode so we can see 'through' the mask(s)
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    // get number of current users
    int numUsers = openNIDevice.getNumTrackedUsers();
    
    // iterate through users
    for (int i = 0; i < numUsers; i++){
        
        // get a reference to this user
        ofxOpenNIUser & user = openNIDevice.getTrackedUser(i);
        
        // draw the mask texture for this user
        user.drawMask();
        
        // get joint position
        head = user.getJoint(JOINT_HEAD).getProjectivePosition();
        leftHand = user.getJoint(JOINT_LEFT_HAND).getProjectivePosition();
        rightHand = user.getJoint(JOINT_RIGHT_HAND).getProjectivePosition();
        leftFoot = user.getJoint(JOINT_LEFT_FOOT).getProjectivePosition();
        rightFoot = user.getJoint(JOINT_RIGHT_FOOT).getProjectivePosition();
        torso = user.getJoint(JOINT_TORSO).getProjectivePosition();
        
        

        
//        array_head.push_back(head);
//        array_leftFoot.push_back(leftFoot);
//        array_leftHand.push_back(leftHand);
//        array_rightFoot.push_back(rightFoot);
//        array_rightHand.push_back(rightHand);
//        array_torso.push_back(torso);
//        
//        if(array_head.size() > array_size) {
//            array_head.erase(array_head.begin());
//        }
//        
//        if(array_leftHand.size() > array_size) {
//            array_leftHand.erase(array_leftHand.begin());
//        }
//        
//        if(array_leftFoot.size() > array_size) {
//            array_leftFoot.erase(array_leftFoot.begin());
//        }
//        
//        if(array_rightFoot.size() > array_size) {
//            array_rightFoot.erase(array_rightFoot.begin());
//        }
//        
//        if(array_rightHand.size() > array_size) {
//            array_rightHand.erase(array_rightHand.begin());
//        }
//        if(array_torso.size() > array_size) {
//            array_torso.erase(array_torso.begin());
//        }
        // you can also access the pixel and texture references individually:
        
        // TEXTURE REFERENCE
        //ofTexture & tex = user.getMaskTextureReference();
        // do something with texture...
        
        // PIXEL REFERENCE
        //ofPixels & pix = user.getMaskPixels();
        // do something with the pixels...
        
        // and point clouds:
        
        ofPushMatrix();
        // move it a bit more central
        ofTranslate(320, 240, 10);
        user.drawPointCloud();
        
        // you can also access the mesh:
        
        // MESH REFERENCE
        //ofMesh & mesh = user.getPointCloud();
        // do something with the point cloud mesh
        
        ofPopMatrix();
        
    }
    
    ofDisableBlendMode();
    ofPopMatrix();
    
    // draw some info regarding frame counts etc
//	ofSetColor(0, 255, 0);
//	string msg = " MILLIS: " + ofToString(ofGetElapsedTimeMillis()) + " FPS: " + ofToString(ofGetFrameRate()) + " Device FPS: " + ofToString(openNIDevice.getFrameRate());
//    
//	verdana.drawString(msg, 20, openNIDevice.getNumDevices() * 480 - 20);
    
   //ofSetColor(leftHand.y,torso.x/10,rightHand.y*20);
    
    
   
//  draw the ploy circle(sh)
//    ofBeginShape();
//
//    for (int i = 0; i <6; i++){
//        
//            if (i == 0){
//            ofCurveVertex(leftFoot.x,leftFoot.y); // we need to duplicate 0 for the curve to start at point 0
//            ofCurveVertex(leftHand.x,leftHand.y); // we need to duplicate 0 for the curve to start at point 0
//        } else if (i == 5){
//            ofCurveVertex(head.x,head.y);
//            ofCurveVertex(torso.x, torso.y);	// to draw a curve from pt 6 to pt 0
//            ofCurveVertex(rightHand.x,rightHand.y);	// we duplicate the first point twice
//        }else {
//            ofCurveVertex(rightFoot.x,rightHand.y);
//        }
//
//    }
//
//   ofEndShape();
    
    
    //SH group adding parts~
    
    ofSetColor(leftHand.y,torso.x,rightHand.y*2);
    //ofSetColor(255, 255, 255);
    //ofRect(0, 0,1000, 1000);
    
    bg.draw(-200, 0);
    
    ofSetColor(255,255,255);
    ofSetLineWidth(3);
    ofLine(leftHand.x+10, leftHand.y+10, head.x+10, head.y+10);
    ofLine(head.x+20, head.y+10, rightHand.x+10, rightHand.y+15);
    ofLine(rightHand.x+8, rightHand.y+10, rightFoot.x+20, rightFoot.y+10);
    ofLine(rightFoot.x, rightFoot.y, leftFoot.x, leftFoot.y);
    ofLine(leftFoot.x,leftFoot.y, leftHand.x, leftHand.y);

    ofSetColor(255,255,255);
    ofCircle(leftHand.x+20, leftHand.y+20,10);
    ofCircle(rightHand.x+10, rightHand.y+10,6);
    
    
    
    ofSetColor(leftHand.y,torso.x/10,rightHand.y*20);
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	ofBeginShape();
    ofVertex(leftFoot.x,leftFoot.y);
    ofVertex(leftHand.x,leftHand.y);
    ofVertex(head.x,head.y);
    ofVertex(rightHand.x,rightHand.y);
    ofVertex(rightFoot.x,rightFoot.y);
	ofEndShape();
	
    
//    for(int i=0; i<array_head.size();i++) {
//        if(i > 1) {
//            ofLine(array_head[i-1].x, array_head[i-1].y, array_head[i].x, array_head[i].y);
//        }
//    }
//    for(int i=0; i<array_leftFoot.size();i++) {
//        if(i > 1) {
//            ofLine(array_leftFoot[i-1].x, array_leftFoot[i-1].y, array_leftFoot[i].x, array_leftFoot[i].y);
//        }
//    }
//    for(int i=0; i<array_rightFoot.size();i++) {
//        if(i > 1) {
//            ofLine(array_rightFoot[i-1].x, array_rightFoot[i-1].y, array_rightFoot[i].x, array_rightFoot[i].y);
//        }
//    }
//    for(int i=0; i<array_leftHand.size();i++) {
//        if(i > 1) {
//            ofLine(array_leftHand[i-1].x, array_leftHand[i-1].y, array_leftHand[i].x, array_leftHand[i].y);
//        }
//    }
//    for(int i=0; i<array_rightHand.size();i++) {
//        if(i > 1) {
//            ofLine(array_rightHand[i-1].x, array_rightHand[i-1].y, array_rightHand[i].x, array_rightHand[i].y);
//        }
//    }
//    for(int i=0; i<array_torso.size();i++) {
//        if(i > 1) {
//            ofLine(array_torso[i-1].x, array_torso[i-1].y, array_torso[i].x, array_torso[i].y);
//        }
//    }
////
//    for (int i=1;i<60 ; i+=10) {
//        CX=i+40;
//        CY=i;
//        ofCircle(CX, CY, 20);
//    }
//    CX=ofRandom(50,400);
//    CY=ofRandom(0,600);
    
   
//  ofCircle(40 ,80, 20);
    //ofSetColor(100);
    ofCircle(100, 100, 20);
    ofCircle(250, 100, 20);
    ofCircle(400, 100, 20);
    
    
    a=rightHand.y;
    
    b=head.y;
    c=leftHand.y;
    
    if (abs(a-b<10)) {
        
        
        la.play();
    }
    if (abs(c-b<10)) {
        so.play();
    }
    if (abs(leftHand.x-100)<10&&abs(leftHand.y-100)<10) {
        Do.play();
    }
    if (abs(leftHand.x-250)<10&&abs(leftHand.y-100)<10) {
        re.play();
    }
    if (abs(leftHand.x-400)<10&&abs(leftHand.y-100)<10) {
        Mi.play();
    }
    if (abs(rightHand.x-100)<10&&abs(rightHand.y-100)<10) {
        Do.play();
    }
    if (abs(rightHand.x-250)<10&&abs(rightHand.y-100)<10) {
        re.play();
    }
    if (abs(rightHand.x-400)<10&&abs(rightHand.y-100)<10) {
        Mi.play();
    }


}

//--------------------------------------------------------------
void testApp::userEvent(ofxOpenNIUserEvent & event){
    // show user event messages in the console
    ofLogNotice() << getUserStatusAsString(event.userStatus) << "for user" << event.id << "from device" << event.deviceID;
}

//--------------------------------------------------------------
void testApp::exit(){
    openNIDevice.stop();
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