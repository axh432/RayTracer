//
//  ImageWriter.h
//  RayTracer
//
//  Created by Alex Handby on 12/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__ImageWriter__
#define __RayTracer__ImageWriter__

#include <stdio.h>
#include <string>

#include "image.h"

using std::string;

class ImageWriter {
    
public:
    virtual void writeImage(const string& outputPath, const Image& image) = 0;

};

#endif /* defined(__RayTracer__ImageWriter__) */
