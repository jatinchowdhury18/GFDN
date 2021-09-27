/*
  ==============================================================================

    GFDN.h
    Created: 17 Sep 2021 12:31:02pm
    Author:  Orchisama Das

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "FDN.h"
#include "MixingMatrix.h"
#include <Eigen/Dense>


class GFDN{
public:
    GFDN();
    ~GFDN();
    
    void initialize(int nGrp, float SR, int* nDel, int *LR, int* UR, int numChannels);
    void updateMixingMatrix(float mixingFrac, int whichRoom);
    void updateCoupledMixingMatrix();
    void updateT60Filter(float t60low, float t60high, float fT, int whichRoom);
    void updateDryMix(float dry);
    void updateCouplingCoeff(float alpha);          //construct block mixing matrix
    void updateListenerRoom(int whichRoom);
    void updateSourceRoom(int whichRoom);
    float* processSample(float input[], int numChannels);   //takes in left and right channel data as input and returns stereo output
    
private:
    
    const float PI = std::acos(-1);
    int nGroups;
    int totalDelayLines;
    FDN* fdns;
    int* nDelayLines;
    float* mixingAngles;
    float couplingCoeff;
    float dryMix;
    float* b;                                   //driving coefficients
    float* c;                                   //output coefficients

    std::vector<float> output;
    
    Eigen::Matrix2f couplingMatrix;
    Eigen::MatrixXf M_coup;
    Eigen::VectorXf delayLineOutput;
    Eigen::VectorXf delayLineInput;
    
    

    
    
};
