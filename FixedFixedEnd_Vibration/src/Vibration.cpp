//
//  Vibration.cpp
//  FixedFixedEnd_Vibration
//
//  Created by Norihito Yuki on 12/6/13.
//
//

#include "Vibration.h"
//--------------------------------------------------------------
Vibration::Vibration(){

}

void Vibration::set(){
    A = 70;
    decay=1;
    n = 1;
    
    for (int i=0; i<NumPoints; i++){
        ofVec2f pos = ofVec2f((b-a).x/NumPoints*i,(b-a).y/NumPoints*i);
        pointsOnString.push_back(pos);
    }
    
    NumPoints=40;
    
    particleImage.loadImage("particle32.png");
    
    particleImage1.loadImage("particle32.png");

    
}

//--------------------------------------------------------------
void Vibration::update(){
    
    L=ofDist(a.x, a.y, b.x, b.y);  //Distance between point a and b
    
    ofPushMatrix();
    ofTranslate(a);  //transrate x,y-coordinate to point a
    decay *= 0.97;  //decay magnitude
    ofVec2f q=ofVec2f(1,0);  //normal vector
    float angle=q.angle(b-a);  //get angle of q and (b-a)
    ofRotateZ(angle);  //rotate x,y-coordinate(around z-axis)
    
    for (int i = 1; i < pointsOnString.size(); i++){
        pointsOnString[i].x = L/NumPoints*i;
        pointsOnString[i].y = A*sin(n*PI/L*i*L/NumPoints + sigma)*cos(TWO_PI*20/2/L*ofGetElapsedTimef()*250) * decay;  //A: magnitude, n: oscillation more, sigma: phase, when phase=0 standing wave
    }
    
    if (minimum_distance_Squared(a, b, c) < 5*5){  //squared of minimum distance
        if ((c-a).dot(c-a) < L*L/(3*3)) {  //when collision point is near to a
            n = 3;
            A = 30;
            decay = 1;
            sigma = PI/2;
        }
        if ((c-a).dot(c-a) > L*L/(3*3) && (c-a).dot(c-a) < L*L*4/9) { //when collision point is in the middle of a and b
            n = 1;
            A = 70;
            decay = 1;
            sigma = 0;
        }
        if( ((c-a).dot(c-a) >  L*L*4/9)){  //when collision point is near to b
            n = 3;
            A = 30;
            decay = 1;
            sigma = PI/2;
            
        }
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void Vibration::draw(){
    
    ofSetColor(10, 20, 80);
    ofCircle(a, 10);  //point a
    ofSetColor(255, 20, 80);
    ofCircle(b, 10);  //point b
    ofSetColor(10, 20, 80);
<<<<<<< HEAD

=======
    

    ofCircle(c, 20);
    
    //ofPushMatrix();
    //ofTranslate(ofPoint(100,100));
<<<<<<< HEAD

=======
=======
>>>>>>> ee5c89c35ee64a70281bdd72a1f1c4adabdaa33b
>>>>>>> f38a6499bea9d4a38dfcece424f6070f965514d0
    ofPushMatrix();
    ofTranslate(a);

    ofVec2f q=ofVec2f(1,0);
    float angle=q.angle(b-a);
    ofRotateZ(angle);
    
    for (int i = 0; i < pointsOnString.size(); i++){

                //ofLine(pointsOnString[i], pointsOnString[i+1]);
        pointsOnString[NumPoints] = ofVec2f(L, 0);
                //ofCircle(pointsOnString[i], 10);
                //ofCircle(pointsOnString[NumPoints], 2);
        particleImage.draw(pointsOnString[i].x -16, pointsOnString[i].y -16);
 

        pointsOnString[NumPoints] = ofVec2f(L, 0);
        particleImage.draw(pointsOnString[i].x -16, pointsOnString[i].y -16);
<<<<<<< HEAD
=======
        ofCircle(pointsOnString[i], 2);
<<<<<<< HEAD

=======
>>>>>>> c514125d12962b093fb6a1e05fb3573195c205c5
>>>>>>> ee5c89c35ee64a70281bdd72a1f1c4adabdaa33b
>>>>>>> f38a6499bea9d4a38dfcece424f6070f965514d0
    }
    
//    for(int i=0;i<10;i++){
//        int rx = ofRandom(0,ofGetWidth());
//        int ry = ofRandom(0,ofGetHeight());
//        particleImage.draw(rx,ry);
//    
//    }

    particleImage.draw(100 -16, 100 -16);
    
<<<<<<< HEAD
=======
    //ofPopMatrix();
    
//    for(int i=0;i<10;i++){
//        int rx = ofRandom(0,ofGetWidth());
//        int ry = ofRandom(0,ofGetHeight());
//        particleImage.draw(rx,ry);    }
    
>>>>>>> ee5c89c35ee64a70281bdd72a1f1c4adabdaa33b
}


//--------------------------------------------------------------
float Vibration::minimum_distance_Squared(ofVec2f v, ofVec2f w, ofVec2f p){
    
    
    // Return minimum distance between line segment vw and point p
    const float l2 = ofDistSquared(v.x, v.y, w.x, w.y);  // i.e. |w-v|^2 -  avoid a sqrt
    if (l2 == 0.0) return ofDist(p.x, p.y, v.x, v.y);   // v == w case
    // Consider the line extending the segment, parameterized as v + t (w - v).
    // We find projection of point p onto the line.
    // It falls where t = [(p-v) . (w-v)] / |w-v|^2
    const float t =(p - v).dot(w - v) / l2;
    
    if (t < 0.0) return ofDist(p.x, p.y, v.x, v.y);       // Beyond the 'v' end of the segment
    else if (t > 1.0) return ofDist(p.x, p.y, w.x, w.y);  // Beyond the 'w' end of the segment
    const ofVec2f projection = v + t * (w - v);  // Projection falls on the segment
    return ofDistSquared(p.x, p.y, projection.x, projection.y);
    
    
}
