//
//  RayTracerException.h
//  RayTracer
//
//  Created by Alex Handby on 13/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__RayTracerException__
#define __RayTracer__RayTracerException__

#include <stdio.h>
#include <exception>
#include <string>

using std::exception;

struct RayTracerException : public exception {
    
private:
    std::string message;
    
public:
    RayTracerException(std::string newMessage);
    std::string getMessage();
    
};

#endif /* defined(__RayTracer__RayTracerException__) */
