//
//  Particle.h
//  test_fluid3
//
//  Created by Norihito Yuki on 10/8/13.
//
//

#pragma once

#include "MSACore.h"
#include "MSAFluidSolver.h"

class ParticleS {
public:
    ofVec2f	pos, vel;
    float	radius;
    float	alpha;
    float	mass;
	
    void init(float x, float y);
    void update( const msa::fluid::Solver &solver, const ofVec2f &windowSize, const ofVec2f &invWindowSize );
	void updateVertexArrays( bool drawingFluid, const ofVec2f &invWindowSize, int i, float* posBuffer, float* colBuffer);
};

