//
//  FileLoader.h
//  RayTracer
//
//  Created by Alex Handby on 05/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__FileLoader__
#define __RayTracer__FileLoader__

#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>

#include "RayTracerException.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using std::vector;
using std::string;
using std::ifstream;

using namespace rapidjson;


class FileLoader{

public:
    Document loadJSONFile(const string& path);
    

};

#endif /* defined(__RayTracer__FileLoader__) */
