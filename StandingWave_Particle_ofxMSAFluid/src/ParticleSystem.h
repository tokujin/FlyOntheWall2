//
//  ParticleSystem.h
//  test_fluid3
//
//  Created by Norihito Yuki on 10/8/13.
//
//

#pragma once

#include "ParticleS.h"

#define MAX_PARTICLES		50000

class ParticleSystem {
public:
	
    float posArray[MAX_PARTICLES * 2 * 2];
    float colArray[MAX_PARTICLES * 3 * 2];
    int curIndex;
	
    ParticleS particles[MAX_PARTICLES];
	
	ParticleSystem();
    
    void updateAndDraw(const msa::fluid::Solver &aSolver, ofVec2f windowSize, bool drawingFluid);
	void addParticles(const ofVec2f &pos, int count);
	void addParticle(const ofVec2f &pos);
};

