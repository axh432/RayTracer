//
//  TGAWriter.h
//  RayTracer
//
//  Created by Alex Handby on 12/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__TGAWriter__
#define __RayTracer__TGAWriter__

#include <stdio.h>
#include "ImageWriter.h"

class TGAWriter : public ImageWriter {

public:
    void writeImage(const string& outputPath, const Image& image);

};

#endif /* defined(__RayTracer__TGAWriter__) */
