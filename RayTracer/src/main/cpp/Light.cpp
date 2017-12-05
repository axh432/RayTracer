//
//  Light.cpp
//  RayTracer
//
//  Created by Alex Handby on 10/09/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "Light.h"

void Light::setPosition(const Vec3f& newPosition){
    this->position = newPosition;
}

void Light::setEmissionColour(const Vec3f& newEmissionColour){
    this->emissionColour = newEmissionColour;
}

const Vec3f& Light::getPosition(){
    return this->position;
}

const Vec3f& Light::getEmissionColour(){
    return this->emissionColour;
}