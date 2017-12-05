//
//  program.h
//  RayTracer
//
//  Created by Alex Handby on 05/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__program__
#define __RayTracer__program__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>
#include "CommandLineParser.h"
#include "CommandLineOptions.h"
#include "FileLoader.h"
#include "raytracer.h"
#include "SceneBuilder.h"
#include "scene.h"
#include "RayTracerException.h"
#include "PPMWriter.h"
#include "image.h"

using std::string;
using std::vector;
using std::unique_ptr;

class Program {

private:
    //components
    unique_ptr<CommandLineParser>          commandLineParser;
    unique_ptr<FileLoader>                 sceneFileLoader;
    unique_ptr<SceneBuilder>               sceneBuilder;
    unique_ptr<RayTracer>                  rayTracer;
    unique_ptr<ImageWriter>                imageWriter;
    
    //data
    unique_ptr<CommandLineOptions>          commandLineOptions;
    unique_ptr<Document>                    sceneFile;
    unique_ptr<Scene>                       scene;
    unique_ptr<Image>                       image;
    
public:
    Program();
    void run(int argc, const char * argv[]);
    
};

#endif /* defined(__RayTracer__program__) */
