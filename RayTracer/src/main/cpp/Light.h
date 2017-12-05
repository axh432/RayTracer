//
//  Light.h
//  RayTracer
//
//  Created by Alex Handby on 10/09/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__Light__
#define __RayTracer__Light__

#include <stdio.h>
#include <memory>
#include "Vec3.h"

using std::shared_ptr;

class Light{

public:
    Light(){}
    
    void setPosition(const Vec3f& newPosition);
    void setEmissionColour(const Vec3f& newEmissionColour);
    
    const Vec3f& getPosition();
    const Vec3f& getEmissionColour();
    
private:
    Vec3f position, emissionColour;
    
};

typedef shared_ptr<Light> LightPtr;

#endif /* defined(__RayTracer__Light__) */
