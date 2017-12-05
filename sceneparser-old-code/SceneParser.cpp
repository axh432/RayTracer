//
//  SceneParser.cpp
//  RayTracer
//
//  Created by Alex Handby on 06/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "SceneParser.h"


vector<string> SceneParser::split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;
    
    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
    
    return internal;
}

SpherePtr SceneParser::parseSphere(string parameters){
    
    vector<string> tokens = split(parameters, ',');
    
    if(tokens.size() != 9){
        throw RayTracerException("Invalid Scene File Error: Sphere definition does not have the correct amount of parameters");
    }
    
    const Vec3f center(stof(tokens[0]), stof(tokens[1]), stof(tokens[2]));
    const float radius = stof(tokens[3]);
    const Vec3f surfaceColour(stof(tokens[4]), stof(tokens[5]), stof(tokens[6]));
    const float reflectivity = stof(tokens[7]);
    const float transparency = stof(tokens[8]);
    const Vec3f emissionColour(0);
    
    return SpherePtr(new Sphere(center,
                                radius,
                                surfaceColour,
                                reflectivity,
                                transparency,
                                emissionColour
                                )
                     );
}

LightPtr SceneParser::parseLight(string parameters){
    
    vector<string> tokens = split(parameters, ',');
    
    if(tokens.size() != 12){
        throw RayTracerException("Invalid Scene File Error: Light definition does not have the correct amount of parameters");
    }
    
    const Vec3f center(stof(tokens[0]), stof(tokens[1]), stof(tokens[2]));
    const float radius = stof(tokens[3]);
    const Vec3f surfaceColour(stof(tokens[4]), stof(tokens[5]), stof(tokens[6]));
    const float reflectivity = stof(tokens[7]);
    const float transparency = stof(tokens[8]);
    const Vec3f emissionColour(stof(tokens[9]), stof(tokens[10]), stof(tokens[11]));
    
    return LightPtr(new Light(center,
                              radius,
                              surfaceColour,
                              reflectivity,
                              transparency,
                              emissionColour
                              )
                    );

}

string SceneParser::getDefinitionParameters(size_t found, string tokenFound, string line){
    size_t start = found + tokenFound.length(); //where to start the substring.
    
    size_t end = line.find(SceneParser::DEFINITION_END_TOKEN); //length of the substring.
    
    if(end == string::npos){
        throw RayTracerException(SceneParser::BROKEN_DEFINITION_ERROR + line);
    }
    
    end -= start;
    
    return line.substr(start, end);
}


unique_ptr<Scene> SceneParser::parseSceneFromText(const vector<string>& textFile){

    unique_ptr<Scene> scene(new Scene());
    
    size_t found;
    
    for(int i = 0; i < textFile.size(); i++){
        
        const string& line = textFile[i];
        
        found = line.find(SceneParser::IMAGE_HEIGHT_TOKEN);
        if(found != string::npos){
            
            string parameters = getDefinitionParameters(found, SceneParser::IMAGE_HEIGHT_TOKEN, line);
            
            scene->setImageHeight(std::stoi(parameters));
            continue;
        }
        
        found = line.find(SceneParser::IMAGE_WIDTH_TOKEN);
        if(found != string::npos){
            
            string parameters = getDefinitionParameters(found, SceneParser::IMAGE_WIDTH_TOKEN, line);
            
            scene->setImageWidth(std::stoi(parameters));
            continue;
        }
        
        found = line.find(SceneParser::IMAGE_FOV_TOKEN);
        if(found != string::npos){

            string parameters = getDefinitionParameters(found, SceneParser::IMAGE_FOV_TOKEN, line);
            
            scene->setImageFov(std::stoi(parameters));
            continue;
        }
        
        found = line.find(SceneParser::LIGHT_TOKEN);
        if(found != string::npos){
            
            string parameters = getDefinitionParameters(found, SceneParser::LIGHT_TOKEN, line);
            
            scene->getLights().push_back(std::move(parseLight(parameters)));
            continue;
        }
        
        found = line.find(SceneParser::SPHERE_TOKEN);
        if(found != string::npos){

            string parameters = getDefinitionParameters(found, SceneParser::SPHERE_TOKEN, line);
            
            scene->getSpheres().push_back(std::move(parseSphere(parameters)));
            continue;
        }
        
        throw RayTracerException(SceneParser::UNKNOWN_DEFINITON_ERROR + line);
        
    }
    
    //check the scene definition:
    if(scene->getImageHeight() == 0){
        throw RayTracerException("Invalid Scene File Error: An image height has not been specified in the scene file");
    }
    
    if(scene->getImageWidth() == 0){
        throw RayTracerException("Invalid Scene File Error: An image width has not been specified in the scene file");
    }
    
    if(scene->getImageFov() == 0){
        throw RayTracerException("Invalid Scene File Error: An image FOV has not been specified in the scene file");
    }
    
    if(scene->getSpheres().size() == 0){
        throw RayTracerException("Invalid Scene File Error: No spheres have not been specified in the scene file");
    }
    
    if(scene->getLights().size() == 0){
        throw RayTracerException("Invalid Scene File Error: No lights have not been specified in the scene file");
    }
    
    return scene;
    
}