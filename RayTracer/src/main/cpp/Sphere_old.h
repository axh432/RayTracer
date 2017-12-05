//
//  Sphere.h
//  RayTracer
//
//  Created by Alex Handby on 12/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef RayTracer_Sphere_h
#define RayTracer_Sphere_h

#include "Vec3.h"

class Sphere
{
public:
    Vec3f center;                           /// position of the sphere
    float radius, radius2;                  /// sphere radius and radius^2
    Vec3f surfaceColor, emissionColor;      /// surface color and emission (light)
    //float transparency, reflection;         /// surface transparency and reflectivity
    Sphere(){}
    Sphere(
           const Vec3f &c,
           const float &r,
           const Vec3f &sc,
           const float &refl = 0,
           const float &transp = 0,
           const Vec3f &ec = 0) :
    center(c), radius(r), radius2(r * r), surfaceColor(sc), emissionColor(ec),
    transparency(transp), reflection(refl)
    { /* empty */ }
    //[comment]
    // Compute a ray-sphere intersection using the geometric solution
    //[/comment]
    bool intersect(const Vec3f &rayorig, const Vec3f &raydir, float &t0, float &t1) const
    {
        Vec3f l = center - rayorig;
        float tca = l.dot(raydir);
        if (tca < 0) return false;
        float d2 = l.dot(l) - tca * tca;
        if (d2 > radius2) return false;
        float thc = sqrt(radius2 - d2);
        t0 = tca - thc;
        t1 = tca + thc;
        
        return true;
    }
    
    Vec3f& getPosition(){
        return center;
    }
};

#endif
