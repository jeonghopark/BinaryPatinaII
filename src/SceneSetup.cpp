//
//  SceneSetup.cpp
//  BinaryPatinaII
//
//  Created by jeonghopark on 18/10/15.
//
//

#include "SceneSetup.hpp"

void SceneSetup::inputBaseArch(BaseArch & _baseArch){
    
    baseArch = & _baseArch;

}


void SceneSetup::inputFFTP(ProcessFFT & _processFFT){
    
    processFFT = & _processFFT;

}