//
//  SceneParser.h
//  RayTracer
//
//  Created by Alex Handby on 06/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__SceneParser__
#define __RayTracer__SceneParser__

#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

#include "scene.h"
#include "Sphere.h"
#include "Vec3.h" 
#include "RayTracerException.h"

using std::vector;
using std::string;
using std::stringstream;
using std::unique_ptr;

class SceneParser {

private:
    vector<string> split(string str, char delimiter);
    string getDefinitionParameters(size_t found, string tokenFound, string line);
    SpherePtr parseSphere(string values);
    LightPtr  parseLight(string values);
    
    
    static const string IMAGE_HEIGHT_TOKEN = "ImageHeight(";
    static const string IMAGE_WIDTH_TOKEN = "ImageWidth(";
    static const string IMAGE_FOV_TOKEN = "ImageFov(";
    static const string LIGHT_TOKEN = "Light(";
    static const string SPHERE_TOKEN = "Sphere(";
    static const string DEFINITION_END_TOKEN = ");";
    static const string UNKNOWN_DEFINITON_ERROR = "Invalid Scene File Error: Unknown definition - ";
    static const string BROKEN_DEFINITION_ERROR = "Invalid Scene File Error: Broken defintion - ";
    
public:
    unique_ptr<Scene> parseSceneFromText(const vector<string>& textFile);

};

#endif /* defined(__RayTracer__SceneParser__) */
