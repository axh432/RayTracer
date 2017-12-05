//
//  image.cpp
//  RayTracer
//
//  Created by Alex Handby on 06/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "image.h"

 unique_ptr<Image> Image::createImage(size_t h, size_t w){

    //no test for negative numbers because we are using unsigned integers
    if(w == 0){
        throw std::invalid_argument("width cannot be 0");
    }
    
    if(h == 0){
        throw std::invalid_argument("height cannot be 0");
    }
    
    return  unique_ptr<Image>(new Image(h, w));
    
}

Image::Image(size_t h, size_t w):
width(w),
height(h),
size(w * h),
data(new Vec3f[h * w])
{

}

Image::~Image(){
    delete[] data;
}

const Vec3f& Image::operator[](size_t index) const {
    
    //no test for negative numbers because size_t can't be negative.
    if(index > size -1){
        throw std::out_of_range("Requested index is not within the range of this Image");
    }
    
    return data[index];
    
}

Vec3f& Image::operator[](size_t index){
    
    //no test for negative numbers because size_t can't be negative.
    if(index > size -1){
        throw std::out_of_range("Requested index is not within the range of this Image");
    }
    
    return data[index];
    
}