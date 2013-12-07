//
//  Vibration.h
//  FixedFixedEnd_Vibration
//
//  Created by Norihito Yuki on 12/6/13.
//
//

#pragma once

#include "ofMain.h"

class Vibration{
    public:
        Vibration();
        void set();
        void update();
        void draw();
    
        ofVec2f a,b,c;
        float L; //Distance
        float A; //magnitude
        deque<ofVec2f> pointsOnString;
        int NumPoints;
        float decay;
        int n; // viblation mode
    
    
        //minumum distance
        float minimum_distance_Squared(ofVec2f v, ofVec2f w, ofVec2f p);

    
        ofImage particleImage,particleImage1;
};