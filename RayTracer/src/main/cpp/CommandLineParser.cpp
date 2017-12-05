//
//  CommandLineParser.cpp
//  RayTracer
//
//  Created by Alex Handby on 05/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "CommandLineParser.h"


/*
 RayTracer Options.
 
 - ./raytracer
 - ./raytracer -f some/path/scene.txt
 - ./raytracer -o some/path/
 */

const string CommandLineParser::DEFAULT_SCENE_FILE_PATH = "come back to this";
const string CommandLineParser::DEFAULT_OUTPUT_FILE_PATH = "come back to this";


unique_ptr<CommandLineOptions> CommandLineParser::parse(int argc, const char * argv[]){
    
        int currentOption;
    
        char ** argv2 = (char **) argv;
    
        string sceneFilePath = DEFAULT_SCENE_FILE_PATH;
        string outputFilePath = DEFAULT_OUTPUT_FILE_PATH;
    
        opterr = 0;
    
        while ((currentOption = getopt (argc, argv2, "f:o:")) != -1){
        
            switch (currentOption)
            {
                case 'f':
                    sceneFilePath.copy(optarg, strlen(optarg));
                    break;
                
                case 'o':
                    outputFilePath.copy(optarg, strlen(optarg));
                    break;
                
                case '?':
                    if (optopt == 'f'){
                        throw RayTracerException(string("Commandline Option Error: Option -f requires an argument.\n"));
                    }
                    else if(optopt == 'o'){
                        throw RayTracerException(string("Commandline Option Error: Option -o requires an argument.\n"));
                    }
                    else if (isprint (optopt)){
                        string message = "Commandline Option Error: Unknown option '";
                        message += (char)optopt;
                        message += "'.\n";
                    
                        throw RayTracerException(message);
                    }
                    else{
                        string message = "Commandline Option Error: Unknown option character '";
                        message += (char)optopt;
                        message += "'.\n";
                    
                        throw RayTracerException(message);
                    }
                
            }
        }
    
    unique_ptr<CommandLineOptions> commandLineOptions(new CommandLineOptions(sceneFilePath,
                                                                    outputFilePath));
    
    return commandLineOptions;
    
}
