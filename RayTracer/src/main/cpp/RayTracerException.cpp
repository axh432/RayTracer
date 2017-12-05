//
//  RayTracerException.cpp
//  RayTracer
//
//  Created by Alex Handby on 13/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "RayTracerException.h"

RayTracerException::RayTracerException(std::string newMessage): message(std::move(newMessage)){}

std::string RayTracerException::getMessage(){ return this->message; }