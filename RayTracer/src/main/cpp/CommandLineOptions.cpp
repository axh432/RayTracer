//
//  CommandLineOptions.cpp
//  RayTracer
//
//  Created by Alex Handby on 05/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "CommandLineOptions.h"


CommandLineOptions::CommandLineOptions(){}

CommandLineOptions::CommandLineOptions(string newSceneFilePath, string newOutputFilePath):
sceneFilePath(std::move(newSceneFilePath)), outputFilePath(std::move(newOutputFilePath)){}

void CommandLineOptions::setSceneFilePath(string newSceneFilePath){
    
    sceneFilePath.assign(newSceneFilePath);
    
}

void CommandLineOptions::setOutputFilePath(string newOutputFilePath){

    outputFilePath.assign(newOutputFilePath);
    
}

const string& CommandLineOptions::getSceneFilePath(){
    return sceneFilePath;
}

const string& CommandLineOptions::getOutputFilePath(){
    return outputFilePath;
}
