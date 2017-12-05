//
//  scene.cpp
//  RayTracer
//
//  Created by Alex Handby on 06/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "scene.h"

vector<SpherePtr>& Scene::getSpheres(){
    return spheres;
}

vector<LightPtr>& Scene::getLights(){
    return lights;
}

unsigned Scene::getImageWidth(){
    return imageWidth;
}

unsigned Scene::getImageHeight(){
    return imageHeight;
}

unsigned Scene::getImageFov(){
    return imageFov;
}

void Scene::setImageHeight(unsigned newImageHeight){
    imageHeight = newImageHeight;
}

void Scene::setImageWidth(unsigned newImageWidth){
    imageWidth = newImageWidth;
}

void Scene::setImageFov(unsigned newImageFov){
    imageFov = newImageFov;
}

void Scene::setSpheres(vector<SpherePtr>& newSpheres){
    spheres = std::move(newSpheres);
}

void Scene::setLights(vector<LightPtr>& newLights){
    lights = std::move(newLights);
}