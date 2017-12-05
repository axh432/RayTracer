//
//  program.cpp
//  RayTracer
//
//  Created by Alex Handby on 05/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "program.h"


Program::Program(void):
//components
commandLineParser(new CommandLineParser),
sceneFileLoader(new FileLoader),
rayTracer(new RayTracer),
imageWriter(new PPMWriter),

//data
sceneFile(nullptr),
commandLineOptions(nullptr),
scene(nullptr),
image(nullptr)
{
//empty.
}

void Program::run(int argc, const char * argv[]){

  try{
        commandLineOptions = commandLineParser->parse(argc, argv); //ready for test
    
        sceneFile = sceneFileLoader->loadJSONFile(commandLineOptions->getSceneFilePath()); //ready for test
    
        scene = sceneBuilder->buildSceneFromJSON(*sceneFile); //ready for test
    
        image = rayTracer->render(*scene); //ready for test

        imageWriter->writeImage(commandLineOptions->getOutputFilePath(), *image); //ready for test
        
    }catch(RayTracerException e){
        std::cerr << e.getMessage() << std::endl;
    }

}
