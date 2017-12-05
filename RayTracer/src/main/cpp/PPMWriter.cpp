//
//  PPMWirter.cpp
//  RayTracer
//
//  Created by Alex Handby on 10/09/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "PPMWriter.h"

void PPMWriter::writeImage(const string& outputPath, const Image& image){
    
    size_t width = image.getWidth();
    size_t height = image.getHeight();
    
    // Save result to a PPM image (keep these flags if you compile under Windows)
    ofstream ofs("./untitled.ppm", std::ios::out | std::ios::binary);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (unsigned i = 0; i < width * height; ++i) {
        ofs << (unsigned char)(std::min(float(1), image[i].getX()) * 255) <<
        (unsigned char)(std::min(float(1), image[i].getY()) * 255) <<
        (unsigned char)(std::min(float(1), image[i].getZ()) * 255);
    }
    ofs.close();

}