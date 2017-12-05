//
//  SceneBuilder.h
//  RayTracer
//
//  Created by Alex Handby on 09/09/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__SceneBuilder__
#define __RayTracer__SceneBuilder__

#include <stdio.h>
#include <memory>

#include "scene.h"
#include "document.h"
#include "RayTracerException.h"

using namespace rapidjson;
using std::unique_ptr;

class SceneBuilder{

    public:
        unique_ptr<Scene> buildSceneFromJSON(Document& document);
        
    private:
        void       populateImageSettings(Scene& scene, const Value& imageSettings);
        SpherePtr buildSphere(const Value& sphere);
        LightPtr  buildLight(const Value& light);
        void      populateSpheres(Scene& scene, const Value& spheres);
        void      populateLights(Scene& scene, const Value& lights);

};


#endif /* defined(__RayTracer__SceneBuilder__) */
