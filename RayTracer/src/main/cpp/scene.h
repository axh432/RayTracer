//
//  scene.h
//  RayTracer
//
//  Created by Alex Handby on 06/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__scene__
#define __RayTracer__scene__

#include <stdio.h>
#include <vector>
#include "Sphere.h"
#include "Light.h"

using std::vector;

class Scene {

private:
    vector<SpherePtr> spheres;
    vector<LightPtr> lights;
    
    unsigned imageWidth;
    unsigned imageHeight;
    unsigned imageFov;
    
public:

    vector<SpherePtr>& getSpheres();
    vector<LightPtr>& getLights();
    unsigned getImageWidth();
    unsigned getImageHeight();
    unsigned getImageFov();
    
    void setImageHeight(unsigned newImageHeight);
    void setImageWidth(unsigned newImageWidth);
    void setImageFov(unsigned newImageFov);
    void setSpheres(vector<SpherePtr>& newSpheres);
    void setLights(vector<LightPtr>& newLights);
    
};

#endif /* defined(__RayTracer__scene__) */
