//
//  FixedString.cpp
//  string_vibration
//
//  Created by Norihito Yuki on 12/7/13.
//
//

#include "testApp.h"

//--------------------------------------------------------------
void testApp::Parameter_Set(ofVec2f a, ofVec2f b){
    //two points
    NumPoints = 40; //Number of Points on the string
    
    //set points
    for (int i = 0; i < NumPoints; i++){
        ofVec2f pos = ofVec2f((b-a).x/NumPoints*i,(b-a).y/NumPoints*i);
        pointsOnString.push_back(pos);
    }
    
    //parameter settings
    A = 70;
    decay=1;
    n = 1;
}



//--------------------------------------------------------------
void testApp::Vibration_Calc(ofVec2f a, ofVec2f b, ofVec2f c){
    
    L = ofDist(a.x, a.y, b.x, b.y);  //Distance between point a and b
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
    
    if (minimum_distance_Squared(a, b, c) < 15*15){  //squared of minimum distance
        if ((c-a).dot(c-a) < L*L/(3*3)) {  //when collision point is near to a
            n=3;
            A = 70;
            decay = 1;
            sigma = PI/2;
        }
        if ((c-a).dot(c-a) > L*L/(3*3) && (c-a).dot(c-a) < L*L*4/9) { //when collision point is in the middle of a and b
            n=1;
            decay = 1;
            sigma = 0;
        }
        if( ((c-a).dot(c-a) >  L*L*4/9)){  //when collision point is near to b
            n=3;
            decay=1;
            sigma = PI/2;
            
        }
        soundPlay = true;  //play sound
    }else{
        soundPlay = false;
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::Vibration_Draw(ofVec2f a, ofVec2f b, ofVec2f c){
    
    ofSetColor(10, 20, 80);
    ofCircle(a, 10);
    ofSetColor(255, 20, 80);
    ofCircle(b, 10);
    ofSetColor(10, 20, 80);
    
    ofCircle(c, 20);
    
    ofPushMatrix();
    ofTranslate(a);
    ofVec2f q=ofVec2f(1,0);
    float angle=q.angle(b-a);
    ofRotateZ(angle);
    
    for (int i = 0; i < pointsOnString.size(); i++){
        pointsOnString[NumPoints] = ofVec2f(L, 0);
        particleImage.draw(pointsOnString[i].x -16, pointsOnString[i].y -16);
    }
    
    ofPopMatrix();
    
}


//--------------------------------------------------------------
float testApp::minimum_distance_Squared(ofVec2f v, ofVec2f w, ofVec2f p){
    
    
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

