//
//  CommandLineParser.h
//  RayTracer
//
//  Created by Alex Handby on 05/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#ifndef __RayTracer__CommandLineParser__
#define __RayTracer__CommandLineParser__

#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <memory>

#include "CommandLineOptions.h"
#include "RayTracerException.h"

using std::unique_ptr;

class CommandLineParser{

private:
    static const std::string DEFAULT_SCENE_FILE_PATH;
    static const std::string DEFAULT_OUTPUT_FILE_PATH;
    
    
public:
    unique_ptr<CommandLineOptions> parse(int argc, const char * argv[]);

};

#endif /* defined(__RayTracer__CommandLineParser__) */
