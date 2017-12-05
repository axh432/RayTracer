//
//  raytracer.h
//  RayTracer
//
//  Created by Alex Handby on 06/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__raytracer__
#define __RayTracer__raytracer__

#include <stdio.h>
#include <array>
#include <memory>

#include "image.h"
#include "scene.h"

using std::unique_ptr;

class RayTracer {

private:
    
    Vec3f trace(const Vec3f& rayOrigin, const Vec3f& rayDir, Scene& scene);
    
    
public:
    
    unique_ptr<Image> render(Scene& scene);

};

#endif /* defined(__RayTracer__raytracer__) */
