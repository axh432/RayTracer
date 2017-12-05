//
//  Sphere.h
//  RayTracer
//
//  Created by Alex Handby on 10/09/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__Sphere__
#define __RayTracer__Sphere__

#include <stdio.h>
#include <math.h>
#include <memory>
#include "Vec3.h"

using std::shared_ptr;


class Sphere {

public:
    Sphere(){}
    
    void setPosition(const Vec3f& newPosition);
    void setSurfaceColour(const Vec3f& newSurfaceColour);
    void setRadius(const float newRadius);
    
    const Vec3f& getPosition();                                   //is this bad practice to return a mutable reference?
    const Vec3f& getSurfaceColour();
    float getRadius();
    bool intersect(const Vec3f &rayorig, const Vec3f &raydir, float &t0, float &t1) const;
    
private:
    Vec3f position, surfaceColour;                          /// position of the sphere
    float radius, radius2;                                  /// sphere radius and radius^2

};

typedef shared_ptr<Sphere> SpherePtr;

#endif /* defined(__RayTracer__Sphere__) */
