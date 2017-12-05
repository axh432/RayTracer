//
//  CommandLineOptions.h
//  RayTracer
//
//  Created by Alex Handby on 05/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__CommandLineOptions__
#define __RayTracer__CommandLineOptions__

#include <stdio.h>
#include <string>

using std::string;

class CommandLineOptions{

private:
    string sceneFilePath;
    string outputFilePath;
    
public:
    CommandLineOptions();
    CommandLineOptions(string newSceneFilePath, string newOutputFilePath);
    
    void setSceneFilePath(string newSceneFilePath);
    void setOutputFilePath(string newOutputFilePath);
    
    const string& getSceneFilePath();
    const string& getOutputFilePath();

};

#endif /* defined(__RayTracer__CommandLineOptions__) */
