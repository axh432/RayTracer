//
//  SceneBuilder.cpp
//  RayTracer
//
//  Created by Alex Handby on 09/09/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "SceneBuilder.h"

void SceneBuilder::populateImageSettings(Scene& scene, const Value& imageSettings){

    if(imageSettings.HasMember("ImageHeight")){
        
        scene.setImageHeight(imageSettings["ImageHeight"].GetUint());
    
    }else{
        throw RayTracerException("SceneBuilder Error: ImageHeight has not been specified in the image settings of the scene JSON");
    }
    
    if(imageSettings.HasMember("ImageWidth")){
        
        scene.setImageWidth(imageSettings["ImageWidth"].GetUint());
        
    }else{
        throw RayTracerException("SceneBuilder Error: ImageWidth has not been specified in the image settings of the scene JSON");
    }
    
    if(imageSettings.HasMember("ImageFov")){
        
        scene.setImageFov(imageSettings["ImageFov"].GetUint());
        
    }else{
        throw RayTracerException("SceneBuilder Error: ImageFov has not been specified in the image settings of the scene JSON");
    }
    
}

SpherePtr SceneBuilder::buildSphere(const Value& sphere){
    
    SpherePtr spherePtr(new Sphere());
    
    if(!sphere.HasMember("position")){
        throw RayTracerException("SceneBuilder Error: A sphere defintion is missing a 'position' attribute in the scene JSON");
    }
    
    if(!sphere.HasMember("radius")){
        throw RayTracerException("SceneBuilder Error: A sphere definition is missing a 'size' attribute in the scene JSON");
    }
    
    if(!sphere.HasMember("surfaceColour")){
        throw RayTracerException("SceneBuilder Error: A sphere definition is missing a 'surfaceColour' attribute in the scene JSON");
    }
    
    
    const Value& position = sphere["position"];
    
    if(!position.IsArray()){
        throw RayTracerException("SceneBuilder Error: The scene JSON - a sphere's position values are not contained in an array");
    }
    
    if(position.Size() != 3){
        throw RayTracerException("SceneBuilder Error: The scene JSON - a sphere's position does not have the correct amount of values");
    }
    
    Vec3f vecPosition;
    
    vecPosition.setX(position[0].GetFloat());
    vecPosition.setY(position[1].GetFloat());
    vecPosition.setZ(position[2].GetFloat());
    
    spherePtr->setPosition(vecPosition);
    
    
    const Value& surfaceColour = sphere["surfaceColour"];
    
    if(!surfaceColour.IsArray()){
        throw RayTracerException("SceneBuilder Error: The scene JSON - a sphere's surfaceColour values are not contained in an array");
    }
    
    if(surfaceColour.Size() != 3){
        throw RayTracerException("SceneBuilder Error: The scene JSON - a sphere's surfaceColour does not have the correct amount of values");
    }
    
    Vec3f vecSurfaceColour;
    
    vecSurfaceColour.setX(surfaceColour[0].GetFloat());
    vecSurfaceColour.setY(surfaceColour[1].GetFloat());
    vecSurfaceColour.setZ(surfaceColour[2].GetFloat());
    
    spherePtr->setSurfaceColour(vecSurfaceColour);
    
    
    const Value& radius = sphere["radius"];
    
    spherePtr->setRadius(radius.GetUint());
    
    return spherePtr;
    
}

LightPtr SceneBuilder::buildLight(const Value& light){
    
    LightPtr lightPtr(new Light());
    
    if(!light.HasMember("position")){
        throw RayTracerException("SceneBuilder Error: A light defintion is missing a 'position' attribute in the scene JSON");
    }
    
    if(!light.HasMember("colour")){
        throw RayTracerException("SceneBuilder Error: A light definition is missing a 'colour' attribute in the scene JSON");
    }
    
    
    const Value& position = light["position"];
    
    if(!position.IsArray()){
        throw RayTracerException("SceneBuilder Error: The scene JSON - a light's position values are not contained in an array");
    }
    
    if(position.Size() != 3){
        throw RayTracerException("SceneBuilder Error: The scene JSON - a light's position does not have the correct amount of values");
    }
    
    Vec3f vecPosition;
    
    vecPosition.setX(position[0].GetFloat());
    vecPosition.setY(position[1].GetFloat());
    vecPosition.setZ(position[2].GetFloat());
    
    lightPtr->setPosition(vecPosition);
    
    
    const Value& colour = light["colour"];
    
    if(!colour.IsArray()){
        throw RayTracerException("SceneBuilder Error: The scene JSON - a light's colour values are not contained in an array");
    }
    
    if(colour.Size() != 3){
        throw RayTracerException("SceneBuilder Error: The scene JSON - a light's colour does not have the correct amount of values");
    }
    
    Vec3f vecColour;
    
    vecColour.setX(colour[0].GetFloat());
    vecColour.setY(colour[1].GetFloat());
    vecColour.setZ(colour[2].GetFloat());
    
    lightPtr->setEmissionColour(vecColour);
    
    return lightPtr;
    
}

void SceneBuilder::populateSpheres(Scene& scene, const Value& spheres){
    
    if(spheres.Size() == 0){
        throw RayTracerException("SceneBuilder Error: The scene JSON contains no spheres");
    }
    
    for (SizeType i = 0; i < spheres.Size(); i++){
    
        const Value& sphere = spheres[i];
        
        SpherePtr spherePtr = buildSphere(sphere);
        
        scene.getSpheres().push_back(spherePtr);
    
    }

}

void SceneBuilder::populateLights(Scene& scene, const Value& lights){

    if(lights.Size() == 0){
        throw RayTracerException("SceneBuilder Error: The scene JSON contains no lights");
    }
    
    for (SizeType i = 0; i < lights.Size(); i++){
        
        const Value& light = lights[i];
        
        LightPtr lightPtr = buildLight(light);
        
        scene.getLights().push_back(lightPtr);
        
    }
    
}


unique_ptr<Scene> SceneBuilder::buildSceneFromJSON(Document& document){
    
    unique_ptr<Scene> scene(new Scene);

    //Check the contents.
    if(!document.IsObject()){
        throw RayTracerException("SceneBuilder Error: The root of the scene JSON is not a JSON Object");
    }
    
    if(!document.HasMember("image")){
        throw RayTracerException("SceneBuilder Error: The scene JSON contains no image settings");
    }
    
    if(!document.HasMember("spheres")){
        throw RayTracerException("SceneBuilder Error: The scene JSON contains no spheres");
    }
    
    if(!document.HasMember("lights")){
        throw RayTracerException("SceneBuilder Error: The scene JSON contains no lights");
    }
    
    
    //Get the image settings.
    const Value& imageSettings = document["image"];
    
    if(!imageSettings.IsObject()){
        throw RayTracerException("SceneBuilder Error: The scene JSON image settings is not contained in an object");
    }
    
    populateImageSettings(*scene, imageSettings);
    
    
    //Get spheres.
    const Value& spheres = document["spheres"];
    
    if(!spheres.IsArray()){
        throw RayTracerException("SceneBuilder Error: The scene JSON spheres are not contained in an array");
    }
    
    populateSpheres(*scene, spheres);
    
    
    //Get lights.
    const Value& lights = document["lights"];
    
    if(!lights.IsArray()){
        throw RayTracerException("SceneBuilder Error: The scene JSON lights are not contained in an array");
    }
    
    populateLights(*scene, spheres);
    
    return scene;

}