//
//  Sphere.cpp
//  RayTracer
//
//  Created by Alex Handby on 10/09/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "Sphere.h"


void Sphere::setPosition(const Vec3f& newPosition){
    this->position = newPosition;
}

void Sphere::setSurfaceColour(const Vec3f& newSurfaceColour){
    this->surfaceColour = newSurfaceColour;
}

void Sphere::setRadius(const float newRadius){
    this->radius = newRadius;
    this->radius2 = newRadius * newRadius;
}

const Vec3f& Sphere::getPosition(){
    return this->position;
}

const Vec3f& Sphere::getSurfaceColour(){
    return this->surfaceColour;
}

float Sphere::getRadius(){
    return this->radius;
}

bool Sphere::intersect(const Vec3f &rayorig, const Vec3f &raydir, float &t0, float &t1) const{

    Vec3f l = position - rayorig;
    float tca = l.dot(raydir);
    if (tca < 0) return false;
    float d2 = l.dot(l) - tca * tca;
    if (d2 > radius2) return false;
    float thc = sqrt(radius2 - d2);
    t0 = tca - thc;
    t1 = tca + thc;
    
    return true;
    
}