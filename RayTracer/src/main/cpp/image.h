//
//  image.h
//  RayTracer
//
//  Created by Alex Handby on 06/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__image__
#define __RayTracer__image__

#include <stdio.h>
#include <stdexcept>
#include <memory>
#include "vec3.h"

using std::unique_ptr;

class Image {
    
private:
    size_t height;
    size_t width;
    size_t size;
    Vec3f * data;

    Image(size_t h, size_t w);
    
public:
    static unique_ptr<Image> createImage(size_t h, size_t w);
    ~Image();
    Vec3f& operator[](size_t index);
    const Vec3f& operator[](size_t index) const;
    const size_t getHeight() const { return height; }
    const size_t getWidth() const { return width; }

};

#endif /* defined(__RayTracer__image__) */
