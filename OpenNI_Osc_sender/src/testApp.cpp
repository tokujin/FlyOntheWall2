#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
    
    //general settings
    ofBackground(0,0,0);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    //OpenNI related settings
    ofSetLogLevel(OF_LOG_VERBOSE);
    openNIDevice.setup();
    openNIDevice.addImageGenerator();
    openNIDevice.addDepthGenerator();
    openNIDevice.setRegister(true);
    openNIDevice.setMirror(true);
    openNIDevice.addUserGenerator();
    openNIDevice.setMaxNumUsers(2);
    openNIDevice.start();
    
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
    
    //Osc related
    mSender.setup("localhost", 12345);
    pos = ofGetWindowSize()/2;

    //display related
    verdana.loadFont(ofToDataPath("verdana.ttf"), 24);


}

//--------------------------------------------------------------
void testApp::update(){
    
    //Osc related
    ofxOscMessage m2;
    m2.setAddress("/ball/pos");
    m2.addIntArg(torso.x);
    m2.addIntArg(torso.y);
    m2.addIntArg(neck.x);
    m2.addIntArg(neck.y);
    m2.addIntArg(head.x);
    m2.addIntArg(head.y);
    m2.addIntArg(leftShoulder.x);
    m2.addIntArg(leftShoulder.y);
    m2.addIntArg(leftElbow.x);
    m2.addIntArg(leftElbow.y);
    m2.addIntArg(leftHand.x);
    m2.addIntArg(leftHand.y);
    m2.addIntArg(rightShoulder.x);
    m2.addIntArg(rightShoulder.y);
    m2.addIntArg(rightElbow.x);
    m2.addIntArg(rightElbow.y);
    m2.addIntArg(rightHand.x);
    m2.addIntArg(rightHand.y);
    m2.addIntArg(leftHip.x);
    m2.addIntArg(leftHip.y);
    m2.addIntArg(leftKnee.x);
    m2.addIntArg(leftKnee.y);
    m2.addIntArg(leftFoot.x);
    m2.addIntArg(leftFoot.y);
    m2.addIntArg(rightHip.x);
    m2.addIntArg(rightHip.y);
    m2.addIntArg(rightKnee.x);
    m2.addIntArg(rightKnee.y);
    m2.addIntArg(rightFoot.x);
    m2.addIntArg(rightFoot.y);

    
    mSender.sendMessage(m2);
    
    //OpenNI related
    openNIDevice.update();
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
	ofSetColor(255, 255, 255);
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
        //        user.drawMask();
        ofSetColor(0,0,0,20);
        ofRect(0,0,ofGetWidth(),ofGetHeight());
        ofSetColor(255,255,255,100);
        
        //nori edit
        // if you want x-coordinate leftHand.x
        ofPushMatrix();
        ofScale(1.6,1.6,1); //super hacky by michael.

        torso = user.getJoint(JOINT_TORSO).getProjectivePosition();
        neck = user.getJoint(JOINT_NECK).getProjectivePosition();
        head = user.getJoint(JOINT_HEAD).getProjectivePosition();
        
        leftShoulder = user.getJoint(JOINT_LEFT_SHOULDER).getProjectivePosition();
        leftElbow = user.getJoint(JOINT_LEFT_ELBOW).getProjectivePosition();
        leftHand = user.getJoint(JOINT_LEFT_HAND).getProjectivePosition();
        rightShoulder = user.getJoint(JOINT_RIGHT_SHOULDER).getProjectivePosition();
        rightElbow = user.getJoint(JOINT_RIGHT_ELBOW).getProjectivePosition();
        rightHand = user.getJoint(JOINT_RIGHT_HAND).getProjectivePosition();
        
        leftHip = user.getJoint(JOINT_LEFT_HIP).getProjectivePosition();
        leftKnee = user.getJoint(JOINT_LEFT_KNEE).getProjectivePosition();
        leftFoot = user.getJoint(JOINT_LEFT_FOOT).getProjectivePosition();
        
        rightHip = user.getJoint(JOINT_RIGHT_HIP).getProjectivePosition();
        rightKnee = user.getJoint(JOINT_RIGHT_KNEE).getProjectivePosition();
        rightFoot = user.getJoint(JOINT_RIGHT_FOOT).getProjectivePosition();
        
        centerHand = (leftHand + rightHand) /2;
        
        ofSetColor(0,150,255);
        ofCircle(leftHand.x, leftHand.y, 10);
        
        ofSetColor(255,0,150);
        ofCircle(rightHand.x, rightHand.y, 10);
        //        openNIDevice.drawSkeletons(0, 0, ofGetWidth(), ofGetHeight());
        openNIDevice.drawSkeletons();
        
//        squareDistance = ((rightHand - leftHand).x*(rightHand - leftHand).x + (rightHand - leftHand).y*(rightHand - leftHand).y);
//        
//        if (squareDistance < 100*100 && squareDistance > 40*40) {
//            ofSetColor(200, 100, 0);
//            ofCircle(centerHand, 20);
//        }
//        
//        for (int i=0; i<pointsOnLine.size()-1 ; i++) {
//            float sqdist = (centerHand - pointsOnLine[i]).x*(centerHand - pointsOnLine[i]).x+(centerHand - pointsOnLine[i]).y*(centerHand - pointsOnLine[i]).y;
//            if (sqdist < 10) {
//                //                pointsOnLine[i+1] = pointsOnLine[i];
//            }else{
//                ofSetColor(255);
//                for(int j=0; j<pointsOnLine.size()-1; j++){
//                    ofLine(pointsOnLine[j],pointsOnLine[j+1]);
//                }
//            }
//        }
        
        ofPopMatrix();
        
        // openNIDevice.drawImage(0, 0, ofGetWidth(), ofGetHeight());
        
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
    
    //	verdana.drawString(msg, 20, openNIDevice.getNumDevices() * 480 - 20);
}

//--------------------------------------------------------------
void testApp::userEvent(ofxOpenNIUserEvent & event){
    // show user event messages in the console
    //  ofLogNotice() << getUserStatusAsString(event.userStatus) << "for user" << event.id << "from device" << event.deviceID;
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