//
//  raytracer.cpp
//  RayTracer
//
//  Created by Alex Handby on 06/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "raytracer.h"


Vec3f RayTracer::trace(const Vec3f& rayOrigin, const Vec3f& rayDir, Scene& scene){
    
    //find the closest intersection point with a sphere.
    vector<SpherePtr>& spheres = scene.getSpheres();
    vector<LightPtr>& lights = scene.getLights();

    float tnear = INFINITY;
    SpherePtr spherePtr = nullptr;
    
    // find intersection of this ray with the sphere in the scene
    for (unsigned i = 0; i < spheres.size(); ++i) {
        float t0 = INFINITY, t1 = INFINITY;
        if (spheres[i]->intersect(rayOrigin, rayDir, t0, t1)) {
            if (t0 < 0) t0 = t1;
            if (t0 < tnear) {
                tnear = t0;
                spherePtr = spheres[i];
            }
        }
    }
    
    //if we do not intersect then return background colour
    if(spherePtr == nullptr){
        return Pixel(0,0,0);
    }
    
    Vec3f surfaceColor = 0; // color of the ray/surfaceof the object intersected by the ray
    Vec3f pointOfIntersection = rayOrigin + rayDir * tnear; // point of intersection
    Vec3f normalOfIntersection = (pointOfIntersection - spherePtr->getPosition()).normalize(); // normal at the intersection point
    
    // If the normal and the view direction are not opposite to each other
    // reverse the normal direction. That also means we are inside the sphere so set
    // the inside bool to true. Finally reverse the sign of IdotN which we want
    // positive.
    
    float bias = 1e-4; // add some bias to the point from which we will be tracing -- why????
    bool inside = false;
    if (rayDir.dot(normalOfIntersection) > 0) normalOfIntersection = -normalOfIntersection, inside = true;

    // all the objects in the scene are diffuse, no need to raytrace any further
    for (unsigned i = 0; i < lights.size(); ++i) {
        
        Vec3f transmission = 1;
        Vec3f lightDirection = lights[i]->getPosition() - pointOfIntersection;
        lightDirection.normalize();
        
        for (unsigned j = 0; j < spheres.size(); ++j) {

                float t0, t1;
                if (spheres[j]->intersect(pointOfIntersection + normalOfIntersection * bias, lightDirection, t0, t1)) {
                    transmission = 0;
                    break;
                }
            
        }
        surfaceColor += spherePtr->getSurfaceColor() * transmission *
        std::max(float(0), normalOfIntersection.dot(lightDirection)) * lights[i]->getEmissionColor();
        
    }


    return surfaceColour;
}

unique_ptr<Image> RayTracer::render(Scene& scene){

    //get the image width and length
    int height = scene->getImageHeight();
    int width = scene->getImageWidth();
    float fov = scene->getImageFov();
    float aspectRatio = width / (float)height;
    
    unique_ptr<Image> image = Image::createImage(height, width);
    
    unsigned pixel = 0;
    
    float invWidth = 1 / float(width), invHeight = 1 / float(height);
    float angle = tan(M_PI * 0.5 * fov / 180.);
    
    for (unsigned y = 0; y < height; ++y) {
        for (unsigned x = 0; x < width; ++x, ++pixel) {
            float xx = (2 * ((x + 0.5) * invWidth) - 1) * angle * aspectratio;
            float yy = (1 - 2 * ((y + 0.5) * invHeight)) * angle;
            Vec3f raydir(xx, yy, -1);
            raydir.normalize();
            image[pixel] = trace(Vec3f(0), raydir, scene); //currently no recursion, and we have vectors but no ray.
        }
    }
    
    return image;
}