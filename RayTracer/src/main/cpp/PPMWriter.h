//
//  PPMWirter.h
//  RayTracer
//
//  Created by Alex Handby on 10/09/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__PPMWriter__
#define __RayTracer__PPMWriter__

#include <stdio.h>
#include <fstream>
#include "ImageWriter.h"

using std::ofstream;

class PPMWriter : public ImageWriter {
    
public:
    void writeImage(const string& outputPath, const Image& image);
    
};

#endif /* defined(__RayTracer__PPMWriter__) */
