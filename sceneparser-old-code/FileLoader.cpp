//
//  FileLoader.cpp
//  RayTracer
//
//  Created by Alex Handby on 05/07/2017.
//  Copyright (c) 2017 Alex Handby. All rights reserved.
//

#include "FileLoader.h"

Document FileLoader::loadJSONFile(const string& path){
    
    string line;
    ifstream inputFileStream (path);
    
    vector<string> textFile;
    
    if (inputFileStream.is_open())
    {
        while ( getline (inputFileStream,line) )
        {
            textFile.push_back(line);
        }
        inputFileStream.close();
    }
    else {
        throw RayTracerException(std::string("File Load Error: Unable to open file: ") += path );
    }
    
    return textFile;

}